#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string& s, string& t,
          vector<vector<int>>& dp) {

    int n = s.size();
    int m = t.size();

    // s is exhausted
    if(i == n)
        return m - j;

    // t is exhausted
    if(j == m)
        return n - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == t[j]) {

        dp[i][j] = solve(i + 1, j + 1, s, t, dp);

    }
    else {

        int replaceChar = 1 + solve(i + 1, j + 1, s, t, dp);

        int deleteChar = 1 + solve(i + 1, j, s, t, dp);

        int insertChar = 1 + solve(i, j + 1, s, t, dp);

        dp[i][j] = min({
            replaceChar,
            deleteChar,
            insertChar
        });
    }

    return dp[i][j];
}

int main() {

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << solve(0, 0, s, t, dp);

    return 0;
}