#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include<stack>
using namespace std;
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tankand it costs cost[i] of gas to travel from station i to its next station(i + 1).
//
//You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
//
//1.出发站点，gas[i] > cost[i]
//2.设置一个rest[]; rest[i] = rest[i - 1] + gas[i] - cost[i - 1];
//仔细一想不需要数组，单独变量rest即可。初始时rest = 0。
//3.能走一圈的条件：每一个点都有rest[i] + gas[i] > cost[i]
//4.如何选择一个出发点？设expectation[i] = gas[i] - cost[i];
//找到环形序列的最大子序列和，子序列开头就是出发点！



int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.size() == 1) {
		return gas[0] >= cost[0];
	}
	vector<int> expect;
	int n = gas.size();
	for (int i = 0; i < gas.size(); i++) {  // 求环形序列expect的最大子序列
		expect.push_back(gas[i] - cost[i]);
	}
	int rest = 0;
	int dp[200000];
	dp[0] = 0;
	for (int j = 1; j <=n*2-1; j++)
		dp[j] = max(dp[j-1] + expect[(j - 1 + n) % n], expect[(j - 1 + n) % n]);

	int maxj = 1; int k = 0; int j = 0;
	for (j = 2; j <= n*2-1; j++)		//求dp中最大元素dp[
		if (dp[j] > dp[maxj]) maxj = j;

	for (k = maxj; k >= 1; k--)		//k为出发点
		if (dp[k] <= 0) break;

	for ( j = k+1; j < k + n; j++) { // 考虑出发点的下一个点的rest
		rest = rest + gas[(j - 1 + n) % n] - cost[(j-1+n)%n   ];
		if (rest + gas[j%n] < cost[j%n ]) { return -1; }
	}
	return k;
}
int main() {
	vector<int> gas; 
	vector<int> cost;
	int g[] = {5,8,2,8};
	int c[] = {6,5,6,6};
	for (int i = 0; i < 4; i++) {
		gas.push_back(g[i]);
		cost.push_back(c[i]);
	}
	cout<<canCompleteCircuit(gas, cost);
	return 1;
}
