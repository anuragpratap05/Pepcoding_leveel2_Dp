# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{

	string s1, s2;
	cin >> s1 >> s2;
	int m = s2.length();
	int n = s1.length();
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
	cout << dp[0][0];


}
