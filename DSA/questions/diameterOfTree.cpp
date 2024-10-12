#include<bits/stdc++.h> // Include all standard libraries
using namespace std; // Use the standard namespace

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
class Solution { // Define the Solution class
public:

pair<int,int> heightDiameter(TreeNode* root){ // Function to calculate height and diameter of the tree
    if(root==NULL){ // Base case: if the node is null
        pair<int,int> p; // Create a pair to store height and diameter
        p.first=0; // Height is 0
        p.second=0; // Diameter is 0
        return p; // Return the pair
    }

    pair<int,int> leftAns=heightDiameter(root->left); // Recursively get height and diameter of left subtree
    pair<int,int> rightAns=heightDiameter(root->right); // Recursively get height and diameter of right subtree

    int leftHeight=leftAns.first; // Height of left subtree
    int leftDiameter=leftAns.second; // Diameter of left subtree

    int rightHeight=rightAns.first; // Height of right subtree
    int rightDiameter=rightAns.second; // Diameter of right subtree

    int height=1+max(leftHeight,rightHeight); // Calculate current node height
    int diameter=max(leftHeight+rightHeight,max(leftDiameter,rightDiameter)); // Calculate current node diameter

    pair<int,int> finalAnsPair; // Create a pair to store final height and diameter
    finalAnsPair.first=height; // Set height in the pair
    finalAnsPair.second=diameter; // Set diameter in the pair
    return finalAnsPair; // Return the pair
}

    int diameterOfBinaryTree(TreeNode* root) { // Function to get the diameter of the binary tree
        pair<int,int>p=heightDiameter(root); // Get height and diameter of the tree
        return p.second; // Return the diameter
    }
};
