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

//Bottom Up

class Solution {
public:
	int climbStairs(int n) {
		int *Steps = new int[n + 1];
		Steps[0] = Steps[1] = 1;
		for (int i = 2; i <= n; i++) {
			Steps[i] = Steps[i - 1] + Steps[i - 2];
		}

		return Steps[n];
	}
};


// Top Down

class Solution {
public:
	int dp[50] = {0}; //none case has an answer of 0 , so we can use 0 has our garbage value
	int climbStairs(int n) {
		if (n <= 1)
			return 1;

		if (dp[n] != 0)
			return dp[n];

		return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
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