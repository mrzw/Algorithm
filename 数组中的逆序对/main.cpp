#include <iostream>
#include <vector>
using namespace std;

// 基于归并思想，先统计子数组内部的逆序对数目，再统计两个相邻子数组间逆序对数目。
int InverseCore(vector<int>& data, vector<int>& copy, int left, int right) {
    if(left>=right) return 0;
    int midLen = (right-left)/2;
    // copy是排序好的数组,每次比较实际是排序好的数组
    int leftCount = InverseCore(copy, data, left, left+midLen);
    int rightCount = InverseCore(copy, data, left+midLen+1, right);

    int i = left + midLen;
    int j = right;
    int indexCopy = right;
    int count = 0;
    // 左半部分 (left,left+midLen) 右半部分 (left+midLen+1,right)
    while(i>=left && j>=left+midLen+1) {
        if(data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            count += j-(left+midLen+1)+1;
        } else {
            copy[indexCopy--] = data[j--];
        }
    }
    while(i>=left) {
        copy[indexCopy--] = data[i--];
    }
    while(j>=left+midLen+1) {
        copy[indexCopy--] = data[j--];
    }
    return count+leftCount+rightCount;
}
int InversePairs(vector<int> data) {
    int len = data.size();
    if(len<=1) return 0;
    vector<int> data1(data.begin(),data.end());
    return InverseCore(data,data1,0,len-1);
}

int main() {
    vector<int> a = {7,5,6,4};
    cout << InversePairs(a) << endl;
}

