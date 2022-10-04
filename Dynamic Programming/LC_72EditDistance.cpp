
#include <bits/stdc++.h>
using namespace std;

string w1, w2;

int dp[505][505];

int solve(int i, int j)
{
    int ans = INT_MAX;

    if (i == w1.length() && j < w2.length())
    {
        // use insert op
        return dp[i][j] = min(ans, 1 + solve(i, j + 1));
    }

    if (j == w2.length() && i < w1.length())
    {
        // use delete op
        return dp[i][j] = min(ans, 1 + solve(i + 1, j));
    }

    if (i == w1.length() && j == w2.length())
    {
        return dp[i][j] = 0;
    }

    if (dp[i][j] != INT_MAX)
    {
        return dp[i][j];
    }

    if (w1[i] == w2[j])
    {
        ans = min(ans, solve(i + 1, j + 1));
    }
    else
    {
        // insert
        ans = min(ans, 1 + solve(i, j + 1));
        // delete
        ans = min(ans, 1 + solve(i + 1, j));
        // replace
        ans = min(ans, 1 + solve(i + 1, j + 1));
    }
    return dp[i][j] = ans;
}

int minDistance(string word1, string word2)
{
    // O(N^2)
    w1 = word1;
    w2 = word2;
    for (int i = 0; i < 505; i++)
    {
        for (int j = 0; j < 505; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    return solve(0, 0);
}