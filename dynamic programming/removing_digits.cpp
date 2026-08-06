#include<bits/stdc++.h>
using namespace std;
int solve(int sum,vector<int>& dp,int target){
    if(sum==target){
        return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int temp=sum;
    int ans=INT_MAX;
    while(temp){
        int digit=temp%10;
        temp=temp/10;
        if(digit==0) continue;
        ans=min(ans,1+solve(sum-digit,dp,target));
    }
    return dp[sum]=ans;;
}
int remove(int num){
    vector<int> dp(num+1,-1);
    return solve(num,dp,0);

}
int main(){
    int n;
    cin>> n;
    cout<< remove(n);
    return 0;
}