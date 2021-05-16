//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

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
    stack<Node *> st;
    void flattenList(Node* head) {
        if (head == NULL) return;
        
        if (head->next == NULL && !st.empty()) {
            head->next = st.top();
            head->next->prev = head;
            st.pop();
        }
        
        if (head->child != NULL) {
            if (head->next != NULL) st.push(head->next);
            head->next = head->child;
            head->next->prev = head;
            head->child = NULL;
        }
        flattenList(head->next);
        
    }
    Node* flatten(Node* head) {
        flattenList(head);
        return head;
    }
};