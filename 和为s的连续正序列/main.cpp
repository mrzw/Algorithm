#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum<3) return vector<vector<int> >();
        int small = 1, big = 2;
        int midden = (1+sum)/2;
        vector<vector<int> > res;
        while(small<midden) {
            int cur = (small+big)*(big-small+1)/2;
            if(cur<sum) {
                ++big;
            } else if(cur>sum) {
                ++small;
            } else {
                vector<int> tmp;
                for(int i=small; i<=big; ++i) {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                ++small;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
