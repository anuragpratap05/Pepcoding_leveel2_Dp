# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string s;
	cin >> s;

	int n = s.length();
	map<char, int> m;
	long dp[n + 1];
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
	
	cout << dp[n]-1;





}
