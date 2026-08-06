#include <bits/stdc++.h>
using namespace std;
long long solve(int n,vector<int>& nums){
    sort(nums.begin(),nums.end());
    long long reach=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=reach+1){
            reach=reach+nums[i];
        }
        else{
            return reach+1;
        }
    }
    return reach+1;
}
int main(){
    int n;
    cin>> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums[i]=ele;
    }
    cout<<solve(n,nums);
    return 0;
}