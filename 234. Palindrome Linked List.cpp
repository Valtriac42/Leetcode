#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        int A[100000];
        int i = 0;
        while (head->next != NULL) {
            A[i] = head->val;
            head = head->next;
            i++;
        }
        A[i] = head->val;

        int j = i;
        for (i = 0; i < j;) {
            if (A[i] == A[j]) {
                i = i + 1;
                j = j - 1;
            } else
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    ListNode* head = NULL;
    ListNode* temp;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (head == NULL) {
            head = new ListNode(val);
            temp = head;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    bool result = sol.isPalindrome(head);
    if (result)
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is not a palindrome.\n";

    return 0;
}
