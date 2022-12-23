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

class Solution {
public:
	//top down
	//TC: O(N)
	//SC: O(N + N)
	int dp[1000] = {0};
	int solve(int ind, vector<int>&nums) {
		if (ind < 0)
			return 0;
		if (ind == 0)
			return nums[0];

		if (dp[ind] != -1)
			return dp[ind];

		int left = 0, right = 0;
		left = solve(ind - 2, nums) + nums[ind];

		right = solve(ind - 1, nums);

		return dp[ind] = max(left, right);
	}


	int rob(vector<int>& nums) {
		// dp=new int[nums.size()];
		memset(dp, -1, sizeof(dp));
		return solve(nums.size() - 1, nums);
	}


	//bottom up
	//TC: O(N)
	//SC: O(N)

	int rob(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n, -1);
		dp[0] = nums[0];
		int neg = 0;
		for (int i = 1; i < n; ++i)
		{
			int op1 = nums[i], op2 = 0;
			if (i > 1)
				op1 += dp[i - 2];
			op2 = dp[i - 1];
			dp[i] = max(op1, op2);
		}

		return dp[n - 1];
	}


	//TC : O(N)
	//SC : O(1)

	int rob(vector<int>& nums) {
		int n = nums.size();
		// dp[0] = nums[0];
		int neg = 0;
		int a = 0, b = nums[0];
		for (int i = 1; i < n; ++i)
		{
			int c = max(nums[i] + a, b);
			a = b;
			b = c;
		}

		return b;
	}
};

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