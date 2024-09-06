/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findMatch(ListNode* head){
        ListNode* t=head;
        ListNode* h=head;
        while(h&&h->next){

            t=t->next;
            h=h->next->next;
            if(t==h){
                break;
            }
        }
        if(!(h&&h->next)) return NULL;
        while(head!=t){
            head=head->next;
            t=t->next;
        }
        return head;
    }
    ListNode *detectCycle(ListNode *head) {
    
        return findMatch(head);
    }
};