# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2 ;
	int c1, c2;
	cin >> c1 >> c2;



	int n = s1.length();
	int m = s2.length();
	//int m = pat.length();
	//int pat_len = pat.length();

	int dp[n + 1][m + 1];

	for (int i = n; i >= 0; i--)
	{
		for (int j = m; j >= 0; j--)
		{
			if (i == n or j == m)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (s1[i] == s2[j])
				{
					dp[i][j] = dp[i + 1][j + 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}
	}
	//cout << dp[0][0];

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << maxi;

	int lcs = dp[0][0];
	int l1 = n - lcs;
	int l2 = m - lcs;
	int ans = c1 * l1 + c2 * l2;
	cout << ans;







}
