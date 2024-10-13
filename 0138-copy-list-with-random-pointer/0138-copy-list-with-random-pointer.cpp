/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=nullptr){
            Node* duplicateNode = new Node(temp->val);
            duplicateNode->next =  temp->next;
            temp->next=duplicateNode;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummyNode=new Node(-1);
        Node*t2= dummyNode;
        while(temp){
            Node* temp2=temp->next;
            if(temp->random)
            temp2->random=temp->random->next;
            else temp2->random=nullptr;
       
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            t2->next=temp->next;
            t2=t2->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};