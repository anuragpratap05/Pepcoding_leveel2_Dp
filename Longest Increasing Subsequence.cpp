#include<bits/stdc++.h>
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
				maxi = max(maxi, dp[j]);
			}
		}
		dp[i] = maxi + 1;
		if (dp[i] > ovmax)
		{
			ovmax = dp[i];
		}
	}



	cout << ovmax;

}
