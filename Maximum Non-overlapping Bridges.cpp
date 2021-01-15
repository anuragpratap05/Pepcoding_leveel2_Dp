# Pepcoding_leveel2_Dp#include<bits/stdc++.h>
using namespace std;


int main()
{

	int n;
	cin >> n;

	int south[n];
	int north[n];
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int s, n;
		cin >> s >> n;
		v.push_back(make_pair(s, n));

	}

	sort(v.begin(), v.end());



	int dp[n];
	for (int i = 0; i < n; i++)
	{
		int maxi = 0;
		for (int j = 0; j < i; j++)
		{
			if (v[j].second < v[i].second)
			{
				maxi = max(maxi, dp[j]);
			}
		}
		dp[i] = maxi + 1;
	}
	//cout << endl;
	int ovmax = 0;
	for (int i = 0; i < n; i++)
	{
		ovmax = max(ovmax, dp[i]);
	}
	cout << ovmax;


}
