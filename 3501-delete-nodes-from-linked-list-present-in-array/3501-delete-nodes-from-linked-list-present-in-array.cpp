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

ListNode* deleteNode(set<int> numSet, ListNode*head){
    ListNode* temp=head;
    ListNode* prev=nullptr;
    ListNode* nxt=nullptr;
    int i=0;
    while(temp){
            nxt=temp->next;
            if(numSet.find(temp->val)!=numSet.end()){

            //node at the begining
            if(i==0){
                head=head->next;
                temp=temp->next;
                continue;
            }
            //node at the middle if deleted
            prev->next=nxt;
            temp=nxt; 
            continue;           
        }   
        prev=temp;
        temp=nxt;
       i++;
    }
    return head;
}
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res = nullptr;
        set<int> numSet(nums.begin(),nums.end());
        return deleteNode(numSet,head);
    }
};