#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
      public:
      T data;
      vector<TreeNode<T>*> children;
      TreeNode(T data){
            this->data=data;
      }
};

int main(){
      TreeNode<int>* root=new TreeNode<int>(1);
      TreeNode<int>* n1=new TreeNode<int>(2);
      TreeNode<int>* n2=new TreeNode<int>(3);
      root->children.push_back(n1);
      root->children.push_back(n2);
      // cout<<n1->data;
      return 0;
}