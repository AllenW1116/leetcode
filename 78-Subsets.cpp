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
//Given an integer array nums, return all possible subsets(the power set).
//
//The solution set must not contain duplicate subsets.
//
//求幂集问题，经典的子集树回溯法。其实是因为做难题太打击自信，做一个基础题缓一缓……


class Solution {
private:
    vector<int> res; //  存放单个集合
    vector<vector<int>> reslist; // 存放结果
    void dfs(vector<int>& nums, int i, vector<bool> x) //n：集合元素个数，也即解空间树层数 i：当前解空间树层数；x[]解向量

    {
        int n = nums.size();
        if (i >= n) {
            for (int i = 0; i < n; i++) { //得到了一个幂集
                if (x[i] == true) { res.push_back(nums[i]); }
            }
            reslist.push_back(res);
            res.clear();
        }

        else
        {
            x[i] = false; dfs(nums, i + 1, x);		//不选择a[i]
            x[i] = true; dfs(nums, i + 1, x);		//选择a[i]
        }
    }



public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> x(n);
        dfs(nums, 0, x);
        return reslist;

    }
};


// 测试方法
//vector<int> res; //  存放单个集合
//vector<vector<int>> reslist; // 存放结果
//void dfs(vector<int>& nums, int i, vector<bool> x) //n：集合元素个数，也即解空间树层数 i：当前解空间树层数；x[]解向量
//
//{
//    int n = nums.size();
//    if (i >= n) {
//        for (int i = 0; i < n; i++) { //得到了一个幂集
//            if (x[i] == true) { res.push_back(nums[i]); }
//        }
//        reslist.push_back(res);
//        res.clear();
//    }
//
//    else
//    {
//        x[i] = false; dfs(nums, i + 1, x);		//不选择a[i]
//        x[i] = true; dfs(nums, i + 1, x);		//选择a[i]
//    }
//}
//
//vector<vector<int>> subsets(vector<int>& nums) {
//    int n = nums.size();
//    vector<bool> x(n);
//    dfs(nums, 0, x);
//    return reslist;
//
//}
//
//int main() {
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(2);
//    subsets(nums);
//    return 0;
//}