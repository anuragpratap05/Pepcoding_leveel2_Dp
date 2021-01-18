# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string str, pat;
	cin >> str >> pat;



	int str_len = str.length();
	int pat_len = pat.length();

	bool dp[pat_len + 1][str_len + 1];

	for (int i = pat_len; i >= 0; i--)
	{
		for (int j = str_len; j >= 0; j--)
		{
			if (i == pat_len and j == str_len)
			{
				dp[i][j] = true;
			}
			else if (i == pat_len)
			{
				dp[i][j] = false;
			}
			else if (j == str_len)
			{
				if (pat[i] == '*')
				{
					dp[i][j] = dp[i + 1][j];
				}
				else
				{
					dp[i][j] = false;
				}
			}
			else
			{
				if (pat[i ] == '?')
				{
					//cout << "aya ?" << endl;
					dp[i][j] = dp[i + 1][j + 1];
				}
				else if (pat[i ] == '*')
				{
					dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
				}
				else if (pat[i ] == str[j])
				{
					dp[i][j] = dp[i + 1][j + 1];
				}

				else
				{
					dp[i][j] = false;
				}
			}
		}
	}


	/*for (int i = 0; i <= pat_len; i++)
	{
		for (int j = 0; j <= str_len; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	if (dp[0][0])
	{
		cout << "true";
	}
	else
	{
	    cout<<"false";
	}


}
