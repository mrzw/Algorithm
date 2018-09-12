#include <iostream>
#include <cstring>

using namespace std;
// https://www.cnblogs.com/GodA/p/5237061.html
// 二维矩阵的最大子矩阵和，将其转换成一维矩阵的最大子矩阵和
// 一维矩阵的最大子矩阵和 dp[i]表示以i为结尾的最大子矩阵和 dp[i] = max(dp[i-1]+a[i],a[i])

int maxsub(int a[], int n) { // 一维矩阵的最大子矩阵和
    int maxdata = 0,b = 0;
    for(int i=0; i<n; ++i) {
        if(b>0)
            b += a[i];
        else
            b = a[i];
        if(b>maxdata)
            maxdata = b;
    }
    return maxdata;
}
int main() {
    int n,i,j,k,maxsubrec,maxsubarr;
    int dp[101][101],arr[101];
    while(cin>>n) {
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
                cin >> dp[i][j];
        maxsubrec = 0;
        for(i=0; i<n; ++i) {
            memset(arr,0,sizeof(arr));
            for(j=i; j<n; ++j) {
                for(k=0; k<n; ++k) {
                    // j=i arr[k] = dp[i][k];
                    // j=i+1 arr[k] = dp[i][k]+dp[i+1][k]; ...
                    // 将dp二维最大子矩阵和转换成arr一维最大子矩阵和
                    arr[k] += dp[j][k];
                }
                maxsubarr = maxsub(arr,n);
                if(maxsubarr>maxsubrec)
                    maxsubrec = maxsubarr;
            }
        }
        cout << maxsubrec << endl;
    }
    return 0;
}
