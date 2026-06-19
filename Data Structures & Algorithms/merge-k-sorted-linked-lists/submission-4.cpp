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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        //the minheap approach: store a whole column of all lists in the minheap. store a pair of value and address.
        //the minheap is the priority queue with {vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>} passed as arguments
        //and when the minimum is found and pointed to, remove that element from pririty queue and add the next node value and address
        priority_queue<pair<int, ListNode*>, 
                       vector<pair<int, ListNode*>>, 
                       greater<pair<int, ListNode*>>
                      > pq;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        for(int i = 0; i<lists.size(); i++){
            if (lists[i]) pq.push({lists[i]->val, lists[i]}); //store all heads
        }
        while(!pq.empty()){
            pair<int, ListNode*> pr = pq.top(); //store the pair from minheap into a pair 
            pq.pop(); //remove that from minheap
            if(pr.second->next) pq.push({pr.second->next->val, pr.second->next});
            temp->next = pr.second;
            temp = temp->next;
        }
        return dummy.next;
    }
};
