#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(int sum, vector<int>& dp) {

    if(sum == 0)
        return 1;

    if(dp[sum] != -1)
        return dp[sum];

    long long ways = 0;

    for(int dice = 1; dice <= 6; dice++) {

        if(sum >= dice) {
            ways += solve(sum - dice, dp);
            ways %= MOD;
        }
    }

    return dp[sum] = ways;
}

int main() {

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << solve(n, dp);

    return 0;
}