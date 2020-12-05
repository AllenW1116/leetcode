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

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//使用回溯法 - 子集树来解决该问题。
//一个问题有很多步、每一步有不同的选择、又要求出问题的所有解，就可以使用回溯法。
//现在来看组合问题：从1234中找出所有组合，应当是：12 13 14 23 24 34
//也就是说，包含i的组合，只需要在[i..end]中找即可

//此处有一个细节：必须先记录合法答案，再判断是否超出范围；否则会丢失【i，n】这个解。比如（2，3），就会丢失（1，3），（2，3）


class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {

        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        //超出范围
        if (cur > n) {
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};