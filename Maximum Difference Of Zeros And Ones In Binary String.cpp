# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string s;
	cin >> s;
	int csum = 0;

	int val;
	int n = s.length();
	int ans = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		char ch = s[i];
		if (ch == '0')
		{
			val = 1;
		}
		else
		{
			val = -1;
		}
		if (csum > 0)
		{
			csum += val;
		}
		else
		{
			csum = val;
		}

		if (csum > ans)
		{
			ans = csum;
		}

	}

	cout << ans;


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
