/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

#include <iostream>
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

void MoveUp(ListNode *&node) {
    ListNode *temp = node;
    node = node->next;
    delete temp;
}

void MergeToEnd(ListNode **head, int data) {
    ListNode *new_node = static_cast<struct ListNode *>(malloc(sizeof(struct ListNode)));
    ListNode *last = *head;
    new_node->val = data;
    new_node->next = nullptr;
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

void PrintList(ListNode *n) {
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

/*class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 && !list2)
            return nullptr;
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *mergedList = new ListNode();

        while (list1 || list2) {
            if (!list1) {
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list2);
                continue;
            }
            if (!list2) {
                MergeToEnd(&mergedList, list1->val);
                MoveUp(list1);
                continue;
            }
            if (list1->val == list2->val) {
                MergeToEnd(&mergedList, list1->val);
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list1);
                MoveUp(list2);
                continue;
            }
            if (list1->val < list2->val) {
                MergeToEnd(&mergedList, list1->val);
                MoveUp(list1);
                continue;
            }
            if (list1->val > list2->val) {
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list2);
            }
        }
        ListNode *temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
        return mergedList;
    }
};*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 || !list2) {
            if (!list1 && !list2)
                return nullptr;
            if (!list2)
                return list1;
            return list2;
        }

        ListNode *mergedList = new ListNode();

        while (list1 || list2) {
            if (!list1) {
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list2);
                continue;
            }
            if (!list2) {
                MergeToEnd(&mergedList, list1->val);
                MoveUp(list1);
                continue;
            }
            if (list1->val == list2->val) {
                MergeToEnd(&mergedList, list1->val);
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list1);
                MoveUp(list2);
                continue;
            }
            if (list1->val < list2->val) {
                MergeToEnd(&mergedList, list1->val);
                MoveUp(list1);
                continue;
            }
            if (list1->val > list2->val) {
                MergeToEnd(&mergedList, list2->val);
                MoveUp(list2);
            }
        }
        ListNode *temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
        return mergedList;
    }
};


int main() {
    auto *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto *list2 = new ListNode(1, new ListNode(2));
    ListNode *list3 = nullptr;
    PrintList(list1);
    PrintList(list2);

    Solution test;
    ListNode *result = test.mergeTwoLists(list1, list2);
    cout << "result is ";
    PrintList(result);
    delete list1;
    delete list2;
    delete list3;
    delete result;
    return 0;
}
