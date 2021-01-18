# Pepcoding_leveel2_Dp
#include<bits/stdc++.h>
using namespace std;


int main()
{

	string str, pat;
	cin >> str >> pat;



	int str_len = str.length();
	int pat_len = pat.length();

	bool dp[pat_len + 1][str_len + 1];

	for (int i = 0; i <= pat_len; i++)
	{
		for (int j = 0; j <= str_len; j++)
		{
			if (i == 0 and j == 0)
			{
				dp[i][j] = true;
			}
			else if (i == 0)
			{
				dp[i][j] = false;
			}
			else if (j == 0)
			{

				char pc = pat[i - 1];
				if (pc == '*')
				{
					dp[i][j] = dp[i - 2][j];
				}
				else
				{
					dp[i][j] = false;
				}
			}
			else
			{
				char pc = pat[i - 1];
				char sc = str[j - 1];
				if (pc == '.')
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (pc == sc)
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (pc == '*')
				{
					dp[i][j] = dp[i - 2][j];
					char pslc = pat[i - 2];

					if (pslc == sc or pslc == '.')
					{
						dp[i][j] = dp[i][j] || dp[i][j - 1];
					}
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

	if (dp[pat_len][str_len ])
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}


}
