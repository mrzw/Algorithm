// https://blog.csdn.net/u012102306/article/details/53184446
// c[i,j] = 0 (i=0 or j=0)
// c[i,j] = c[i-1,j-1]+1 (xi=yj)
// c[i,j] = max(c[i,j-1],c[i-1,j]) (xi!=yj)
int dp[1000][1000];

int num(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	for(int i=0; i<=len1; ++i) {
		for(int j=0; j<=len2; ++j) {
			if(i==0 || j==0) dp[i][j] = 0;
			else if(str1[i-1]==str2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			} else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}
