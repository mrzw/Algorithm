#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        if(len<=0) return vector<int>();
        int left = 0, right = len-1;
        while(left<right) {
            if(array[left]+array[right]>sum) {
                --right;
            } else if(array[left]+array[right]<sum) {
                ++left;
            } else {
                return vector<int>{array[left],array[right]};
            }
        }
        return vector<int>();
    }
};

int main() {

    return 0;
}
