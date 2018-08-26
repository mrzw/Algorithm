#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 从右上角开始查询
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if(row<=0) return false;
        int col = array[0].size();
        int r = 0, c = col-1;
        while(r<=row-1 && c>=0) {
            if(array[r][c]==target)
                return true;
            else if(array[r][c]<target) {
                ++r;
            } else if(array[r][c]>target) {
                --c;
            }
        }
        return false;
    }
};
