#include <iostream>
#include <vector>

using namespace std;

int res[1000];

// Ksum https://www.jianshu.com/p/3d1791cfba53
/*
 * 考虑是否取第n个数，问题可以转化为前n-1个数和为sum-a[n-1]的问题，也可以转化为后n-1个数的求和问题。使用递归思想解决。
 * 如果取第n个数，即求得前n-1个数满足和为sum-a[n-1]的问题
 * 如果不取第n个数，即求得前n-1个数满足和为sum的问题
 * */
void sumofKNumber(vector<int>& da, int len, int sum, int& k) {
    if(len<=0 || sum<=0) return;
    if(sum==da[len-1]) {
        for(int i=0; i<k; ++i)
            cout << res[i] << " ";
        cout << da[len-1] << endl;  //特别注意，输出时，该元素还未加入数组
    }
//  考虑是否取第n个数
    res[k++] = da[len-1];
    sumofKNumber(da,len-1,sum-da[len-1],k);
    k--;
    sumofKNumber(da,len-1,sum,k);
}

int main() {
    vector<int> a{1,3,5,4,2,2,1,1};
    int k=0;
    sumofKNumber(a,a.size(),5,k);
    return 0;
}
