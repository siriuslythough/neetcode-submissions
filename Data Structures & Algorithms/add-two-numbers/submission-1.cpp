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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* ans = &dummy;

        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;
            if(l1!=nullptr){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                sum +=l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            ans->next = new ListNode(sum%10);
            ans = ans->next;
            
        }
        return dummy.next;
    }
private:
    ListNode* reversell(ListNode* head){
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(temp){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
};
