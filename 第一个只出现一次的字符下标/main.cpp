#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 基于hashmap,key存储的是字符，value存储的是字符出现的次数
    int FirstNotRepeatingChar(string str) {
        if(str.size()<=0) return -1;
        unordered_map<char,int> up;
        for(int i=0; i<str.size(); ++i) {
            up[str[i]]++;
        }
        for(int i=0; i<str.size(); ++i) {
            if(up[str[i]]==1) return i;
        }
        return -1;
    }
};
