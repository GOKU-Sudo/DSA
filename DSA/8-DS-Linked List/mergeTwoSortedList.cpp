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
      Node* head=NULL;
      Node* tail=NULL;

      public:
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

      void mergeSortedList(LinkedList L1,LinkedList L2){
            Node* ptr1=L1.head;
            Node* ptr2=L2.head;

            while(ptr1!=NULL and ptr2!=NULL){
                  if(ptr1->data<ptr2->data){
                        pushBack(ptr1->data);
                        ptr1=ptr1->next;
                  }
                  else{
                        pushBack(ptr2->data);
                        ptr2=ptr2->next;
                  }
            }
            while(ptr1!=NULL){
                  pushBack(ptr1->data);
                  ptr1=ptr1->next;
            }
            while(ptr2!=NULL){
                  pushBack(ptr2->data);
                  ptr2=ptr2->next;
            }

      }

};
int main(){
      LinkedList ll1,ll2,ll3,ll4;
      int m,n;
      cin>>m>>n;
      while(m--){
            int x;
            cin>>x;
            ll1.pushBack(x);
      }
      while(n--){
            int x;
            cin>>x;
            ll2.pushBack(x);
      }
      ll1.display();
      ll2.display();
      ll3.mergeSortedList(ll1,ll2);
      ll3.display();
      return 0;
}