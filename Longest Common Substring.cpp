# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str, pat;
	cin >> str >> pat;



	int n = str.length();
	int m = pat.length();
	//int pat_len = pat.length();

	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 0; i <= m; i++)
	{
		dp[0][i] = 0;
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = 0;

			if (str[i - 1] == pat[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			maxi = max(maxi, dp[i][j]);
		}
	}

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << maxi;






}
