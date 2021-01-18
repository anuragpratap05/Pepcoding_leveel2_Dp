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
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}

	int tar;
	cin >> tar;

	bool dp[n + 1][tar + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tar; j++)
		{
			dp[i][j] = false;
		}
	}

	for (int i = 0; i <= tar; i++)
	{
		dp[0][i] = false;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= tar; j++)
		{
			if (dp[i - 1][j])
			{
				dp[i][j] = true;
			}
			else if (j >= a[i - 1])
			{

				if (dp[i - 1][j - a[i - 1]])
				{
					dp[i][j] = true;
				}
			}
		}
	}

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tar; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	if (dp[n][tar])
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

		if (i==0 or j == 0)
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
					trplet* y = new trplet(i - 1, j - a[i - 1],  to_string(i - 1) +" "+ psf);
					q.push(y);
				}
			}
		}
	}
	}
	else 
	{
	    cout<<"false";
	}

}
