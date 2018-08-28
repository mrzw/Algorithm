// https://www.jianshu.com/p/ae71823744b3
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int F[1000];
int pre[1000];
// 最长递增子序列长度（动态规划o(n2)）
// F[i]表示以i为结尾的最长子序列长度
// 当 arr[i] > arr[j]，lis[i] = max{lis[j]}+1 ；其中，j 的取值范围为：0,1...i-1
// 当 arr[i] > arr[j]，pre[i]表示i为结尾的前驱结点
int maxSubIncreaseArray(const vector<int>& da, int length) {
    // 初始条件
    for(int i=0; i<length; ++i) {
        F[i] = 1;
        pre[i] = i;
    }
    for(int i=1; i<length; ++i) {
        for(int j=0; j<i; ++j) {
            if(da[i]>da[j] && F[i]<F[j]+1) {
                F[i] = F[j]+1;
                pre[i] = j;
            }
        }
    }
    int maxLength = 0;
    int maxIndex = 0;
    for(int i=0; i<length; ++i) {
        if(F[i]>maxLength) {
            maxLength = F[i];
            maxIndex = i;
        }
    }
    stack<int> st;
    while(maxIndex!=pre[maxIndex]) {
        st.push(da[maxIndex]);
        maxIndex = pre[maxIndex];
    }
    if(maxIndex==pre[maxIndex]) {
        st.push(da[maxIndex]);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return maxLength;
}

int main() {
    vector<int> a{35, 36, 39, 3, 15, 27, 6, 42};
    cout << maxSubIncreaseArray(a,a.size()) << endl;
    return 0;
}
