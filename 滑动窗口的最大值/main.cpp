#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // qu存储的是下标，当当前的数比num中以qu为下标的数大，就从后往前删除。
    // 当当前数的下标与qu第一个数差距大于等于窗口大小时，将qu第一个数删除。
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int len = num.size();
        if(len<size || size==0) return vector<int>();
        vector<int> res;
        deque<int> qu;
        for(int i=0; i<size; ++i) {
            while(!qu.empty() && num[i]>=num[qu.back()])
                qu.pop_back();
            qu.push_back(i);
        }
        for(int i=size; i<len; ++i) {
            res.push_back(num[qu.front()]);
            while(!qu.empty() && num[i]>=num[qu.back()])
                qu.pop_back();
            if(!qu.empty() && i-qu.front()>=size)
                qu.pop_front();
            qu.push_back(i);
        }
        res.push_back(num[qu.front()]);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {2,3,4,2,6,2,5,1};
    vector<int> res = s.maxInWindows(a,3);
    for(auto i:res) cout << i << " ";
    return 0;
}


