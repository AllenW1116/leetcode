#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include<stack>
using namespace std;

//Given an array of integers arr of even length nand an integer k.
//
//We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
//
//Return True If you can find a way to do that or False otherwise.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod(k);
        for (int i = 0; i < arr.size();i++) {
            mod[(arr[i] % k + k) % k]++;
        }
        for (int i = 1; i + i < k; i++) {
            if (mod[i] != mod[k - i]) {
                return false;
            }
        }
        return mod[0] % 2 == 0;
    }
};



//
//��֪ʶ��1����ͳһ��������ȡ�������
//xk = (x % k + k) % k
//x=11 k=2��xk=1��
//x=-11 k=2��xk=1��
//
//��֪ʶ��2����vector�Ĵ��ι��졣
//vector<int> vec(3);
//��vec����ĳ���Ϊ3��
//
//��֪ʶ��3����c++�м�������ĳ���
//length=sizeof��Arr��/sizeof��Arr[0]��