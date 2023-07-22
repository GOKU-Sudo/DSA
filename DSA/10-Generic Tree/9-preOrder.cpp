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

TreeNode<int>* takeInput(){  // recursive input
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

TreeNode<int>* takeInputLevelWise(){
      int rootData;
      cout<<"Enter root Data"<<endl;
      cin>>rootData;
      TreeNode<int>* root=new TreeNode<int>(rootData);
      queue<TreeNode<int>*> q;
      q.push(root);

      while(!q.empty()){
            TreeNode<int>* f=q.front();
            q.pop();
            cout<<"No. of children of "<<f->data<<endl;
            int n;
            cin>>n;
            for(int i=1;i<=n;i++){
                  int childData;
                  cout<<"Enter "<<i<<" th child of "<<f->data<<endl;
                  cin>>childData;
                  TreeNode<int>* child=new TreeNode<int>(childData);
                  q.push(child);
                  f->children.push_back(child); 
            }
      }
            return root;

}

void printLevelWise(TreeNode<int>* root){
      queue<TreeNode<int>*> q;
      q.push(root);
      while(!q.empty()){
            TreeNode<int>* f = q.front();
            q.pop();

            cout<<f->data<<": ";                                //Level wise print
            for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<" ,";
            }
            cout<<endl;

            for(int i=0;i<f->children.size();i++){
                  q.push(f->children[i]);
            }

      }
}

int countNode(TreeNode<int>* root){
        int ans=1;                    //Count the no. of nodes
        for(int i=0;i<root->children.size();i++){
            ans=ans+countNode(root->children[i]);
        }

        return ans;
}


int heightTree(TreeNode<int>* root){

      if(root==NULL){
            return 0;
      }
      
      int heightMax=0;

      for(int i=0;i<root->children.size();i++){
            heightMax=max(heightMax,heightTree(root->children[i]));
      }

      return heightMax+1;

}


void printAllkthLevele(TreeNode<int>* root,int k){
      if(root==NULL){
            return;
      }

      if(k==0){
            cout<<root->data<<endl;
      }
      for(int i=0;i<root->children.size();i++){
            printAllkthLevele(root->children[i],k-1);
      }

}

int countLeafNode(TreeNode<int>* root){
      if(root==NULL){
            return 0;
      }
      if(root->children.size()==0){   // why the ans is incremented instead of remaining zero in the zero

            return 1;
      }
      int ans=0;
      for(int i=0;i<root->children.size();i++){
            ans+=countLeafNode(root->children[i]);
      }
      return ans;
}

void printPreOrder(TreeNode<int>* root){
      if(root==NULL) return;

      cout<<root->data<<" ";

      for(int i=0;i<root->children.size();i++){
            printPreOrder(root->children[i]);
      }
}

int main(){
      // TreeNode<int>* root=new TreeNode<int>(1);
      // TreeNode<int>* n1=new TreeNode<int>(2);
      // TreeNode<int>* n2=new TreeNode<int>(3);
      // root->children.push_back(n1);
      // root->children.push_back(n2);


      // cout<<n1->data;  //just try

      // printTree1(root);
      // printTree2(root);


      // TreeNode<int>* root2=takeInput();
      // printTree1(root2);
      // printTree2(root2);

      TreeNode<int>* root3=takeInputLevelWise();
      printLevelWise(root3);
      printPreOrder(root3);
      return 0;
}