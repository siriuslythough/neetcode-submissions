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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        while(curr!=nullptr){
            nxt=curr->next; //nxt is having location of upcoming list from curr and its connections
            curr->next = prev; //here, assign next for curr at prev
            prev = curr; //move prev to curr
            curr = nxt; //move curr to nxt
        }
        return prev; //when curr will be at nullptr, prev will be head of the reversed LL
    }
};
