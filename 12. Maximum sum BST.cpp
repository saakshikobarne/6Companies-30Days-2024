/*
Problem Statement:

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/




//code:

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

    struct MyNode{
        int maxNode, minNode, maxSum;

        MyNode(int maxNode, int minNode, int maxSum){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSum = maxSum;
        }
    };

    int MAX_SUM = INT_MIN;

    MyNode getMaxSum(TreeNode* root) {
        
        if(!root) return MyNode(INT_MIN, INT_MAX, 0); 

        MyNode myLeftNode = getMaxSum(root->left);
        MyNode myRightNode = getMaxSum(root->right);

        if(myLeftNode.maxNode < root->val && root->val < myRightNode.minNode){ 
            MAX_SUM = max(MAX_SUM, myLeftNode.maxSum + myRightNode.maxSum + root->val);
            
            return MyNode(
                    max(root->val, myRightNode.maxNode), 
                    min(root->val, myLeftNode.minNode),
                    myLeftNode.maxSum + myRightNode.maxSum + root->val
                );
        }
        return MyNode(INT_MAX, INT_MIN, 0); 
    }

public:
    int maxSumBST(TreeNode* root) {
        MyNode node = getMaxSum(root);
        return (MAX_SUM < 0)? 0 : MAX_SUM;
    }
};
