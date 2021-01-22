# Pepcoding_leveel2_Dp
#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int dp[n + 1][10];

	vector<vector<int>> v;
	v.push_back({0, 8});
	v.push_back({1, 4, 2});
	v.push_back({1, 2, 3, 5});
	v.push_back({2, 3, 6});
	v.push_back({1, 4, 7, 5});
	v.push_back({2, 4, 5, 6, 8});
	v.push_back({3, 6, 9, 5});
	v.push_back({4, 7, 8});
	v.push_back({5, 7, 8, 9, 0});
	v.push_back({8, 9, 6});

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



	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0)
			{
				dp[i][j] = 0;
			}
			else if (i == 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = 0;
				for (int idx = 0; idx < v[j].size(); idx++)
				{
					int val = v[j][idx];
					dp[i][j] += dp[i - 1][val];
				}
			}
		}
	}

	/*for (int i = 0; i <= n; i++)

	{
		for (int j = 0; j < 10; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}
	cout << sum;
}
