# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;

class trplet
{
public:
	int jump_left;
	int idx;
	int kood_skta;
	string psf;
	trplet(int jump_left, int idx, int kood_skta, string psf)
	{
		this->jump_left = jump_left;
		this->idx = idx;
		this->kood_skta = kood_skta;
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

	int dp[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = INT_MAX;
	}

	dp[n - 1] = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		int jumps = a[i];
		int mini = INT_MAX;
		if (jumps != 0)
		{
			for (int j = 1; j <= jumps and i + j < n; j++)
			{
				mini = min(mini, dp[i + j]);
			}
			dp[i] = mini + 1;
		}
	}


	/*for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}*/
    cout<<dp[0]<<endl;
	queue<trplet*> q;
	trplet* x = new trplet(dp[0], 0, a[0],  "0" );
	q.push(x);
	while (!q.empty())
	{

		trplet* f = q.front();
		q.pop();
		if (f->jump_left == 0)
		{
			cout << f->psf+" ." << endl;
		}

		for (int j = f->idx + 1; j <= f->idx + f->kood_skta and j < n; j++)
		{
			if (f->jump_left - 1 == dp[j])
			{
				//cout << j << endl;
				trplet* y = new trplet(dp[j], j, a[j], f->psf + " -> " + to_string(j)  );
				q.push(y);
			}
		}
	}

}
