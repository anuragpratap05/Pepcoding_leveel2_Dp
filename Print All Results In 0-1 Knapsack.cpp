# Pepcoding_leveel2_Dp
#include<bits/stdc++.h>
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
	int val[n];
	int wt[n];
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];

	}

	for (int i = 0; i < n; i++)
	{
		cin >> wt[i];
	}

	int cap;
	cin >> cap;

	int dp[n + 1][cap + 1];
	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tar; j++)
		{
			dp[i][j] = false;
		}
	}*/

	for (int i = 0; i <= cap; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= cap; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= wt[i - 1])
			{
				if (dp[i - 1][j - wt[i - 1]] + val[i - 1] > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j - wt[i - 1]] + val[i - 1];
				}
			}
		}
	}

	cout << dp[n][cap] << endl;
	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= cap; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	queue<trplet*> q;
	trplet* x = new trplet(n, cap, "");
	q.push(x);
	while (!q.empty())
	{
		trplet* f = q.front();
		q.pop();
		int i = f->i;
		int j = f->j;
		string psf = f->psf;

		if (i == 0 or j == 0)
		{
			cout << psf << endl;
		}
		else
		{
			int exc = dp[i - 1][j];
			if (exc == dp[i][j])
			{
				trplet* u = new trplet(i - 1, j, psf);
				q.push(u);
			}
			if (j >= wt[i - 1])
			{
				int inc = dp[i - 1][j - wt[i - 1]] + val[i - 1];
				if (inc == dp[i][j])
				{
					trplet* v = new trplet(i - 1, j - wt[i - 1],  to_string(i - 1) + +" "+psf);
					q.push(v);
				}
			}
		}
	}

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
