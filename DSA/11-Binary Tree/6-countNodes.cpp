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
    cout<<"Enter Root Data :";
    cin>>rootData;
    BTNode<int>* root=new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
      BTNode<int>* front=q.front();
      q.pop();
      cout<<"Enter left child of :"<<front->data<<endl;
      int left;
      cin>>left;
      if(left!=-1){
            BTNode<int>* leftChild=new BTNode<int>(left);
            q.push(leftChild);
            front->left=leftChild;
      }
      cout<<"Enter right child of :"<<front->data<<endl;
      int right;
      cin>>right;
      if(right!=-1){
            BTNode<int>* rightChild=new BTNode<int>(right);
            q.push(rightChild);
            front->right=rightChild;
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

void levelWisePrint(BTNode<int>* root){
      if(root==NULL) return;
      queue<BTNode<int>*> q;
      q.push(root);
      while(!q.empty()){
            BTNode<int>* front=q.front();
            q.pop();
            cout<<front->data<<": ";
            if(front->left){
                  q.push(front->left);
                  cout<<front->left->data<<" ";
            }            
            if(front->right){
                  q.push(front->right);
                  cout<<front->right->data<<" ";
            }
            cout<<endl;            
      }

}

int countNodes(BTNode<int>* root){
      if(root==NULL) return 0;

      int ans=1;
      if(root->left){
            ans=ans+countNodes(root->left);
      }
      if(root->right){
            ans=ans+countNodes(root->right);
      }
      return ans;
}

int main(){
   
      BTNode<int>* root=takeInputLevelWise();

      levelWisePrint(root);

      cout<<countNodes(root);

      return 0;
}