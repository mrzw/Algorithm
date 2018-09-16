#include <iostream>
#include <cmath>

using namespace std;
const int maxData = 1000000;
bool notprimeTable[maxData]; // true表示非素数,false表示素数
// 判断n是否为素数，只要试除到n的平方根就可以了，不必一直到n-1。
bool isPrime(int n) // n为素数返回true
{
    for(int i=2; i<=sqrt(n); ++i) {
        if(n%i==0)
            return false;
    }
    return true;
}

// 查表法，首先统计maxData内的素数
void init() {
    for(long long i=2; i<maxData; ++i) {
        if(!notprimeTable[i]) { // 如果是素数
            for(long long j=i*i; j<maxData; j+=i) {
                notprimeTable[j] = true;
            }
        }
    }
}
bool isPrime1(int n) {
    init();
    return !notprimeTable[n];
}

int main() {
    if(isPrime1(10)) {
        cout << "sushu" << endl;
    } else {
        cout << "feisushu" << endl;
    }
    return 0;
}
