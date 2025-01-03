#include<iostream>
using namespace std;

template<typename T>

class BTNode{
      public:
      T data;
      BTNode* left;
      BTNode* right;

      BTNode(T data){
            this->data=data;
            left=NULL;
            right=NULL;
      }
      ~BTNode(){
            delete left;
            delete right;
      }
};

BTNode<int>* takeInput(){  //not optimal way of taking input becuz we have to keep
                          // the track of BT insertion
      int rootData;
      cout<<"Enter data: "<<endl;
      cin>>rootData;

      if(rootData==-1) return NULL;

      BTNode<int>* root=new BTNode<int>(rootData);
      BTNode<int>* leftChild=takeInput();
      BTNode<int>* rightChild=takeInput();

      root->left=leftChild;
      root->right=rightChild;

      return root;
}      



void printTree(BTNode<int>*root){ 
      if(root==NULL) return ;

       cout<<root->data<<": ";
       if(root->left!=NULL) cout<<"L"<<root->left->data<<" ";

       if(root->right!=NULL) cout<<"R"<<root->right->data;

       cout<<endl;

       printTree(root->left);
       printTree(root->right);
}

int main(){
      BTNode<int>* root=takeInput();

      printTree(root);

      delete root;
      return 0;
}