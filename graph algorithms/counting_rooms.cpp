#include <bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    if(i>=n || j>=m || i<0 || j<0 || grid[i][j]!='.'){
        return ;
    }
    grid[i][j]='#';
    solve(i+1,j,grid);
    solve(i-1,j,grid);
    solve(i,j+1,grid);
    solve(i,j-1,grid);
}
int count(vector<vector<char>>& grid,int n,int m){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                ans++;
                solve(i,j,grid);
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ele;
            cin>> ele;
            grid[i][j]=ele;
        }
    }
    cout<< count(grid,n,m);
    return 0;
}