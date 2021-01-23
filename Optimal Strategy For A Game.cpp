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

	int dp[n][n];

	for (int i = 0; i < n; i++)

	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = 0;
		}
		//cout << endl;
	}

	for (int g = 0; g < n; g++)
	{
		for (int i = 0,  j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = a[i];
			}
			else if (g == 1)
			{
				dp[i][j] = max(a[i], a[j]);
			}
			else
			{
				int op1 = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
				int op2 = a[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
				dp[i][j] = max(op1, op2);
			}
		}
	}


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





	/*for (int i = 0; i < n; i++)

	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[0][n - 1];

}
