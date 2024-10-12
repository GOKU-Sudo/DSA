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

pair<int,int> heightDiameter(TreeNode* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);

    int leftHeight=leftAns.first;
    int leftDiameter=leftAns.second;

    int rightHeight=rightAns.first;
    int rightDiameter=rightAns.second;

    int height=1+max(leftHeight,rightHeight);
    int diameter=max(leftHeight+rightHeight,max(leftDiameter,rightDiameter));

    pair<int,int> finalAnsPair;
    finalAnsPair.first=height;
    finalAnsPair.second=diameter;
    return finalAnsPair;
}

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>p=heightDiameter(root);
        return p.second;
    }
};