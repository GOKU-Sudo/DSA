#include<bits/stdc++.h>
#include<iostream>
#include<queue>
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
                          // recursive input
      int rootData;
      cout<<"Enter data: "<<endl;
      cin>>rootData;

      if(rootData==-1) return NULL;

      BTNode<int>* root=new BTNode<int>(rootData);
      
      root->left=takeInput();
      root->right=takeInput();


      return root;
}      

BTNode<int>* takeInputLevelWise(){ // iterative input
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

         cout<<"Enter left child of "<<f->data<<endl;
         int leftChildData;
         cin>>leftChildData;
         if(leftChildData != -1){
            BTNode<int>* child = new BTNode<int>(leftChildData);
            q.push(child);
            f->left = child;
         }
         cout<<"Enter right child of "<<f->data<<endl;
         int rightChildData;
         cin>>rightChildData;
         if(rightChildData != -1){
            BTNode<int>* child = new BTNode<int>(rightChildData);
            q.push(child);
            f->right = child;
         }
    }
    return root;
}


void printTree(BTNode<int>*root){  // recursiveprinting
      if(root==NULL) return ;

       cout<<root->data<<": ";
       if(root->left!=NULL) cout<<"L"<<root->left->data<<" ";

       if(root->right!=NULL) cout<<"R"<<root->right->data;

       cout<<endl;

       printTree(root->left);
       printTree(root->right);
}

vector<vector<int>> levelOrder(BTNode<int>* root){
      vector<vector<int>> v;
      if(root==NULL){ cout<<"Empty"; return v;}
      vector<int> temp; // storing result of current level

      queue<BTNode<int>*> q;
      q.push(root);
      q.push(NULL);
      while(!q.empty()){
            BTNode<int>* f=q.front();
            q.pop();
            if(f==NULL){
                  cout<<endl;
                  v.push_back(temp);
                  temp.clear();
                  if(!q.empty()){
                        q.push(NULL);
                  }
            }
            else{
                  temp.push_back(f->data);
                  if(f->left){
                        q.push(f->left);
                  }
                  if(f->right){
                        q.push(f->right);
                  }
            }
      }
  for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
      return v;
}


int main(){
      // BTNode<int>* root=takeInput();
      BTNode<int>* root=takeInputLevelWise();

      printTree(root);
      levelOrder(root);
      delete root;
      return 0;
}