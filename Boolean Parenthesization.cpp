# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{


	string str, pat;
	cin >> str >> pat;



	int n = str.length();
	int m = pat.length();
	//int pat_len = pat.length();

	int dpt  [n][n];
	int dpf [n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dpt[i][j] = 0;
			dpf[i][j] = 0;
		}
	}

	for (int g = 0; g < n; g++)
	{
		for (int i = 0, j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				if (str[i] == 'T')
				{
					dpt[i][j] = 1;
					dpf[i][j] = 0;
				}
				else
				{
					dpt[i][j] = 0;
					dpf[i][j] = 1;
				}
			}
			else
			{
				for (int k = i; k < j; k++)
				{
					int ltc = dpt[i][k];
					int rtc = dpt[k + 1][j];
					int lfc = dpf[i][k];
					int rfc = dpf[k + 1][j];

					if (pat[k] == '&')
					{
						dpt[i][j] += ltc * rtc;
						dpf[i][j] += lfc * rfc + ltc * rfc + lfc * rtc;
					}
					else if (pat[k] == '|')
					{
						dpt[i][j] += ltc * rtc + ltc * rfc + lfc * rtc;
						dpf[i][j] += lfc * rfc;
					}
					else
					{
						dpt[i][j] += lfc * rtc + ltc * rfc;
						dpf[i][j] += ltc * rtc + lfc * rfc;
					}
				}
			}
		}
	}


	cout << dpt[0][n - 1];

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dpt[i][j] << " ";
		}
		cout << endl;
	}*/






}
