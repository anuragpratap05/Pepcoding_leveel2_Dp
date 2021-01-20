# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;

class trplet
{
public:
	int i;
	int j;
	//int val;
	string psf;
	trplet(int i, int j,  string psf)
	{
		this->i = i;
		this->j = j;
		//this->val = val;
		this->psf = psf;
	}
};

int main()
{


	int n;
	cin >> n;
	int a[n ];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dp[n - 1][n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			dp[i][j] = 0;
		}

	}
	for (int g = 0; g < n - 1; g++)
	{
		for (int i = 0, j = g; j < n - 1; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = 0;
			}
			else if (g == 1)
			{
				dp[i][j] = a[i] * a[j] * a[j + 1];
				//cout << i << " " << j << " " << dp[i][j] << endl;
			}
			else
			{
				int mini = INT_MAX;
				for (int k = i; k < j; k++)
				{
					int left = dp[i][k];
					int right = dp[k + 1][j];
					int m = a[i] * a[k + 1] * a[j + 1];
					int total = left + right + m;
					mini = min(mini, total);
				}
				dp[i][j] = mini;
			}
		}
	}
	/*for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[0][n - 2];









	/*for (int i = 0; i <= n; i++)
	{
		cout << dp[i] << " ";
	}*/

	/*if (dp[n][tar])
	{
		cout << "true" << endl;

		queue< trplet*> q;

		trplet *t = new trplet(n, tar, "");
		q.push(t);

		while (!q.empty())
		{
			trplet* f = q.front();
			q.pop();

			int i = f->i;
			int j = f->j;
			string psf = f->psf;

			if (i == 0 or  j == 0)
			{
				cout << psf << endl;
			}
			else
			{
				if (dp[i - 1][j])
				{
					trplet* x = new trplet(i - 1, j, psf);
					q.push(x);
				}

				if (j >= a[i - 1])
				{
					if (dp[i - 1][j - a[i - 1]])
					{
						trplet* y = new trplet(i - 1, j - a[i - 1],  to_string(i - 1) + psf);
						q.push(y);
					}
				}
			}
		}
	}
	else
	{
		cout << "false";
	}*/

}
