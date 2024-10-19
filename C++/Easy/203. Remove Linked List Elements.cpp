/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list
that has Node.val == val, and return the new head.
*/

#include <iostream>
#include <vector>
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
    ListNode *removeElements(ListNode *head, int val) {
        if (!head)
            return nullptr;
        ListNode *temp, *start = head;
        while (start->val == val) {
            if (!start->next)
                return nullptr;
            temp = start;
            start = start->next;
            delete temp;
        }
        head = start;
        while (head != nullptr && head->next != nullptr) {
            if (head->next->val == val) {
                temp = head->next;
                head->next = head->next->next;
                delete temp;
            } else {
                head = head->next;
            }
        }
        return start;
    }
};

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void deleteList(ListNode *head) {
    ListNode *curr = head;
    ListNode *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void printList(ListNode *head) {
    ListNode *current = head;
    cout << "list: ";
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution test;
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode* list = createList(values);
    printList(list);
    printList(test.removeElements(list, 6));
    values = {6, 6, 6, 6, 6};
    ListNode* list2 = createList(values);
    printList(list2);
    printList(test.removeElements(list2, 6));
    deleteList(list);
    deleteList(list2);
    printList(test.removeElements(nullptr, 6));
    return 0;
}
