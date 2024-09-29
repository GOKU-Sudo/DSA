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

      public:
      int size=0;
      Node* temp1;
      
      void pushBack(int data){
      
            if(head==NULL){
                  head=new Node(data);
                  size++;
                  return ;
            }
            Node* ptr=head;
            while(ptr->next!=NULL){
                  ptr=ptr->next;
            }
            ptr->next=new Node(data);
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

      void display(){
            if(head==NULL) return;
            Node* ptr=head;
            while(ptr!=NULL){
                  cout<<ptr->data<<"->"; 
                  ptr=ptr->next;
            }
            cout<<"NULL";
            cout<<endl;
      
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
      cout<<(ll.size)<<endl;

      ll.popFront();
      ll.display();
      cout<<(ll.size)<<endl;

    
      //  for (auto ptr = ll.head; ptr!= NULL; ptr = ptr->next) cout<<ptr->data<<' ';

      ll.popLast();
      ll.display();

      cout<<"Enter the position and Data :";
      int position,data;
      cin>>position>>data;

      ll.insertAt(position,data);
      ll.display();

      cout<<"Enter the index :";
      int index;
      cin>>index;
      ll.displayAt(index);
      return 0;
}