/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

/*class Solution {            // 555ms
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != NULL) {
            ListNode *temp = headB;
            while (headB != NULL) {
                if (headA == headB)
                    return headA;
                headB = headB->next;
            }
            headA = headA->next;
            headB = temp;
        }
        return NULL;
    }
};*/

class Solution {                // 20ms
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int LenA=0, LenB=0;
        auto node = headA;
        while (node) {
            LenA++;
            node = node->next;
        }
        node = headB;
        while (node) {
            LenB++;
            node = node->next;
        }
        while (LenA > LenB) {
            LenA--;
            headA = headA->next;
        }
        while (LenB > LenA) {
            LenB--;
            headB = headB->next;
        }
        while (headA) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// Helper function to delete the list safely
void deleteList(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution test;
    auto intersection = new ListNode(3);
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = intersection;
    auto head2 = new ListNode(2);
    head2->next = intersection;
    auto *head3 = test.getIntersectionNode(head, head2);
    if (head3 != NULL)
        cout << head3->val << endl;
    else
        cout << "Not Found" << endl;
    deleteList(head);
    deleteList(head2);
    deleteList(head3);
    return 0;
};
