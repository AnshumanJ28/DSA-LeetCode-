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
    void reorderList(ListNode* head) {
    if (head == nullptr) return;
    
    stack<ListNode*> st;
    int n = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        st.push(curr);
        n++;
        curr = curr->next;
    }
    
    ListNode* front = head;
    
    for (int i = 0; i < n / 2; i++) {
        ListNode* nextFront = front->next;
        ListNode* backNode = st.top();
        st.pop();
        
        front->next = backNode;
        backNode->next = nextFront;
        front = nextFront;
    }
    
    front->next = nullptr;
}
};