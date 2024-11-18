/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    explicit ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {    // 0ms  15mb
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode start(0, head);
        ListNode *prev = &start;

        while (head) {
            if (head->next && head->val == head->next->val) {
                int duplicate = head->val;
                while (head && head->val == duplicate) {
                    ListNode *temp = head;
                    head = head->next;
                    delete temp;
                }
                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return start.next;
    }
};

void PrintList(ListNode *n) {
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

ListNode *createLinkedList(const vector<int> &arr) {
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 4, 4, 5, 5};
    ListNode *list1 = createLinkedList(arr);
    PrintList(list1);
    Solution test;
    ListNode *result = test.deleteDuplicates(list1);
    cout << "result is ";
    PrintList(result);
    delete list1;
    delete result;
    return 0;
}
