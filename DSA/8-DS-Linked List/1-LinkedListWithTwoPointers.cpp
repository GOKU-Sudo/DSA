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

      void pushFront(int data){
            if(head==NULL) return;
            Node* n=new Node(data);
            n->next=head;
            head=n;
            
      }

      void insertAt(int index,int data){
            if(index==0){
                  pushFront(data);
                  size++;
                  return;
            }
            else if(index==size){
                  pushBack(data);
                  size++;
                  return;
            }
            else if(0<index and index<=size-1){
                  int i=0;
                  Node* ptr=head;
                  while(i<index-1){
                        ptr=ptr->next;
                        i++;
                  }
                  
             
                  Node* temp;
                  temp=ptr->next;
                  Node* n=new Node(data);
                  ptr->next=n;
                  n->next=temp;
                  size++;
                  return;
            }
            else if(index<0 or index>=size){
                  cout<<"Out of Index range----"<<endl;
                  return;
            }

      }
      bool search(int data){
            if(head==NULL and tail==NULL) return false;
            Node* ptr=head;
            while(ptr!=NULL){
                  if(ptr->data==data) return true;
                  ptr=ptr->next;
            }
            return false;
      }

      void middleChar(){                                    //slow and fast pointer approach and only one traversal is needed
            if(head==NULL and tail==NULL) return ;
            Node* slow=head;
            Node* fast=head->next;
            while(fast and fast->next){
                  slow=slow->next;
                  fast=fast->next->next;
            }
            if(fast==NULL) cout<< slow->data; // odd

            else cout<<slow->next->data; // even
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

      void displayReverse(){
            Node* ptr=head;
            stack<int> s1;
            while(ptr!=NULL){
                  s1.push(ptr->data);
                  ptr=ptr->next;
            }
            while(!s1.empty()){
                  cout<<s1.top()<<"->";
                  s1.pop();
            }
            cout<<"NULL"<<endl;
      }

      void reverseList(){
             if(head==NULL and tail==NULL) return;
             Node* prev=NULL;
             Node* curr=head;
             while(curr!=NULL){
                  Node* n=curr->next;
                  curr->next=prev;
                  prev=curr;
                  curr=n;
             }
             head=prev;
      }

      void displayAt(int index){
            if(index>=0 and index<=size-1){
                  int i=0;
                  Node* ptr=head;
                  while(i<index){
                        ptr=ptr->next;
                        i++;
                  }
                  cout<<ptr->data<<endl;
            }
            else{
                  cout<<"out of Index range--"<<endl;
            }
      }

      void deleteAt(int index){
            if(index>0 and index<=size-1){
                  int i=0;
                  Node* ptr=head;
                  Node* prev=NULL;
                  while(i<index){
                        prev=ptr;
                        ptr=ptr->next;
                        i++;
                  }
                  prev->next=ptr->next;
                  size--;

            }
            else if(index==0){
                  popFront();
            }
            else{
                  cout<<"Out of range";
            }
      }

      void deleteFromLast(int n){
            Node* ptr=head;
            while(ptr!=NULL){
                  ptr=ptr->next;
            }
            ptr=head;
            for(int i=0;i<size-n-1;i++){ptr=ptr->next;}
            ptr->next=ptr->next->next;
      }

      void popFront(){
            if(head==NULL) return;
            head=head->next;
            size--;
      }

      void popLast(){
            if(head==NULL) return;
            Node* ptr=head;
            while(ptr->next->next!=NULL){
                  ptr=ptr->next;
            }
            ptr->next=NULL;
            size--;
      }

};

int main(){
      LinkedList ll;
      int n;
      cin>>n;
      while(n--){
            int element;
            cin>>element;
            ll.pushBack(element);
      }
      ll.display();
      ll.reverseList();
      ll.display();
}