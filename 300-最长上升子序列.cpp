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
//给定一个无序的整数数组，找到其中最长上升子序列的长度。
//
//示例 :
//
//输入: [10, 9, 2, 5, 3, 7, 101, 18]
//输出 : 4
//解释 : 最长的上升子序列是 [2, 3, 7, 101]，它的长度是 4。
//
//使用动态规划，设dp[i]为：以a[i]结尾的最长子序列长度;
//那么在填入dp[i]时，我们只需要扫描j∈[0..i-1]的每一个数字，若a[j]<a[i],
//那么a[i]就加入了以a[j]做结尾的子序列中！
//dp[i]=Max(dp[j]+1,dp[i])

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { dp[i] = max(dp[j] + 1, dp[i]); }
            }
        }
        int ans = 0;
        vector<int>::iterator it = dp.begin();
        for (it = dp.begin(); it < dp.end(); it++) {
            if (*it > ans) ans = *it;
        }
        return ans;
    }
};
