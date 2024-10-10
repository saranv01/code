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
    ListNode* getKthNode(ListNode* temp,int k){
        k--;
        while(k--&&temp){
            temp=temp->next;
        }
        return temp;
    }
    ListNode*reverseNode(ListNode* head){
        if(!head||!head->next)return head;
        ListNode* current=head;
        ListNode* previous=nullptr;
        while(current){
            ListNode* nextNode = current->next;
            current->next=previous;
            previous=current;
            current=nextNode;
        }
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=1;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        temp=head;
        ListNode* previousLast=nullptr;
        while(temp){
            ListNode* kthNode=getKthNode(temp,k);
            
            if(!kthNode){
                if(previousLast){
                    previousLast->next=temp;
                }
                break;
            }

            ListNode* kthNextNode= kthNode->next;

            kthNode->next=nullptr;
        
           ListNode* reversedNodes = reverseNode(temp);
           if(temp==head) head=reversedNodes;
           else
           previousLast->next=reversedNodes;
           previousLast=temp;
           temp=kthNextNode;
        }
        return head;
    }
};