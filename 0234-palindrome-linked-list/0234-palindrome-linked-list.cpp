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
    ListNode* reverseNodes(ListNode* head){
        if(!head||!head->next)return head;
        ListNode* cur=head;     ListNode* prev=nullptr;
        while(cur){
            ListNode*nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
          if((head==nullptr)||(head->next==nullptr))return 1;
        
        ListNode*fast=head; ListNode*slow=head;
        
        while(fast&&fast->next){
            slow=slow->next;    fast=fast->next->next;
        }

        ListNode* temp1=head;     ListNode* temp2=reverseNodes(slow);

        while(temp2){
            if(temp1->val!=temp2->val){
                return 0;
            }
            temp1=temp1->next;     temp2=temp2->next;
        }

        return true;
    }
};

