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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //let me try the merge two at a time approach
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        ListNode* combine = mergetwo(lists[0], lists[1]);
        for(int i = 2; i<lists.size(); i++){
            combine = mergetwo(lists[i], combine);
        }
        return combine;
    }
private: 
    ListNode* mergetwo(ListNode* l1, ListNode* l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode dummy(0);
        ListNode* a = &dummy;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<t2->val){
                a->next = t1;
                t1 = t1->next;
            }else{
                a->next = t2;
                t2 = t2->next;
            }
            a = a->next;
        }
        if(t1!=nullptr){
            a->next = t1;
        }else{
            a->next = t2;
        }
        return dummy.next;
    }
};
