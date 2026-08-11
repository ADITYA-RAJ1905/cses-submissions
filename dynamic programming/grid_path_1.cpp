#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& dp){
    int n=grid.size();
    if(i>=n || j>=n || i<0 || j<0 || grid[i][j]=='*'){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=(solve(i+1,j,grid,dp)+ solve(i,j+1,grid,dp))%MOD;
    return dp[i][j];
}
int gridpath(int n,vector<vector<char>>& grid){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(0,0,grid,dp);
}
int main(){
    int n;
    cin>> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ele;
            cin>> ele;
            grid[i][j]=ele;
        }
    }
    cout<<gridpath(n,grid);
    return 0;
}