
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

    TreeNode* helperFunc(vector<int> inOrder,vector<int> preOrder,int inStart,int inEnd, int preStart, int preEnd){

        if(inStart>inEnd) return NULL; //base condition

        int rootData=preOrder[preStart];
        int rootIndex=-1;
        for(int i=inStart;i<=inEnd;i++){
            if(inOrder[i]==rootData){
                rootIndex=i;
                break;
            } //rootIndex=-1 can only be if input is wrong
        }

        int leftInOrderStart=inStart;
        int leftInOrderEnd=rootIndex-1;
        int leftPreOrderStart=preStart+1;
        int leftPreOrderEnd=leftInOrderEnd+leftPreOrderStart-leftInOrderStart;

        int rightInOrderStart=rootIndex+1;
        int rightInOrderEnd=inEnd;
        int rightPreOrderStart=leftPreOrderEnd+1;
        int rightPreOrderEnd=preEnd;

        TreeNode* root=new TreeNode(rootData);
        root->left=helperFunc(inOrder,preOrder,leftInOrderStart,leftInOrderEnd,leftPreOrderStart,leftPreOrderEnd);
        root->right=helperFunc(inOrder,preOrder,rightInOrderStart,rightInOrderEnd,rightPreOrderStart,rightPreOrderEnd);

        return root;


    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        return helperFunc(inorder,preorder,0,n-1,0,n-1);
        
    }
};