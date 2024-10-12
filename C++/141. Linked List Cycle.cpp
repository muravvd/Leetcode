/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

/*class Solution {              // 6ms   10mb
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        if (head->val == 80085)         // silly solution that wouldn't necessarily work if there's a list with no cycle but a 80085 value
            return true;
        head->val = 80085;
        return hasCycle(head->next);
    }
};*/

class Solution {            // 4ms   10mb
public:
    bool hasCycle(ListNode *head) {         // Floyd’s Cycle Finding Algorithm
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

void breakCycle(ListNode* head) {
    if (!head || !head->next) return;

    ListNode *slow = head, *fast = head;

    // Detect the cycle using Floyd’s algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected, now break it
            slow = head;
            ListNode *prev = nullptr;
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            // Break the cycle by making the previous node point to nullptr
            prev->next = nullptr;
            return;
        }
    }
}

// Helper function to delete the list safely
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution test;
    auto *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;
    cout << test.hasCycle(head);
    breakCycle(head);
    deleteList(head);
    return 0;
};
