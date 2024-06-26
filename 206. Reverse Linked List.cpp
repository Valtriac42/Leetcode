#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* hola = head;
        ListNode* hola2 = head;
        int A[10000];
        int i = 0;

        while (hola != nullptr) {
            A[i] = hola->val;
            hola = hola->next;
            i++;
        }

        int a = i;

        while (a != 0) {
            hola2->val = A[a - 1];
            hola2 = hola2->next;
            a--;
        }
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = sol.reverseList(head);
    std::cout << "Reversed list: ";
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    // deallocate memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
