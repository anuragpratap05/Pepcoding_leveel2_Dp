# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string src, tar;
	cin >> src >> tar ;



	int n = tar.length();
	int m = src.length();
	//int m = pat.length();
	//int pat_len = pat.length();

	int dp[n + 1][m + 1];

	for (int i = n; i >= 0; i--)
	{
		for (int j = m; j >= 0; j--)
		{
			if (i == n and j == m)
			{
				dp[i][j] = 1;
			}
			else if (i == n)
			{
				dp[i][j] = 1;
			}
			else if (j == m)
			{
				dp[i][j] = 0;
			}
			else
			{
				char c1 = tar[i];
				char c2 = src[j];

				if (c1 == c2)
				{
					dp[i][j] = dp[i][j + 1] + dp[i + 1][j + 1];
				}
				else
				{
					dp[i][j] = dp[i][j + 1];
				}
			}
		}
	}
	cout << dp[0][0];

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << maxi;








}
