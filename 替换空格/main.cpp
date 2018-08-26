#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
public:
	// 第一次遍历空格个数，然后从后往前赋值
    void replaceSpace(char *str,int length) {
        char *p = str;
        int lengthOrigin = strlen(str);
        int numSpace = 0;
        while(*p!='\0') {
            if(*p==' ')
                ++numSpace;
            ++p;
        }
        int newLength = lengthOrigin + numSpace*2;
        if(newLength > length) return;
        int index1 = lengthOrigin;
        int index2 = newLength;
        while(index1>=0 && index2>=0 && index1<index2) {
            if(str[index1]==' ') {
                str[index2--] = '0';
                str[index2--] = '2';
                str[index2--] = '%';
                --index1;
            } else {
                str[index2--] = str[index1--];
            }
        }
    }
};

int main() {
    Solution s;
    char str[20] = "hello world";
    s.replaceSpace(str, 20);
    cout << str << endl;
}
