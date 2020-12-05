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

//������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�
//ʹ�û��ݷ� - �Ӽ�������������⡣
//һ�������кܶಽ��ÿһ���в�ͬ��ѡ����Ҫ�����������н⣬�Ϳ���ʹ�û��ݷ���
//��������������⣺��1234���ҳ�������ϣ�Ӧ���ǣ�12 13 14 23 24 34
//Ҳ����˵������i����ϣ�ֻ��Ҫ��[i..end]���Ҽ���

//�˴���һ��ϸ�ڣ������ȼ�¼�Ϸ��𰸣����ж��Ƿ񳬳���Χ������ᶪʧ��i��n������⡣���磨2��3�����ͻᶪʧ��1��3������2��3��


class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {

        // ��¼�Ϸ��Ĵ�
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        //������Χ
        if (cur > n) {
            return;
        }
        // ����ѡ��ǰλ��
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // ���ǲ�ѡ��ǰλ��
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};