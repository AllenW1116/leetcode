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


//����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�
//���룺nums = [1, 1, 2]
//�����
//[[1, 1, 2],
//[1, 2, 1],
//[2, 1, 1]]
//
//���������ƣ����ڼ���ʱ��Ҫ�ж���anslist���Ƿ��Ѿ�������ans��
//����ж��ظ��أ������������е�Ԫ����һ�Ƚϣ�����ȫ��ͬ����������ͬ���ϱ����ˣ�
//���ѵõ����룺
class Solution {
private:
	vector<int> ans;
	vector<vector<int>> anslist;



	bool contain(vector<vector<int>> list, vector<int> item) {
		vector<vector<int>>::iterator it = list.begin();
		for (it; it < list.end(); it++) {
			if (*it == item) { return true; }
		}
		return false;
	}

	void dfs(vector<int>& nums, int i) { //i��0��ʼ
		if (i >= nums.size()) {
			ans = nums;
			if (!contain(anslist, ans)) {
				anslist.push_back(ans);
			}
		}
		else {
			for (int j = i; j < nums.size(); j++) {
				if (nums[i] != nums[j]) {
					swap(nums[i], nums[j]);
					dfs(nums, i + 1);
					swap(nums[i], nums[j]);
				}
				
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		dfs(nums, 0);
		return anslist;
	}
};
//Ȼ����ô����ʱ�ˡ�����ʵ����������ʱ�临�Ӷȱ���ܸߣ�����㷨�Ѿ��޷���ʱ�临�Ӷ��Ͻ�һ���Ż��ˡ�
//������ǿ���ʹ�ô�ͳ�Ļ��ݷ��������й�������ɣ���n���ո���������Ҫ����n���ո������������֣�
//�������ȶ����н���sort����֤��ͬ�����������ڵģ�
//ÿ����������ʱ�����Լ����ͬ�����ַ��Ѿ������ֱ�����������������Լ�֦��
//���������У�1 1 2��
//�ڽ�ռ����ĵ�һ���һ����㣬������1��
//�ò�ĵڶ������Ӧ����i[1]������i[1]=i[0],����м�֦�����
//�ɴ˿��Եõ����룺

class Solution {
	vector<int> vis;

public:
	void backtrack(vector<int>& nums, vector<vector<int>>& anslist, int idx, vector<int>& ans) {
		if (idx == nums.size()) {
			anslist.push_back(ans);
			return;
		}
		for (int i = 0; i < (int)nums.size(); i++) {
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) { //��ǰһ�������ǰһ��û�����
				continue;
			}
			ans.push_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, anslist, idx + 1, ans);
			vis[i] = 0;
			ans.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> perm;
		vis.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}
};
//
//һ��Ļ��ݷ��Ƕ�����
//����Ƕ����������Ҫ��forѭ������ÿһ���ֲ�





