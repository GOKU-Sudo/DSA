#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helperFunc(vector<int> inorder,vector<int> postorder,int inorderStart,int inorderEnd, int postorderStart,int postorderEnd){

        if(inorderStart>inorderEnd) return NULL;

        int rootData=postorder[postorderEnd];

        int rootIndex=-1;
        for(int i=inorderStart;i<=inorderEnd;i++){
            if(inorder[i]==rootData){
                rootIndex=i;
                break;
            }
        }

        int leftinorderStart=inorderStart;
        int leftinorderEnd=rootIndex-1;
        int leftpostorderStart=postorderStart;
        int leftpostorderEnd=leftpostorderStart+leftinorderEnd-leftinorderStart;

        int rightinorderStart=rootIndex+1;
        int rightinorderEnd=inorderEnd;
        int rightpostorderStart=leftpostorderEnd+1;
        int rightpostorderEnd=postorderEnd-1;

    TreeNode* root=new TreeNode(rootData);
    root->left=helperFunc(inorder,postorder,leftinorderStart,leftinorderEnd,leftpostorderStart,leftpostorderEnd);
    root->right=helperFunc(inorder,postorder,rightinorderStart,rightinorderEnd,rightpostorderStart,rightpostorderEnd);

    return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n=inorder.size();
        
        return helperFunc(inorder,postorder,0,n-1,0,n-1);
    }
};