#include<bits/stdc++.h>
using namespace std;

class Node{
      public:
      int data;
      Node* next;

      Node(int data){
            this->data=data;
            next=NULL;
      }
};

class LinkedList{

      public:
      Node* head=NULL;
      Node* tail=NULL;
      int size=0;
      
      void pushBack(int data){
      
            if(head==NULL and tail==NULL){
                  head=new Node(data);
                  tail=head;
                  size++;
                  return ;
            }
            Node* n=new Node(data);
            tail->next=n;
            tail=n;
            size++;
      }

      // Node* returnHead(){
      //        return head;
      // }

      Node* mergeTwoLists(Node* l1, Node* l2) {
       if(l1==NULL) return l2;
       if(l2==NULL) return l1;
        
       Node* finalHead = NULL;   /// head of the list to return
        
       if(l1->data < l2->data){
           finalHead = l1;
           l1 = l1->next;
       }else{
           finalHead = l2;
           l2 = l2->next;
       }
        Node *p = finalHead;   /// pointer to form new list
        
        while(l1 && l2){
            if(l1->data < l2->data){
                p->next = l1;   /// inseting at tail
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1){
            p->next = l1;
        }else{
            p->next = l2;
        }
        return finalHead;
    }


      Node* mergeSort(Node* head1){
            if((head==NULL and tail==NULL) || head->next==NULL) return head1;

            // Node* mid;
            // Node* left=head1;
            // Node* right;

            Node* slow=head1;
            Node* fast=head1->next;
            while(fast and fast->next){
                  slow=slow->next;
                  fast=fast->next->next;
            }

            Node* n=slow->next;
            slow->next=NULL;
            Node* left=mergeSort(head1);
            Node* right=mergeSort(n);
            head1=mergeTwoLists(left,right);
            
            return head1;
            // head=head1;
      }

      void display(){
            if(head==NULL and tail==NULL) return;
            Node* ptr=head;
            while(ptr!=NULL){
                  cout<<ptr->data<<"->"; 
                  ptr=ptr->next;
            }
            cout<<"NULL";
            cout<<endl;
      
      }
};

int main(){
      LinkedList ll1;
      // LinkedList ll2;
      int m;
      cin>>m;

      while(m--){
            int x;
            cin>>x;
            ll1.pushBack(x);
      }

      ll1.display();

      Node* head=ll1.mergeSort(ll1.head);
      // cout<<ll1.head->data;
      // ll1.display();
      // cout<<head->data;
      // cout<<ll1.head->data;
          // Node* h=ll1.mergeSort(ll1.head);
      // cout<<h->next->data;


}