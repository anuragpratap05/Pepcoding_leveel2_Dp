# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string s;
	cin >> s;

	int n = s.length();
	bool dp[n][n] ;


	int len = 0;
	for (int g = 0; g < n; g++)
	{
		for (int i = 0, j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = true;
			}
			else if (g == 1)
			{
				if (s[i] == s[j]) dp[i][j] = true;
				else
					dp[i][j] = false;
			}
			else
			{
				if (s[i] == s[j] and dp[i + 1][j - 1] == true)
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = false;
				}
			}
			if (dp[i][j]) len = g + 1;
		}
	}
	cout << len;



}
