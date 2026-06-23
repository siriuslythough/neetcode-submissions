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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(head==nullptr || n>length(head)) return nullptr;
        if(n==len){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        int pos = 0;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(pos<(len-n)){
            pos++;
            prev = temp;
            temp = temp->next;
        }
        prev->next=temp->next;
        delete temp; //delete keyword is better to use instead of free()
        return head;
    }
private:
    int length(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
};
