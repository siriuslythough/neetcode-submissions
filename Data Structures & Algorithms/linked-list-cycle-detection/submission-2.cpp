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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode dummy(0); //dummy node with any value and nullptr as next (dummy IS A WHOLE NODE)
        ListNode* a = &dummy; //a HOLDS THE EXACT ADDRESS OF dummy NOW
                              //SO IF A CAUSES A CHANGE OF ADDRESS, THEN DUMMY ALSO SUFFERS A CHANGE OF ADDRESS 

        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<t2->val){
                a->next = t1; //HERE THE NEXT POINTER FROM a'S LOCATION, AND HENCE dummy's LOCATION ALSO
                              //POINTS TO THE FIRST ELEMENT
                t1=t1->next;
            }
            else if(t1->val==t2->val){
                a->next = t1;
                t1=t1->next; // only t1 is updated to move cause it has been seen by a, t2 wont be updated
            }else{
                a->next = t2;
                t2=t2->next;

            }
            a = a->next; //THE FIRST TIME THIS IS DONE, a GOES TO A NEW LOCATION, WHERE dummy IS ALSO
                              //POINTED TO. HENCE dummy POINTS TO FIRST NODE OF ANSWER LIST
        }
        if(t1!=nullptr){
            a->next = t1;
        }else{
            a->next = t2;
        }
        return dummy.next; //a had been holding dummy at the start, and dummy pointed 
    }
};
