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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        if(head->next == nullptr || head->next->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //REVERSE THE SECOND HALF
        ListNode* second = slow->next; //head of the second part
        slow->next = nullptr; //it is supposed to be pointing to null in the merged case so do it here
        ListNode* prev = slow->next; //last reversed element
        ListNode* temp; //stores the element that is the moving head of the unreversed second part
        while(second){
            temp = second->next; //temp moves to next position of head
            second->next = prev; //head points to the last position seen 
            prev = second; // last seen position becomes equal to head
            second = temp; //move head(second) to start of unreserved second part, which is temp
        }
        //MERGE THE TWO HALFS
        ListNode* first = head;
        second = prev; // head of the reversed second part is the last that you had seen
        ListNode* t1;
        ListNode* t2; // you had earlier written ListNode* t1, t2
                      // that created t1 as a ptr but t2 as an object
                      // thus if you had to declare both of them in one line 
                      // you should have written ListNode *t1, *t2
                      // cause the * gives the variable the meaning that it is a ptr
        while (second){
            t1 = first->next;
            t2 = second->next;
            first->next = second;
            second->next = t1;
            second = t2;
            first = t1;
        }
    }
};
