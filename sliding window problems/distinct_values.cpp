#include <bits/stdc++.h>
using namespace std;
void solve(int k,vector<int>& nums,vector<int>& ans){
    int n=nums.size();
    unordered_map<int,int> mp;
    int i=0,j=0;
    while( j<n){
        mp[nums[j]]++;
        j++;
        if(j-i==k){
            ans.push_back(mp.size());
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            i++;
        }
        
    }
}
void distinct(int k,vector<int>& nums){
    vector<int> ans;
    solve(k,nums,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n,k;
    cin>> n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>> ele;
        nums[i]=ele;
    }
    distinct(k,nums);
    return 0;
}