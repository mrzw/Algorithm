
// 动态规划 递推公式是DP[i] = max{DP[i-1] + A[i],A[i]}
int maxSubArray(int A[], int n) {
    int curSum = 0;
    int maxSum = A[0];
    for(int j = 0; j < n; j++) {
        if(curSum >= 0)  {
            curSum += A[j];
        }
        else {
            curSum = A[j];
        }
        if(curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}
