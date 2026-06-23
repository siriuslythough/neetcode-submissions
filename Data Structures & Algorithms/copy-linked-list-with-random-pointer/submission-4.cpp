/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        //inserting copy nodes
        Node* temp = head;
        while(temp!=nullptr){
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        //connecting random pointers
        while(temp!=nullptr){
            temp->next->random = (temp->random!=nullptr)?temp->random->next:nullptr;
            temp = temp->next->next;
        }
        temp = head;
        //connext next pointers and detach from og list
        Node dummy(0);
        Node* res = &dummy;
        while(temp!=nullptr ){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next; //because temp was still pointing to previous res, so could use temp->next
            temp = temp->next;
        }
        return dummy.next;
    }
};
