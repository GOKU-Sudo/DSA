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

void inorderTraversal(BTNode<int>* root){
      if(root==NULL) return;

      inorderTraversal(root->left);
      cout<<root->data<<" ";
      inorderTraversal(root->right);

}

void preorderTraversal(BTNode<int>* root){
      if(root==NULL) return;

      cout<<root->data<<" ";
      preorderTraversal(root->left);
      preorderTraversal(root->right);
}
void postorderTraversal(BTNode<int>* root){
      if(root==NULL) return;

      postorderTraversal(root->left);
      postorderTraversal(root->right);
      cout<<root->data<<" ";
}

int heightTree(BTNode<int>* root){
      if(root==NULL){
            return 0;
      }
      int left=heightTree(root->left);
      int right=heightTree(root->right);

      return max(left,right)+1;

}

bool symmetricTree(BTNode<int>* leftT,BTNode<int>* rightT){
      if(leftT==NULL && rightT!=NULL) return false;
      if(leftT!=NULL && rightT==NULL) return false;
      if(leftT==NULL && rightT==NULL) return true;

      if(leftT->data!= rightT->data) return false;

      return symmetricTree(leftT->left,rightT->right) && symmetricTree(leftT->right,rightT->left); 

}

bool findNode(BTNode<int>* root,int key){
      if(root==NULL) return false;

      if(root->data==key){
            return true;
      }

      return findNode(root->left,key) or findNode(root->right,key);
}

int minValue(BTNode<int>* root){
      if(root==NULL) return INT_MAX;

      int ans=root->data;

      int leftMin=minValue(root->left);
      int rightMin=minValue(root->right);

      int final1=min(leftMin,rightMin);
      return min(final1,ans);


}
int maxValue(BTNode<int>* root){
      if(root==NULL) return INT_MIN;

      int ans=root->data;

      int leftMin=maxValue(root->left);
      int rightMin=maxValue(root->right);

      int final1=max(leftMin,rightMin);
      return max(final1,ans);


}

int countLeafNodes(BTNode<int>* root){
      if(root==NULL) return 0;

      if(root->left==NULL and root->right==NULL) return 1;

      int count=0;
      count=count+countLeafNodes(root->left) ;
      count=count+countLeafNodes(root->right);
      return count;
}

int main(){
   
      BTNode<int>* root=takeInputLevelWise();

      levelWisePrint(root);
      cout<<countLeafNodes(root);

      return 0;
}

