#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res = -1;
        if(!stack2.empty()) {
            res = stack2.top();
            stack2.pop();
        } else if(!stack1.empty()) {
            while(!stack1.empty()) {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            res = stack2.top();
            stack2.pop();
        } else return -1;
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
