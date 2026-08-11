#include<bits/stdc++.h>
using namespace std;
int solve(int i,int sum,vector<vector<int>>& dp,vector<int>& nums,int target){
    int n=nums.size();
    if(i>=n || sum>target){
        return 1e9;
    }
    if(sum==target){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    dp[i][sum]=min(1+solve(i,sum+nums[i],dp,nums,target),solve(i+1,sum,dp,nums,target));
    return dp[i][sum];
}
int coins(int num,vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(num+1,-1));
    return solve(0,0,dp,nums,num);
}
int main(){
    int n,target;
    cin>> n>> target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>> ele;
        nums[i]=ele;

    }
    cout<<coins(target,nums);
    return 0;
}