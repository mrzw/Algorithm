#include <iostream>
using namespace std;

int gcd(int a, int b) {  // 求a和b的最大公约数
	int t;
	if(a < b) {
		int temp = a;
		a = b;
		b = temp;
		t = a;
	} else {
		t = b;
	}
	while(b != 0) {
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int gcd(int a, int b) { // 默认a>b
	if(b==0) return a;
	gcd(b,a%b));
}
int lcm(int a, int b) {   // 求a和b的最小公倍数 = a*b/最大公约数
	int gongyueshu = gcd(a, b);
	return a*b/gongyueshu;
}

int main(int argc, char *argv[]) {
	int m = 12, n = 8;
	cout << gcd(m,n) << endl;
	cout << lcm(m,n) << endl;
	return 0;
}

