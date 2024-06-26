#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        
        ListNode* first = head;
        ListNode* second = head;

        if (first->next == nullptr) {
            if (first->val == val) {
                return nullptr;
            }
            return head;
        }
        second = first->next;

        if (first->val == val) {
            while (true) {
                if (head->next == nullptr) {
                    if (head->val != val) {
                        break;
                    }
                    return nullptr;
                }
                head = head->next;
                if (head->val != val) {
                    break;
                }
            }
        }
            
        while (first->next->next != nullptr) {
            if (first->next->val == val) {
                first->next = first->next->next;
            } else {
                first = first->next;
            }
        }
        if (first->next->val == val)
            first->next = nullptr;
        return head;
    }
};

int main() {
    int val, n;
    std::cout << "Enter the value to remove: ";
    std::cin >> val;
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    std::cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ListNode* newNode = new ListNode(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Solution solution;
    ListNode* result = solution.removeElements(head, val);
    
    std::cout << "List after removal: ";
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}
