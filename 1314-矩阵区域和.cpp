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
//给你一个 m* n 的矩阵 mat 和一个整数 K ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和： 
//
//i - K <= r <= i + K, j - K <= c <= j + K 
//(r, c) 在矩阵内。
//
//
//示例 1：
//
//输入：mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], K = 1
//输出： [[12, 21, 16], [27, 45, 33], [24, 39, 28]]
//
//这简直是一个把动态规划拍在脸上的题，其实解题思路和上一题【最小路径和】相似，使用dp[][]来逐步记录，最后得到整个矩阵即可

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();//行数
        int m = mat[0].size();//列数
        ans.resize(mat.size());
        for (int k = 0; k < n; k++) { //每一行resize
            ans[k].resize(m);
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = 0;
                //计算ans[i][j]
                for (int k = i - K; k <= i + K; k++) {
                    for (int p = j - K; p <= j + k; p++) {
                        k = k < 0 ? 0 : k;
                        p = p < 0 ? 0 : p;
                        k = k >= n ? n - 1 : k;
                        p = p >= m ? m - 1 : p;
                        ans[i][j] += mat[k][p];
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {

        int n = mat.size() + 1, m = mat[0].size() + 1;
        vector<vector<int>> sumvec(n, vector<int>(m, 0));
        vector<vector<int>> ans(n - 1, vector<int>(m - 1, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) { //求前缀和
                sumvec[i][j] = sumvec[i][j - 1] + sumvec[i - 1][j] - sumvec[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        n--; m--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int L = (j - K) < 0 ? 0 : j - K;
                int R = (j + K) >= m ? m - 1 : j + K;
                int U = (i - K) < 0 ? 0 : i - K;
                int D = (i + K) >= n ? n - 1 : i + K;

                ans[i][j] = sumvec[D + 1][R + 1] - sumvec[D + 1][j - K] - sumvec[U][R + 1] + sumvec[U][L];
            }
        }

        return ans;
    }
};