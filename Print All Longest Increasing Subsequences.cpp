# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;

class triplet
{
public:
	int l, idx, val;
	string psf;

	triplet(int l, int idx, int val, string psf)
	{
		this->l = l;
		this->idx = idx;
		this->val = val;
		this->psf = psf;
	}
};

int main()
{

	int n;
	cin >> n;

	int input[n];
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	int ovmax = 0;
	int mi = 0;
	int dp[n];

	for (int i = 0; i < n; i++)
	{
		int maxi = 0;
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i])
			{
				maxi = max(maxi, dp[j] );
			}
		}
		dp[i] = maxi + 1;
		if (dp[i] > ovmax)
		{
			ovmax = dp[i];
			mi = i;
		}

	}
	cout << ovmax << endl;
	/*for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}*/
	//triplet t;
	queue<triplet*> q;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == ovmax)
		{
			triplet *x = new triplet(ovmax, i, input[i], to_string(input[i]) + "");
			q.push(x);
		}
	}

	//triplet *x = new triplet(ovmax, mi, input[mi], to_string(input[mi]) + "");
	//q.push(x);
	while (!q.empty())
	{
		triplet* rem = q.front();
		q.pop();
		if (rem->l == 1)
		{
			cout << rem->psf << endl;
		}
		for (int j = rem->idx - 1; j >= 0; j--)
		{
			if (dp[j] == rem->l - 1 and input[j] <= rem->val)
			{
				triplet *y = new triplet(dp[j], j, input[j], to_string(input[j]) + " -> " + rem->psf);
				q.push(y);
			}
		}
	}







}
