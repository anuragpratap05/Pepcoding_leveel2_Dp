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

	int dp[n];
	dp[0] = 0;
	dp[1] = 0;
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		dp[i] = 0;
		if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
		{
			dp[i] = dp[i - 1] + 1;
			ans += dp[i];
		}
	}
	//cout << dp[n];
	cout << ans;
	/*for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}*/



	/*for (auto vec : *v[0])
	{
		for (auto ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl;
	}*/
	/*for (int i = 0; i < v[5].size(); i++)
	{
		cout << v[5][i] << " ";
	}*/



	//int maping[][10] = {{0, 8}, {1, 4, 2}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 7, 5}, {2, 4, 5, 6, 8}, {3, 6, 9, 5}, {4, 7, 8}, {5, 7, 8, 9, 0}, {8, 9, 6}};

	//cout << maping[2][3] << " " << maping[0][1];





	/*for (int i = 0; i <= eggs; i++)

	{
		for (int j = 0; j <= floor; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << dp[eggs][floor];

}
