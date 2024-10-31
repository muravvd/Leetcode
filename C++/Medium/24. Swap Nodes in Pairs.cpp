/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)
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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev;
        ListNode *start = head->next;

        while (head && head->next) {
            ListNode *first = head;
            ListNode *second = head->next;
            first->next = second->next;
            second->next = first;
            if (prev)
                prev->next = second;
            prev = first;
            head = first->next;
        }

        return start;
    }
};

void deallocList(ListNode* head) {
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution test;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    printList(test.swapPairs(head));
    deallocList(head);
    return 0;
}
