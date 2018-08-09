#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int partion(vector<int> &da, int start, int end) {
        int pivot = da[start];
        while(start<end) {
            while(start<end && da[end]>=pivot) --end;
            da[start] = da[end];
            while(start<end && da[start]<=pivot) ++start;
            da[end] = da[start];
        }
        da[start] = pivot;
        return start;
    }
    // 基于快排分区思想
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len==0) return 0;
        int midden = len/2;
        int start = 0, end = len-1;
        int index = partion(numbers, start, end);
        while(index!=midden) {
            if(index>midden) {
                end = index-1;
                index = partion(numbers, start, end);
            } else {
                start = index+1;
                index = partion(numbers, start, end);
            }
        }
        int res = numbers[midden];
        if(!checkMoreThanHalf(numbers, res)) res = 0;
        return res;
    }
    bool checkMoreThanHalf(vector<int> &da, int k) {
        int len = da.size();
        int times = 0;
        for(int i=0; i<len; ++i) {
            if(da[i]==k) ++times;
        }
        if(times*2<=len) return false;
        else return true;
    }
};
