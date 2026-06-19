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
        priority_queue<pair<int, ListNode*>, 
                       vector<pair<int, ListNode*>>, 
                       greater<pair<int, ListNode*>>
        > pq;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        for(int i = 0; i<lists.size(); i++){
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        while(!pq.empty()){
            pair<int, ListNode*> pr = pq.top();
            pq.pop();
            temp->next = pr.second;
            if(pr.second->next) pq.push({pr.second->next->val, pr.second->next});
            temp = temp->next;
        }
        return dummy.next;
    }
};
