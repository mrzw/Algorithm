#include <iostream>
#include <stack>

// 构造一个辅助栈，存原始数组的最小值
class Solution {
public:
    void push(int value) {
        data.push(value);
        if(minData.size()==0 || value < minData.top())
            minData.push(value);
        else
            minData.push(minData.top());
    }
    void pop() {
        if(data.size()==0 || minData.size()==0) return;
        data.pop();
        minData.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minData.top();
    }
public:
    stack<int> data;
    stack<int> minData;
};
