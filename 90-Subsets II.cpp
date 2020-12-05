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
//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.

//���ԭ�����п������ظ���Ԫ�أ����ݼ��в������ظ���Ԫ�أ�
//���������ⷨ�����ϣ��ڽ�res���뵽reslistǰ���ж�һ�������ظ��������򲻼��롣
//����ж��ظ��أ������������е�Ԫ������һ�£��������һ�Ƚϣ�����ȫ��ͬ����������ͬ

class Solution {
private:
    vector<int> res; //  ��ŵ�������
    vector<vector<int>> reslist; // ��Ž��


    bool issameset(vector<int> set1, vector<int> set2) {
        sort(set1.begin(),set1.end());
        sort(set2.begin(), set2.end());
        return set1 == set2;

    }

    bool contain(vector<vector<int>> list, vector<int> item) {
        vector<vector<int>>::iterator it=list.begin();
        for (it; it < list.end(); it++) {
            if (issameset(*it,item)) { return true; }
        }
        return false;
        
    }

    void dfs(vector<int>& nums, int i, vector<bool> x) //n������Ԫ�ظ�����Ҳ����ռ������� i����ǰ��ռ���������x[]������

    {
        int n = nums.size();
        if (i >= n) {
            for (int i = 0; i < n; i++) { //�õ���һ���ݼ�
                if (x[i] == true) { res.push_back(nums[i]); }
            }
            if(!contain(reslist,res)){
                reslist.push_back(res);
            }
            
            res.clear();
        }

        else
        {
            x[i] = false; dfs(nums, i + 1, x);		//��ѡ��a[i]
            x[i] = true; dfs(nums, i + 1, x);		//ѡ��a[i]
        }
    }



public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<bool> x(n);
        dfs(nums, 0, x);
        return reslist;

    }
};


