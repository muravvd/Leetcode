/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {    // O(n) - 0ms
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*
cn  n p
    1 2 3 4 5       2->next=p=1
      c
      n p
    1 2 3 4 5
        c
    - - - - -

    1 2 3 4 5
            n c
*/

void deleteList(ListNode* head) {
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";  // Print current node value
        current = current->next;      // Move to the next node
    }
    cout << endl;
}

int main() {
    Solution test;
    const auto list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    printList(test.reverseList(list));
    deleteList(list);
    return 0;
};
