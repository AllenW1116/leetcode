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
//给定一个数组，它的第 i 个元素是【一支】给定股票第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//示例 1:
//
//输入: [7, 1, 5, 3, 6, 4]
//输出 : 7
//解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
//
//分析：我们可以这样想这个问题：我们一直在买卖同一只股票，这只股票的价格是不断变动的；
//那么我们可能的最大获利是多少？显然是：价格波动图（横轴为时间纵轴为价格）上所有递增序列的落差的和！
//因此，我们只要不断计算序列中相邻两个价格的差值，若为正就将其加入maxprofit，若为负则不加入。

class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] - prices[i - 1] > 0) { profit += prices[i] - prices[i - 1]; }
        }
        return profit;
    }

};


