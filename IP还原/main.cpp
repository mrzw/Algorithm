#include <iostream>
#include <vector>
using namespace std;
// IP还原
// https://www.cnblogs.com/grandyang/p/4305572.html

// 用k来表示当前还需要分的段数，如果k = 0，则表示三个点已经加入完成，四段已经形成，若这时字符串刚好为空，
// 则将当前分好的结果保存。若k != 0, 则对于每一段，我们分别用一位，两位，三位来尝试，分别判断其合不合法，
// 如果合法，则调用递归继续分剩下的字符串，最终和求出所有合法组合
bool isValid(string s) {
    if(s.size()>1 && s[0]=='0')
        return false;
    int res = atoi(s.c_str());
    if(res>=0 && res<=255)
        return true;
    else
        return false;
}
void restore(string s, int k, string out, vector<string>& res) {
    if(k==0) {
        if(s.empty())
            res.push_back(out);
    } else {
        for(int i=1; i<=3; ++i) {
            if(s.size()>=i && isValid(s.substr(0,i))) {
                if(k==1) {
                    restore(s.substr(i),k-1,out+s.substr(0,i),res);
                } else {
                    restore(s.substr(i),k-1,out+s.substr(0,i)+".",res);
                }
            }
        }
    }
}
vector<string> restoreIp(string s) {
    vector<string> res;
    restore(s,4,"",res);
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<string> res = restoreIp(s);
    for(auto &i:res)
        cout << i << endl;
    return 0;
}
