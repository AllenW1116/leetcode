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

//����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//����Ŀ��Ҫ�������н�㣻��Ŀ�����Ķ��������ǽ�ռ���������Ȼ�����û��ݷ������
//����ĳһ�����ӽڵ�ʱ����sum=sum-��ǰ���val���ɡ�
//��Ҷ�ӽڵ�ʱ��ֻ��Ҫ�ж�Ҷ�ӽڵ�ֵ�Ƿ���ڴ����sum��
//���ж������������������޽⣬���ж������������ֻ���˼�롣

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

        if (root->left == NULL && root->right == NULL) { //����Ҷ�ӽڵ�
            if (root->val == sum) {
                return true;
            }
            return false;
        }
        //total += root->val;
        //int left = (root->left == NULL) ? 0 : root->left->val;
        //int right = (root->right == NULL) ? 0 : root->right->val;//�������ҽ���ֵ

        if (hasPathSum(root->left, sum - root->val) == true) {
            return true;
        }
        else {
            return hasPathSum(root->right, sum - root->val);
        }
    }
};
