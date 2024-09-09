struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        pair<Node*,Node*>p;
        
        if(head==NULL || head->next == head || head->next==NULL){
            return {head,head};
        }
        Node* fast=head;
        Node* slow=head;
        
        while(fast->next!=head && fast->next->next!=head){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast->next->next==head){
            fast=fast->next;
        }
        
        Node* second= slow->next;
        slow->next=head;
        fast->next=second;
        
        p.first=head;
        p.second=second;
        
        return p;
        
    }
};
