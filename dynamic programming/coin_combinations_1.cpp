#include<bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int solve(int sum,vector<int>& nums,vector<int>& dp,int target){
    int n=nums.size();
    if(sum >target){
        return 0;
    }
    if(sum==target){
        return 1;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    long long ways=0;
    for(int coin:nums){
        ways=(ways+solve(sum+coin,nums,dp,target)) % MOD;
    }
    return dp[sum]=ways;
}
int coinchange(vector<int>& nums,int target){
    int n=nums.size();
    vector<int> dp(target+1,-1);
    return solve(0,nums,dp,target);
}
int main(){
    int n,x;
    cin>> n>> x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums[i]=ele;
    }
    cout<<coinchange(nums,x);
    return 0;
}