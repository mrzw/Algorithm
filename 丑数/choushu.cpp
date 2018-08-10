//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 以空间换时间，da存储已保存的丑数，下一个丑数肯定是他们之中某个丑数乘以2,3,5中最小的数。index2 index3 index5分别表示da中某个丑数的下标使其乘以2,3,5时超过当前保存的最大丑数。
    int GetUglyNumber_Solution(int index) {
        if(index<=1) return index;
        vector<int> da(index);
        da[0] = 1;
        int next_index = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        while(next_index<index) {
            int minDa = min(2*da[index2],3*da[index3]);
            minDa = min(minDa, 5*da[index5]);
            da[next_index] = minDa;
            while(2*da[index2]<=da[next_index]) ++index2;
            while(3*da[index3]<=da[next_index]) ++index3;
            while(5*da[index5]<=da[next_index]) ++index5;
            ++next_index;
        }
        return da[next_index-1];
    }
};
