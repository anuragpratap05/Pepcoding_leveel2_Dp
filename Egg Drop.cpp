# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;
int main()
{


	int eggs, floor;
	cin >> eggs >> floor;

	int dp[eggs + 1][floor + 1];

	for (int i = 1; i <= eggs; i++)
	{
		for (int j = 0; j <= floor; j++)
		{

			if (i == 1)
			{
				dp[i][j] = j;
			}
			else if (j == 0)
			{
				dp[i][j] = 0;
			}
			else if (j == 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = 0;
				int mini = INT_MAX;
				for (int mj = j - 1, mi = 0; mj >= 0; mj--, mi++)
				{
					int v1 = dp[i][mj];
					int v2 = dp[i - 1][mi];
					int val = max(v1, v2);
					//cout << val << endl;
					mini = min(mini, val);
					//cout << mini << endl;

				}
				dp[i][j] = mini + 1;
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





	/*for (int i = 0; i <= eggs; i++)

	{
		for (int j = 0; j <= floor; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[eggs][floor];

}
