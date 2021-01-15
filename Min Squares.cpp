# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	int n;
	cin >> n;

	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int mini = INT_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			int rem = i - j * j;
			mini = min(mini, dp[rem]);
		}
		dp[i] = mini + 1;
	}


	cout << dp[n];


}
