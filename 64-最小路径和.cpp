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

//����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//
//˵����ÿ��ֻ�����»��������ƶ�һ����
//
//����������һ�����͵Ķ�̬�滮���⡣���ά����dp[i][j]:����ø��ӵ���С·���͡�
//��һ�еĸ��ӣ�dp[i][j]= dp[i][j-1]+grid[i][j](i=0)
//��һ�еĸ��ӣ�dp[i][j]= dp[i-1][j]+grid[i][j](j=0)
//�������ӣ�dp[i][j]=Max(dp[i][j - 1] + grid[i][j]��dp[i - 1][j] + grid[i][j])

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        dp.resize(grid.size());        
        int n = grid.size();// ����
        int m = grid[0].size();// ����
        for (int k = 0; k < n; k++) { //ÿһ��resize
            dp[k].resize(m);
        }

        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){//��һ�и���
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < m; j++) {//��һ�и���
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