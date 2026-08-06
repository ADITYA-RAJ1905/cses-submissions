#include<bits/stdc++.h>
using namespace std;
long long solve(int n,vector<int>& nums){
    long long ans=0;
    sort(nums.begin(),nums.end());
    int median;
    median=nums[n/2];
    for(int num:nums){
        ans+=abs(1LL* num-median);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums[i]=ele;
    }
    cout<<solve(n,nums);
    return 0;
}