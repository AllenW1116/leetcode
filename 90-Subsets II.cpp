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
//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.

//如今原集合中可能有重复的元素，但幂集中不能有重复的元素；
//因此在上题解法基础上，在将res加入到reslist前，判断一下有无重复，若有则不加入。
//如何判断重复呢？将两个集合中的元素排序一下，排序后逐一比较，若完全相同，两集合相同

class Solution {
private:
    vector<int> res; //  存放单个集合
    vector<vector<int>> reslist; // 存放结果


    bool issameset(vector<int> set1, vector<int> set2) {
        sort(set1.begin(),set1.end());
        sort(set2.begin(), set2.end());
        return set1 == set2;

    }

    bool contain(vector<vector<int>> list, vector<int> item) {
        vector<vector<int>>::iterator it=list.begin();
        for (it; it < list.end(); it++) {
            if (issameset(*it,item)) { return true; }
        }
        return false;
        
    }

    void dfs(vector<int>& nums, int i, vector<bool> x) //n：集合元素个数，也即解空间树层数 i：当前解空间树层数；x[]解向量

    {
        int n = nums.size();
        if (i >= n) {
            for (int i = 0; i < n; i++) { //得到了一个幂集
                if (x[i] == true) { res.push_back(nums[i]); }
            }
            if(!contain(reslist,res)){
                reslist.push_back(res);
            }
            
            res.clear();
        }

        else
        {
            x[i] = false; dfs(nums, i + 1, x);		//不选择a[i]
            x[i] = true; dfs(nums, i + 1, x);		//选择a[i]
        }
    }



public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<bool> x(n);
        dfs(nums, 0, x);
        return reslist;

    }
};


