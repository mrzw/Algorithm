// https://www.2cto.com/kf/201411/350991.html
// 返回str1->str2最小操作次数，只可以删除，添加，修改一个字符。
/**
 *x,y:是字符串
 *动态规划最小编辑距离,
 *dp[i][j]表示取x的前i个字符和y的前j个字符操作的最小次数。
 *dp[0][j]=j:取x的前0个字符和y的前j个字符操作的
 *最小次数为(j),只能添加到x
 *
 *dp[i][0]=i:取x的前i个字符和y的前0个字符操作的
 *最小次数为(i),只能删除x
 *
 *dp[i][j]只有三种来源:
 *1、由x删除一个字符得到:dp[i][j]=dp[i-1][j]+1;
 *2、由x添加一个字符得到(相当于y删除一个):dp[i][j]=dp[i][j-1]+1;
 *3、由转换得到:if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
 *              else dp[i][j]=d[i-1][j-1]+1;
 *dp[i][j]取到三种操作中的最小次数:
 *str1[i-1]==str2[j-1]?ok=0:ok=1;
 *转化方程:
 *dp[i][j]=min(dp[i-1][j-1]+ok,dp[i-1][j]+1,dp[i][j-1]+1);
 */
int num(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	int dp[2000][2000];
	for(int i=0; i<=len1; ++i) {
		dp[i][0] = i;
	}
	for(int j=0; j<=len2; ++j) {
		dp[0][j] = j;
	}
	for(int i=1; i<=len1; ++i) {
		for(int j=1; j<=len2; ++j) {
			if(str1[i-1]==str2[i-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			int min = dp[i][j];
			if(min>dp[i-1][j]+1) min = dp[i-1][j]+1;
			if(min>dp[i][j-1]+1) min = dp[i][j-1]+1;
			dp[i][j] = min;
		}
	}
	return dp[len1][len2];
}
