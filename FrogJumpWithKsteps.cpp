#include<iostream>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<cstring>//<--strings
#include<algorithm>//<--sort
#include<unordered_map>
#include<map>
#include<list>
#include<cstring>

using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair


int k;
int dp[1000000];

int FrogHumpWithKsteps(int ind, vector<int>heights)
{
	if (ind == 0)
		return 0;

	if (ind == 1)
		return abs(heights[1] - heights[0]);


	int ans = INT_MAX;
	for (int i = 1; i <= k ; ++i)
	{
		if (ind - i >= 0) {
			ans = min(ans, abs(heights[ind] - heights[ind - i]) + FrogHumpWithKsteps(ind - i, heights));
		}
		else
		{
			break;
		}
	}

	dp[ind] = ans;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	cout << endl;
	cout << endl;

	return 0;
}