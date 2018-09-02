#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len<=0) return "";
        sort(numbers.begin(),numbers.end(),[](int a, int b){
            string str1 = to_string(a)+to_string(b);
            string str2 = to_string(b)+to_string(a);
            return str1 < str2;
        });
        string res;
        for(auto i:numbers) {
            res += to_string(i);
        }
        return res;
    }
};

int main() {
    vector<int> input{3,32,321};
    Solution s;
    cout << s.PrintMinNumber(input) << endl;
    return 0;
}
