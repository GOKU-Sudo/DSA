#include<bits/stdc++.h>
using namespace std;

template <class T>

class TreeNode{
      public:
      T data;
      vector<TreeNode<T>*> children;
      TreeNode(T data){
            this->data=data;
      }
};

void printTree1(TreeNode<int>* root ){

      if(root==NULL){
            return;
      }
      cout<<root->data<<endl;

      for(int i=0;i<root->children.size();i++){  //recursive printing only node;
            printTree1(root->children.at(i));
      }
}
void printTree2(TreeNode<int>* root ){
      if(root==NULL){
            return;
      }
      cout<<root->data<<": ";
      for(int i=0;i<root->children.size();i++){
            cout<<root->children[i]->data<<",";
      }
      cout<<endl;

      for(int i=0;i<root->children.size();i++){  //printing optimize recursive;
            printTree2(root->children.at(i));
      }
}

TreeNode<int>* takeInput(){
      int rootData;
      cout<<"Enter data :"<<endl;
      cin>>rootData;
      TreeNode<int>* root=new TreeNode<int>(rootData);
      cout<<"How many children: "<<endl;
      int n;
      cin>>n;
      for(int i=0;i<n;i++){
            TreeNode<int>* child=takeInput();
            root->children.push_back(child);
      }
      return root;
}

int main(){
      TreeNode<int>* root=new TreeNode<int>(1);
      TreeNode<int>* n1=new TreeNode<int>(2);
      TreeNode<int>* n2=new TreeNode<int>(3);
      root->children.push_back(n1);
      root->children.push_back(n2);
      // cout<<n1->data;

      printTree1(root);
      printTree2(root);


      TreeNode<int>* root2=takeInput();
      printTree1(root2);
      printTree2(root2);

      return 0;
}