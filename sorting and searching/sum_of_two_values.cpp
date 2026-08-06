#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n,vector<int>& nums,int target){
    unordered_map<int,int> mp;
    mp.reserve(n);
    mp.max_load_factor(0.25);
    for(int i=0;i<n;i++){
        if(mp.find(target-nums[i])!=mp.end()){
            return {mp[target-nums[i]]+1,i+1};
        }
        mp[nums[i]]=i;
    }
    return {};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,target;
    cin>>n>>target;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums[i]=ele;
    }
    vector<int> ans=solve(n,nums,target);
    if(ans.size()==0){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<ans[0]<<" "<<ans[1];
    }
    return 0;
}