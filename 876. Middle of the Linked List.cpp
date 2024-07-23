#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* hola = head;
        ListNode* hola2 = head;
        int count = 0;
        while (hola->next != NULL) {
            hola = hola->next;
            count = count + 1;
        }
        int i = 0;
        if (count % 2 != 0)
            count = (count / 2) + 1;
        else
            count = count / 2;
        for (i = 0; i < count; i++) {
            hola2 = hola2->next;
        }
        return hola2;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    ListNode* middle = sol.middleNode(head);

    if (middle != nullptr)
        cout << "Middle node value: " << middle->val << endl;
    else
        cout << "List is empty." << endl;

    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
