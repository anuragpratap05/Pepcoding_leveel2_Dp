# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string str;
	cin >> str;



	int str_len = str.length();
	//int pat_len = pat.length();



	bool dp[str_len][str_len];
	for (int i = 0; i < str_len; i++)
	{
		for (int j = 0; j < str_len; j++)
		{
			dp[i][j] = false;;
		}
		//cout << endl;
	}

	for (int g = 0; g < str_len; g++)
	{
		for (int i = 0, j = g; j < str_len; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = true;
			}
			else if (g == 1)
			{
				if (str[i] == str[j])
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = false;
				}
			}
			else
			{
				if (str[i] == str[j] and dp[i + 1][j - 1])
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = false;
				}
			}
		}
	}


	/*for (int i = 0; i < str_len; i++)
		{
			for (int j = 0; j < str_len; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
	int strg[str_len];
	strg[0] = 0;
	for (int j = 1; j < str_len; j++)
	{
		if (dp[0][j])
		{
			strg[j] = 0;
		}
		else
		{
			int mini = INT_MAX;
			for (int k = j; k >= 1; k--)
			{
				if (dp[k][j])
				{
					mini = min(mini, strg[k - 1]);
				}
			}
			strg[j] = mini + 1;
		}
	}
	/*for (int i = 0; i < str_len; i++)
	{
		cout << strg[i] << " ";
	}*/
	cout << strg[str_len - 1];




}
