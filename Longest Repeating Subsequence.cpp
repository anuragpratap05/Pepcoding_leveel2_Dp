# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str ;



	int n = str.length();
	//int m = pat.length();
	//int pat_len = pat.length();

	int dp[n + 1][n + 1];

	for (int i = n; i >= 0; i--)
	{
		for (int j = n; j >= 0; j--)
		{
			if (i == n or j == n)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (str[i] == str[j] and i != j)
				{
					dp[i][j] = dp[i + 1][j + 1] + 1;
					//cout << str[i] << " " << str[j] << endl;
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
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
