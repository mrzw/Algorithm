// https://blog.csdn.net/u012102306/article/details/53184446
// 动态规划 c[i][j] = 0 (i=0 or j=0)
// c[i][j]表示str1,str2分别以i,j结尾的最长公共子串
// c[i][j] = c[i-1,j-1]+1 (xi=yj)
// c[i][j] = 0 (xi!=yj)
int dp[1000][1000];

int num(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	int result=0;
	for(int i=0; i<=len1; ++i) {
		for(int j=0; j<=len2; ++j) {
			if(i==0 || j==0) dp[i][j] = 0;
			else if(str1[i]==str2[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
				result = max(dp[i][j], result);
			} else dp[i][j] = 0;
		}
	}
	return result;
}
