#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val = 0, ListNode* next = nullptr) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* temp = head;
        int i = 1;
        if (head == NULL) {
            return head;
        }
        while (start->next != NULL) {
            if (left == 1) {
                break;
            }
            start = start->next;
            end = end->next;
            i++;
            if (i == left) {
                break;
            }
        }

        int A[10000];
        left = right - left;
        for (i = 0; i <= left; i++) {
            A[i] = start->val;
            start = start->next;
            cout << A[i];
        }

        for (i = 0; left >= i; left--) {
            end->val = A[left];
            end = end->next;
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    int left, right;
    cout << "Enter left and right indices: ";
    cin >> left >> right;
    solution.reverseBetween(head, left, right);
    return 0;
}
