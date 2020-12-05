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

//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
//一个经典的排列树问题。做点基础题找找自信……
//根据回溯法.排列树框架：
//最初的排列开始，【第i层代表处理第i个元素】；
//几个子树分别代表：和a【i】交换（和自己交换就是不交换）。所以排列中有几个元素，第一层就有几个分支；
//第i层要处理的第i个元素，都是和从i开始（也就是不换）往后的元素换；每一个共父结点群，第一个节点都和父亲节点一样！
//后面每下一层少一个分支。（第i个元素不和第i-1个元素换，防止换回去，即回到上一层的状态）
//来个框架：
//void dfs(int a[], int n, int i)		//求a[0..n-1]的全排列
//{
//    if (i >= n)				//递归出口
//        dispasolution(a, n);
//    else
//    {
//        for (int j = i; j < n; j++)
//        {
//            swap(a[i], a[j]);		//交换a[i]与a[j]:每一个元素只与自己及其后面的元素交换
//            dfs(a, n, i + 1);
//            swap(a[i], a[j]);		//交换a[i]与a[j]：若没有找到解，恢复
//        }
//    }
//}

class Solution {
private:
	vector<int> ans;
	vector<vector<int>> anslist;
	void dfs(vector<int>& nums, int i) { //i从0开始
		if (i >= nums.size()) {
			ans = nums;
			anslist.push_back(ans);
		}
		else {
			for (int j = i; j < nums.size(); j++) {
				swap(nums[i], nums[j]);
				dfs(nums, i + 1);
				swap(nums[i], nums[j]);
			}
		}

	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		dfs(nums, 0);
		return anslist;
	}
};