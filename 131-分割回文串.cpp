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
//����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
//
//���� s ���п��ܵķָ����
//
//����������Ҫһ���������жϸ����ַ����Ƿ�Ϊ���Ĵ���isPalindrome������
//���Ե�֪�����ַ���NullҲ�ǻ��Ĵ���

//������֪����������Ҫ�ҵ����п��ܵĽ⣬�Ҳ��ı�ԭ�ַ�����˳�����Ϊһ���Ӽ������ݷ����⡣
//ÿ�ηָ�һ��Ŀ���ַ������õ��Ľ�����һ��vector<string>�У�
//ÿ�ε����㷨�õ���vector<string>�ٴ��һ��������vector<vector<string>>�С�
//��ˣ�����Ŀ������partition���������ȶ���һ��vector<vector<string>> anslist��Ȼ������ݷ��������ݷ���Ҫ��Ӷ�anslist�����ã�
//Ȼ����һ��vector<string> ans�����ڴ�ŵ��ηָ�����Ĵ�
//�ڻ��ݷ����ж���һ�����ڴ�ŵ����ָ��������õ�����ͽ������anslist�С�





//class Solution {
//private:
//    vector<vector<string>> result;
//    vector<string> path; // ���Ѿ����ĵ��Ӵ�
//    void backtracking(const string& s, int startIndex) {
//        // �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
//        if (startIndex >= s.size()) {
//            result.push_back(path);
//            return;
//        }
//        for (int i = startIndex; i < s.size(); i++) {
//            if (isPalindrome(s, startIndex, i)) {   // �ǻ����Ӵ�
//                // ��ȡ[startIndex,i]��s�е��Ӵ�
//                string str = s.substr(startIndex, i - startIndex + 1);
//                path.push_back(str);
//            }
//            else {                                // ���ǻ��ģ�����
//                continue;
//            }
//            backtracking(s, i + 1); // Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
//            path.pop_back(); // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
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

