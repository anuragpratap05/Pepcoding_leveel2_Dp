# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string s;
	cin >> s;

	int n = s.length();
	int dp[n][n] ;



	for (int g = 0; g < n; g++)
	{
		for (int i = 0, j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = 1;
			}
			else if (g == 1)
			{
				dp[i][j] = s[i] == s[j] ? 2 : 1;
			}
			else
			{
				if (s[i] == s[j])
				{
					dp[i][j] = 2 + dp[i + 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
				}
			}
		}
	}
	cout << dp[0][n - 1];



}
