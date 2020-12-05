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


//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//输入：nums = [1, 1, 2]
//输出：
//[[1, 1, 2],
//[1, 2, 1],
//[2, 1, 1]]
//
//和排列类似，但在加入时需要判读：anslist中是否已经包含该ans；
//如何判断重复呢？将两个集合中的元素逐一比较，若完全相同，两集合相同（老笨蛋了）
//不难得到代码：
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

	void dfs(vector<int>& nums, int i) { //i从0开始
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
//然而这么做超时了……事实上排列树的时间复杂度本身很高，这个算法已经无法在时间复杂度上进一步优化了。
//因此我们可以使用传统的回溯法，将排列过程想象成：有n个空格，现在我们要往这n个空格里面填入数字；
//我们首先对序列进行sort，保证相同的数字是相邻的；
//每次填入数字时，可以检测相同集里手否已经有数字被填入过，如果有则可以剪枝。
//例如有序列：1 1 2；
//在解空间树的第一层第一个结点，我们填1；
//该层的第二个结点应该填i[1]，发现i[1]=i[0],则进行剪枝，不填！
//由此可以得到代码：

class Solution {
	vector<int> vis;

public:
	void backtrack(vector<int>& nums, vector<vector<int>>& anslist, int idx, vector<int>& ans) {
		if (idx == nums.size()) {
			anslist.push_back(ans);
			return;
		}
		for (int i = 0; i < (int)nums.size(); i++) {
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) { //和前一个相等且前一个没被填过
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
//一般的回溯法是二叉树
//这个是多叉树，所以要用for循环遍历每一个分叉





