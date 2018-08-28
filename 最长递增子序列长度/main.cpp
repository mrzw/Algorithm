#include <iostream>
#include <vector>

using namespace std;

int F[1000];
// 最长递增子序列长度（动态规划o(n2)）
// F[i]表示以i为结尾的最长子序列长度
// 当 arr[i] > arr[j]，lis[i] = max{lis[j]}+1 ；其中，j 的取值范围为：0,1...i-1
int maxSubIncreaseArray(vector<int>& da, int length) {
    // 初始条件
    for(int i=0; i<length; ++i) {
        F[i] = 1;
    }
    for(int i=1; i<length; ++i) {
        for(int j=0; j<i; ++j) {
            if(da[i]>da[j] && F[i]<F[j]+1) {
                F[i] = F[j]+1;
            }
        }
    }
    int maxLength = 0;
    for(int i=0; i<length; ++i) {
        if(F[i]>maxLength)
            maxLength = F[i];
    }
    return maxLength;
}

int main() {
    vector<int> a{3,1,4,1,5,9,2,6,5};
    cout << maxSubIncreaseArray(a,a.size()) << endl;
    return 0;
}


