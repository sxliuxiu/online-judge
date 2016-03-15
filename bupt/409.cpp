#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;
//本题算法已经正确，但是n = 100时，已经超过64位整数，不能在C++中直接表示
//如果需要使用，应当考虑使用Java求解，因为Java有大整数类
int main() {
	long long dp[101][101];
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i = 2; i < 101; i++) {
		for(int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] * j + dp[i - 1][j] * j;
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		long long res = 0;
		for(int j = 1; j <= n; j++)
			res += dp[n][j];
		printf("%lld\n", res);
	}
	return 0;
}
