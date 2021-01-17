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
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	int a[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int dp[n][m];

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == n - 1 )
			{
				dp[i][j] = a[i][j] + dp[i][j + 1];
			}
			else if (j == m - 1)
			{
				dp[i][j] = a[i][j] + dp[i + 1][j];
			}

			else
			{
				dp[i][j] = a[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	cout << dp[0][0] << endl;

	queue<trplet*> q;

	trplet* x = new trplet(0, 0, "");

	q.push(x);

	while (!q.empty())
	{
		trplet *f = q.front();
		q.pop();
		//int i = f->i;
		//int j = f->j;
		//int val = f->val;
		//string psf = f->psf;
		if (f->i == n - 1 and f->j == m - 1)
		{
			//cout << "aya";
			cout << f->psf << endl;
		}
		//cout << psf << endl;
		else if (f->j == m - 1)
		{
			//cout << "aya";
			trplet* h = new trplet(f->i + 1, f->j, f->psf + "V");
			q.push(h);
		}
		else if (f->i == n - 1)
		{
			//cout << "aya row last" << endl;
			trplet* g = new trplet(f->i, f->j + 1, f->psf + "H");
			q.push(g);
		}

		else
		{
			if (dp[f->i + 1][f->j] < dp[f->i][f->j + 1])
			{
				//cout << dp[f->i + 1][f->j] << " " << f->i + 1 << "," << f->j << endl;
				trplet * u = new trplet(f->i + 1, f->j, f->psf + "V");
				q.push(u);
			}

			else if (dp[f->i][f->j + 1] < dp[f->i + 1][f->j])
			{
				//cout << dp[f->i][f->j + 1] << " " << f->i << "," << f->j + 1 << endl;
				trplet* t = new trplet(f->i, f->j + 1, f->psf + "H");
				q.push(t);
			}

			else
			{
				trplet* v = new trplet(f->i, f->j + 1, f->psf + "H");
				q.push(v);
				trplet * w = new trplet(f->i + 1, f->j, f->psf + "V");
				q.push(w);
			}
		}
	}







}
