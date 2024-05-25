#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* pointer = head;
        ListNode* hola = head;
        if (head == NULL)
            return nullptr;

        if (head->next == NULL)
        {
            return nullptr;
        }
        int a;
        int loc = 0;
        hola = hola->next;

        while (hola->next != NULL)
        {
            for (a = 800; a >= 0; a--)
            {
                if (hola->next == NULL)
                {
                    return nullptr;
                }
                if (hola->next == pointer)
                {
                    return pointer;
                }
                hola = hola->next;
            }
            pointer = pointer->next;
        }
        return nullptr;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    int val;
    int n;

    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            node = head;
        } else {
            node->next = newNode;
            node = newNode;
        }
    }

    // Link last node to create a cycle
    node->next = head->next;

    ListNode* cycleStart = solution.detectCycle(head);
    if (cycleStart)
        std::cout << "Cycle detected, starts at node with value: " << cycleStart->val << std::endl;
    else
        std::cout << "No cycle detected." << std::endl;

    // Free allocated memory
    ListNode* curr = head;
    ListNode* temp;
    while (curr != nullptr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }

    return 0;
}
