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
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//示例 :
//
//输入: [2, 3, 1, 1, 4]
//输出 : 2
//解释 : 跳到最后一个位置的最小跳跃数是 2。
//从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
//分析：当前处在位置i，那么可以到达的最远位置为i+a[i]；
//所以只要搜索[i+1..i+a[i]]中的max（最远到达位置）,下一步跳到那里即可；
//什么时候可以跳完：若i+a[i]>=n,则i为最后一跳！步数+1算法结束即可
//
class Solution {
private:
    int sum = 0;
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int max = 0;
        int next = 0;
        if (nums.size() == 1) { //一开始就在最后一个位置
            return 0;
        }
        while (cur < nums.size()) {
            //已经可以跳完了
            if (cur + nums[cur] >= nums.size() - 1) { sum += 1; break; }
            //还不能跳完
            for (int i = cur + 1; i <= cur + nums[cur]; i++)
            {
                if (i + nums[i] > max) { max = i + nums[i]; next = i; }
            }
            //max作为下一步起跳点
            sum += 1;
            cur = next;
            max = 0;
        }
        return sum;
    }
};