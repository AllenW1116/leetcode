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

//����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�
//
//һ����������������⡣����������������š���
//���ݻ��ݷ�.��������ܣ�
//��������п�ʼ������i��������i��Ԫ�ء���
//���������ֱ������a��i�����������Լ��������ǲ��������������������м���Ԫ�أ���һ����м�����֧��
//��i��Ҫ����ĵ�i��Ԫ�أ����Ǻʹ�i��ʼ��Ҳ���ǲ����������Ԫ�ػ���ÿһ���������Ⱥ����һ���ڵ㶼�͸��׽ڵ�һ����
//����ÿ��һ����һ����֧������i��Ԫ�ز��͵�i-1��Ԫ�ػ�����ֹ����ȥ�����ص���һ���״̬��
//������ܣ�
//void dfs(int a[], int n, int i)		//��a[0..n-1]��ȫ����
//{
//    if (i >= n)				//�ݹ����
//        dispasolution(a, n);
//    else
//    {
//        for (int j = i; j < n; j++)
//        {
//            swap(a[i], a[j]);		//����a[i]��a[j]:ÿһ��Ԫ��ֻ���Լ���������Ԫ�ؽ���
//            dfs(a, n, i + 1);
//            swap(a[i], a[j]);		//����a[i]��a[j]����û���ҵ��⣬�ָ�
//        }
//    }
//}

class Solution {
private:
	vector<int> ans;
	vector<vector<int>> anslist;
	void dfs(vector<int>& nums, int i) { //i��0��ʼ
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