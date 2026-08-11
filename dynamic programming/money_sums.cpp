#include <bits/stdc++.h>
using namespace std;

void solve(int i, int sum, vector<int>& coins,
           vector<vector<int>>& dp, vector<bool>& possible) {

    int n = coins.size();

    if(i == n) {
        possible[sum] = true;
        return;
    }

    if(dp[i][sum] != -1)
        return;

    dp[i][sum] = 1;

    solve(i + 1, sum, coins, dp, possible);

    solve(i + 1, sum + coins[i], coins, dp, possible);
}

int main() {

    int n;
    cin >> n;

    vector<int> coins(n);
    int totalSum = 0;

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        totalSum += coins[i];
    }

    vector<vector<int>> dp(
        n,
        vector<int>(totalSum + 1, -1)
    );

    vector<bool> possible(totalSum + 1, false);

    solve(0, 0, coins, dp, possible);

    int count = 0;

    for(int sum = 1; sum <= totalSum; sum++) {
        if(possible[sum])
            count++;
    }

    cout << count << "\n";

    for(int sum = 1; sum <= totalSum; sum++) {
        if(possible[sum])
            cout << sum << " ";
    }

    return 0;
}