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

int kconcat(int a[], int n)
{
	int csum = a[0];
	int ovsum = a[0];
	for (int i = 1; i < n; i++)
	{
		if (csum >= 0)

		{
			csum += a[i];
			//cout << csum << endl;
		}
		else
		{
			csum = a[i];
		}
		if (csum > ovsum)
		{
			ovsum = csum;
		}
	}
	return ovsum;
}

int kconcat_two(int a[], int n)
{
	int arr[2 * n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		arr[i + n] = a[i];
	}
	return kconcat(arr, 2 * n);

}

int main()
{

	int n;
	cin >> n;
	int a[n];
	int kadene[n];
	//int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		//sum += a[i];
	}
	int csum = a[0];
	kadene[0] = a[0];
	//int ovsum = a[0];
	for (int i = 1; i < n; i++)
	{
		if (csum >= 0)

		{
			csum += a[i];
			//cout << csum << endl;
		}
		else
		{
			csum = a[i];
		}
		kadene[i] = csum;
	}




	int k;
	cin >> k;
	int cur_val = 0;
	int ans = INT_MIN;
	for (int i = 0; i < k; i++)
	{
		cur_val += a[i];
	}

	if (cur_val > ans) ans = cur_val;
	int more_k = INT_MIN;
	for (int i = k; i < n; i++)
	{
		cur_val = cur_val + a[i] - a[i - k];
		if (cur_val > ans)
		{
			ans = cur_val;
		}
		more_k = kadene[i - k] + cur_val;
		//cur_val += kadene[i - k];
		if (more_k > ans)
		{
			ans = more_k ;
		}
	}

	cout << ans;


	/*int csum = a[0];
	int ovsum = a[0];
	for (int i = 1; i < n; i++)
	{
		if (csum >= 0)

		{
			csum += a[i];
			//cout << csum << endl;
		}
		else
		{
			csum = a[i];
		}
		if (csum > ovsum)
		{
			ovsum = csum;
		}
	}
	cout << ovsum;*/
	/*for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << dp[0][n - 1];









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
