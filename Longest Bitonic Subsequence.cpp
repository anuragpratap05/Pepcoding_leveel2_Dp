# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ovmax = 0;
	int dp[n];

	for (int i = 0; i < n; i++)
	{
		int maxi = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				maxi = max(maxi, dp[j] );
			}
		}
		dp[i] = maxi + 1;

	}
	int dplds[n];
	for (int i = n - 1; i >= 0; i--)
	{
		int maxi2 = 0;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[i])
			{
				maxi2 = max(maxi2, dplds[j]);
			}
		}
		dplds[i] = maxi2 + 1;
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << dplds[i] << " ";
	}*/

	for (int i = 0; i < n; i++)
	{
		ovmax = max(ovmax, dp[i] + dplds[i]);
	}

	cout << ovmax - 1;


}
