#include <iostream>
#include <cstring>

using namespace std;
// 最长无重复子串长度
// https://blog.csdn.net/u013575812/article/details/50198905
int longestSubstring(string A, int n)
{
    int mp[256]; // 存储某个字符最近出现的位置
    memset(mp, -1, sizeof(mp));
    int pre = -1, maxSubLen = 0;
    for (int i = 0; i < n; ++i)
    {
        pre = max(pre, mp[A[i]]); // pre+1表示以str[i]字符结尾的情况下最长无重复子串开始的位置
        maxSubLen = max(maxSubLen, i - pre); // i-pre表示以str[i]字符结尾的情况下无重复子串的长度
        mp[A[i]] = i;
    }
    return maxSubLen;
}

int main(void) {
    string str = "aabcdb";
    cout << longestSubstring(str, str.size()) << endl;
    return 0;
}
