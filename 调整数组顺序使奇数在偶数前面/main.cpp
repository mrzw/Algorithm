#include <iostream>
using namespace std;

class Solution {
public:
	// 从前往后遍历，遇到偶数先删除再插入到尾部
     void reOrderArray(vector<int> &array) {
         vector<int>::iterator even = array.begin();
         int size = array.size();
         while (size--)
         {
             if (*even % 2 == 0)
             {
                 int tmp = *even;
                 even = array.erase(even);
                 array.push_back(tmp);
             }
             else
                 even++;
         }
     }
};
