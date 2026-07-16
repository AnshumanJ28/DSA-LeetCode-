/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;

        dfs(head);
        return head;
    }

    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;

            if (curr->child != nullptr) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if (nextNode != nullptr) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
            } else {
                last = curr;
            }

            curr = nextNode;
        }

        return last;
    }
};