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
    int maxi=INT_MIN;

    ListNode* reverseAndRemove(ListNode* head){
        while(head->next==nullptr||head==nullptr){
            if(head->next==nullptr)
            maxi=head->val;
            cout<<maxi<<" ";
            return head;
        }
        ListNode* temp=reverseAndRemove(head->next);
        maxi=max(head->val,maxi);
        if(maxi<=head->val){
        head->next=temp;
        return head;
        }
        cout<<maxi<<" ";
        return temp;
    }
public:
    ListNode* removeNodes(ListNode* head) {

        return reverseAndRemove(head);
    }
};