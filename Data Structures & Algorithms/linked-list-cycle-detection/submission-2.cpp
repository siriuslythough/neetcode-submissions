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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        ListNode* temp = head;
        while(temp!=nullptr){
            if(s.count(temp)) return true;
            s.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
