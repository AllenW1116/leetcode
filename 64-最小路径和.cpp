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

//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//分析：这是一个典型的动态规划问题。设二维数组dp[i][j]:到达该格子的最小路径和。
//第一行的格子：dp[i][j]= dp[i][j-1]+grid[i][j](i=0)
//第一列的格子：dp[i][j]= dp[i-1][j]+grid[i][j](j=0)
//其它格子：dp[i][j]=Max(dp[i][j - 1] + grid[i][j]，dp[i - 1][j] + grid[i][j])

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        dp.resize(grid.size());        
        int n = grid.size();// 行数
        int m = grid[0].size();// 列数
        for (int k = 0; k < n; k++) { //每一行resize
            dp[k].resize(m);
        }

        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){//第一列格子
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < m; j++) {//第一行格子
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < m; b++) {
                dp[a][b] = min(dp[a][b - 1] + grid[a][b], dp[a - 1][b] + grid[a][b]);
            }
        }
        return dp[n - 1][m - 1];
    }
};