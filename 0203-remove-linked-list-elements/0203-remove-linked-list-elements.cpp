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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev=nullptr;
        ListNode* nxt=nullptr;
        ListNode* temp=head;
        while(temp){
            nxt=temp->next;
            //deleting node at the begining
            if(prev==nullptr&&temp->val==val){
                ListNode*t1=head;
                head=head->next;
                temp=head;
                delete(t1);
                continue;
            }
            //deleting node at the mid or end
            if(temp->val==val){
                ListNode*t1=temp;
                prev->next=nxt;
                temp=prev;
                delete(t1);
            }
            prev=temp;
            temp=nxt;

        }
        return head;
    }
};