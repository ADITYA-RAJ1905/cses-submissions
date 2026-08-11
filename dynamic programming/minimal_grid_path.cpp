#include <bits/stdc++.h>
using namespace std;

string solve(int i, int j, vector<vector<char>>& grid,
             vector<vector<string>>& dp) {

    int n = grid.size();

    // Destination
    if(i == n - 1 && j == n - 1) {
        return string(1, grid[i][j]);
    }

    // Already calculated
    if(dp[i][j] != "#") {
        return dp[i][j];
    }

    string down = "";
    string right = "";

    // Move down
    if(i + 1 < n) {
        down = solve(i + 1, j, grid, dp);
    }

    // Move right
    if(j + 1 < n) {
        right = solve(i, j + 1, grid, dp);
    }

    string best;

    if(down.empty()) {
        best = right;
    }
    else if(right.empty()) {
        best = down;
    }
    else {
        best = min(down, right);
    }

    return dp[i][j] = grid[i][j] + best;
}

string minpath(vector<vector<char>>& grid) {

    int n = grid.size();

    // "#" means not calculated yet
    vector<vector<string>> dp(n, vector<string>(n, "#"));

    return solve(0, 0, grid, dp);
}

int main() {

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minpath(grid);

    return 0;
}