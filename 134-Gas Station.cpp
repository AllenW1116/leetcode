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
//1.����վ�㣬gas[i] > cost[i]
//2.����һ��rest[]; rest[i] = rest[i - 1] + gas[i] - cost[i - 1];
//��ϸһ�벻��Ҫ���飬��������rest���ɡ���ʼʱrest = 0��
//3.����һȦ��������ÿһ���㶼��rest[i] + gas[i] > cost[i]
//4.���ѡ��һ�������㣿��expectation[i] = gas[i] - cost[i];
//�ҵ��������е���������кͣ������п�ͷ���ǳ����㣡



int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.size() == 1) {
		return gas[0] >= cost[0];
	}
	vector<int> expect;
	int n = gas.size();
	for (int i = 0; i < gas.size(); i++) {  // ��������expect�����������
		expect.push_back(gas[i] - cost[i]);
	}
	int rest = 0;
	int dp[200000];
	dp[0] = 0;
	for (int j = 1; j <=n*2-1; j++)
		dp[j] = max(dp[j-1] + expect[(j - 1 + n) % n], expect[(j - 1 + n) % n]);

	int maxj = 1; int k = 0; int j = 0;
	for (j = 2; j <= n*2-1; j++)		//��dp�����Ԫ��dp[
		if (dp[j] > dp[maxj]) maxj = j;

	for (k = maxj; k >= 1; k--)		//kΪ������
		if (dp[k] <= 0) break;

	for ( j = k+1; j < k + n; j++) { // ���ǳ��������һ�����rest
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
