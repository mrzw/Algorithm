int add(int num1, int num2) {
	int sum=0,jinwei=0;
	while(num2!=0) {
		sum = num1^num2; //不考虑进位相加 0+0=0 0+1=1 1+0=1 1+1=0
		jinwei = (num1&num2)<<1; //考虑进位 0+0=0 0+1=0 1+0=0 1+1=1
		num1 = sum;
		num2 = jinwei;
	}
	return num1;
}
