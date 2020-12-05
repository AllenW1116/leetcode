#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include<stack>
#include<typeinfo>   // for typeid to work
using namespace std;

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明 : 叶子节点是指没有子节点的节点。
//
//本题目需要遍历所有结点；题目所给的二叉树就是解空间树，很显然可以用回溯法解决。
//考虑某一结点的子节点时，将sum=sum-当前结点val即可。
//到叶子节点时，只需要判断叶子节点值是否等于传入的sum。
//先判断左子树；若左子树无解，再判断右子树，体现回溯思想。

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int total = 0;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            cout << "";
            return false;
        }

        if (root->left == NULL && root->right == NULL) { //到达叶子节点
            if (root->val == sum) {
                return true;
            }
            return false;
        }
        //total += root->val;
        //int left = (root->left == NULL) ? 0 : root->left->val;
        //int right = (root->right == NULL) ? 0 : root->right->val;//保存左右结点的值

        if (hasPathSum(root->left, sum - root->val) == true) {
            return true;
        }
        else {
            return hasPathSum(root->right, sum - root->val);
        }
    }
};
