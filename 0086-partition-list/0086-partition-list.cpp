/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode smallDummy(0), bigDummy(0);
    ListNode* smallTail = &smallDummy;
    ListNode* bigTail = &bigDummy;
    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val < x) {
            smallTail->next = curr;
            smallTail = curr;
        } else {
            bigTail->next = curr;
            bigTail = curr;
        }
        curr = curr->next;
    }

    smallTail->next = bigDummy.next;
    bigTail->next = nullptr;

    return smallDummy.next;
}
};