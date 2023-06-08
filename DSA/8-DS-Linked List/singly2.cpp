#include<iostream>
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

int main(){
      // statically
      Node n1(1);
      Node *head=&n1;
      Node n2(2);
      Node n3(3);
      Node n4(3);
      Node n5(3);
      n1.next=&n2;
      n2.next=&n3;
      n3.next=&n4;
      n4.next=&n5;

      // print(head)
      // cout<<n1.data<<"->"<<n2.data<<"->"<<n3.data<<endl;
      // Node* head=&n1;
      // cout<<head->data;

      //dynamically
      // Node* n4=new Node(3);
      // Node* n5=new Node(4);
      // n4->next=n5;


      return 0;
}