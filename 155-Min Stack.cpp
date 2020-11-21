#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({x,x});
        }
        else {
            st.push({ x , min(x,st.top().second) });
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};