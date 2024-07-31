#include <iostream>
using namespace std;

// ListNode definition
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// Solution class definition
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* hola = list1;
        ListNode* hola2 = list1;
        int i = 0;
        for(i = 1; i < a; i++) {
            hola = hola->next;
            hola2 = hola2->next;
        }
        int c = b - a;
        for(i = 0; i <= c; i++) {
            hola2 = hola2->next;
        }
        hola2 = hola2->next;
        hola->next = list2;
        ListNode* temp = list1;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = hola2;
        return list1;
    }
};

// Main function
int main() {
    // Input values
    int n, m, a, b;
    cout << "Enter the number of elements in list1: ";
    cin >> n;
    cout << "Enter the number of elements in list2: ";
    cin >> m;
    cout << "Enter the range (a, b) to merge list2 into list1: ";
    cin >> a >> b;

    // Constructing list1
    cout << "Enter elements of list1 separated by spaces: ";
    ListNode *list1 = nullptr, *list2 = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (list1 == nullptr) {
            list1 = newNode;
        } else {
            ListNode* temp = list1;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Constructing list2
    cout << "Enter elements of list2 separated by spaces: ";
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (list2 == nullptr) {
            list2 = newNode;
        } else {
            ListNode* temp = list2;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Merge operation
    Solution solution;
    ListNode* result = solution.mergeInBetween(list1, a, b, list2);

    // Output the merged list
    cout << "Merged list: ";
    ListNode* temp = result;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deallocate memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    while (list2 != nullptr) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
