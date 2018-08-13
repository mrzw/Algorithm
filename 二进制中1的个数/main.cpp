#include <iostream>
using namespace std;

class Solution {
public:
	// n&(n-1)将从右往左最后一个1消掉
     int  NumberOf1(int n) {
         int count = 0;
         while(n) {
             n = n&(n-1);
             ++count;
         }
         return count;
     }
};
