# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string s;
	cin >> s;

	int n = s.length();

	int prev[n];
	map<char, int> m;

	for (int i = 0; i < n; i++)
	{
		char ch = s[i];

		if ( m.find(ch) != m.end() )
		{
			prev[i] = m[ch];
		}
		else
		{
			prev[i] = -1;
		}
		m[ch] = i;
	}
	m.clear();
	int next[n];
	for (int i = n - 1; i >= 0; i--)
	{
		char ch = s[i];

		if ( m.find(ch) != m.end() )
		{
			next[i] = m[ch];
		}
		else
		{
			next[i] = -1;
		}
		m[ch] = i;
	}


	/*for (int i = 0; i < n; i++)
	{
		cout << prev[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << next[i] << " ";
	}*/

	int dp[n][n];
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
				dp[i][j] = 2;
			}
			else
			{
				char sc = s[i];
				char ec = s[j];
				if (sc != ec)
				{
					dp[i][j] = dp[i + 1][j] + dp[i ][j - 1] - dp[i + 1][j - 1];
				}
				else
				{
					int n = next[i];
					int p = prev[j];

					if (n > p)
					{
						dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
					}
					else if (n == p)
					{
						dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
					}
					else
					{
						dp[i][j] = 2 * dp[i + 1][j - 1] - dp[n + 1][p - 1];
					}
				}
			}
		}
	}
	/*int dp[n + 1];
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1];
		char ch = s[i - 1];
		if (m[ch])
		{
			dp[i] = dp[i] - dp[m[ch] - 1];
		}
		m[ch] = i;

	}

	cout << dp[n];*/
	cout << dp[0][n - 1];




}
