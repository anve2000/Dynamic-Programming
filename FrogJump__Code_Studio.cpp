#include <bits/stdc++.h>

//one pass, no separate function needed


vector<int>dp; // made it global , so erase the memory after a testcase execution completes

int frogJump(int n, vector<int> &heights)
{
    if (n == heights.size()) {
        dp.resize(n + 1, -1);   //at beginning index n, dp initialised and allocated size

    }
    if (n <= 1)
    {
        dp.clear();  //memory erased
        return 0;
    }



    if (n == 2) {
        return abs(heights[1] - heights[0]);
    }

    if (dp[n] != -1)
        return dp[n];

    int left = INT_MAX, right = INT_MAX;

    left = abs(heights[n - 1] - heights[n - 2]) + frogJump(n - 1, heights);

    if (n > 2) {
        right = abs(heights[n - 1] - heights[n - 3]) + frogJump(n - 2, heights);
    }

    return dp[n] = min(left, right);
}