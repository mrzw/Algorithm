#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len1 = pushV.size();
        int len2 = popV.size();
        if(len1==0 && len2==0) return true;
        if(len1!=len2) return false;
        stack<int> tmpstack;
        for(int i=0,j=0; i<len1; ++i) {
            tmpstack.push(pushV[i]);
            while(j<len1 && popV[j]==tmpstack.top()) {
                tmpstack.pop();
                ++j;
            }
        }
        return tmpstack.empty();
    }
};
