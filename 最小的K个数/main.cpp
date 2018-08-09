#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 利用大顶堆，每次与堆顶比较，当遇到比堆顶小的时候，将堆顶替换并维护大顶堆
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if(len<=0 || k>len || k<=0) return vector<int>();
        vector<int> res(input.begin(), input.begin()+k);
        for(int i=k; i<len; ++i) {
            if(input[i]<res[0]) {
                pop_heap(res.begin(), res.end());
                res.pop_back();
                res.push_back(input[i]);
                push_heap(res.begin(),res.end());
            }
        }
        sort_heap(res.begin(),res.end());
        return res;
    }
};
