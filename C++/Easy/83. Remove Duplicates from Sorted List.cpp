/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

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

void MoveUp(ListNode *&node) {
    ListNode *temp = node;
    node = node->next;
    delete temp;
}

void MergeToEnd(ListNode **head, int data) {
    ListNode *new_node = new ListNode(data);
    new_node->next = nullptr;
    ListNode *last = *head;
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

class Solution {
    // 0ms without delete | 8ms with delete
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        vector<int> uniques;
        uniques.push_back(head->val);
        ListNode *temp = head;
        temp = temp->next;
        while (temp) {
            if (uniques.back() != temp->val)
                uniques.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        ListNode *cut = nullptr;
        while (i < uniques.size()) {
            temp->val = uniques[i];
            cut = temp;
            temp = temp->next;
            i++;
        }
        cut->next = nullptr;
        delete temp;
        return head;
    }
};

/*class Solution {                // 7ms
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *res = new ListNode(head->val, nullptr);
        int last = head->val;
        MoveUp(head);
        while (head) {
            //cout << head->val << " | " << res->val << " " << endl;
            if (head->val == last) {
                //cout << "equal" << endl;
                MoveUp(head);
                continue;
            }
            MergeToEnd(&res, head->val);
            last = head->val;
            MoveUp(head);
        }
        return res;
    }
};*/

void PrintList(ListNode *n) {
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    auto *list1 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(3))))))));
    PrintList(list1);
    Solution test;
    ListNode *result = test.deleteDuplicates(list1);
    cout << "result is ";
    PrintList(result);
    delete list1;
    delete result;
    return 0;
}
