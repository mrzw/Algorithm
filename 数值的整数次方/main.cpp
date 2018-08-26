#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0) return 1;
        if(exponent==1) return base;
        bool negative = false;
        bool odd = false;
        if(exponent<0) {
            negative = true;
            exponent = -exponent;
        }
        double base1 = base;
        if(exponent%2!=0) {
            exponent -= 1;
            odd = true;
        }
        for(int i=1; i<exponent; i*=2) {
            base *= base;
        }
        if(odd) base *= base1;
        return (negative==true)?1/base:base;
    }
};
