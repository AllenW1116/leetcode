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
//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//首先我们需要一个方法来判断给定字符串是否为回文串。isPalindrome方法。
//测试得知：空字符串Null也是回文串。

//分析得知，该问题需要找到所有可能的解，且不改变原字符串的顺序，因此为一个子集树回溯法问题。
//每次分割一次目标字符串，得到的结果存进一个vector<string>中；
//每次调用算法得到的vector<string>再存进一个公共的vector<vector<string>>中。
//因此，在题目所给的partition方法中首先定义一个vector<vector<string>> anslist，然后定义回溯方法，回溯方法要添加对anslist的引用；
//然后定义一个vector<string> ans，用于存放单次分割产生的答案
//在回溯方法中定义一个用于存放单个分割结果，若得到结果就将其存入anslist中。





//class Solution {
//private:
//    vector<vector<string>> result;
//    vector<string> path; // 放已经回文的子串
//    void backtracking(const string& s, int startIndex) {
//        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
//        if (startIndex >= s.size()) {
//            result.push_back(path);
//            return;
//        }
//        for (int i = startIndex; i < s.size(); i++) {
//            if (isPalindrome(s, startIndex, i)) {   // 是回文子串
//                // 获取[startIndex,i]在s中的子串
//                string str = s.substr(startIndex, i - startIndex + 1);
//                path.push_back(str);
//            }
//            else {                                // 不是回文，跳过
//                continue;
//            }
//            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
//            path.pop_back(); // 回溯过程，弹出本次已经填在的子串
//        }
//    }
//    bool isPalindrome(const string& s, int start, int end) {
//        for (int i = start, j = end; i < j; i++, j--) {
//            if (s[i] != s[j]) {
//                return false;
//            }
//        }
//        return true;
//    }
//public:
//    vector<vector<string>> partition(string s) {
//        result.clear();
//        path.clear();
//        backtracking(s, 0);
//        return result;
//    }
//};

