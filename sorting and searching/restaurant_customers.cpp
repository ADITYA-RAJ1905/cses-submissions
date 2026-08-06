#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<vector<int>>& nums){
    sort(nums.begin(),nums.end());
    int ans=0;
    int last=nums[0][1];
    int c=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int arrival=nums[i][0];
        int depart=nums[i][1];
        while(!pq.empty() && pq.top()<arrival){
            pq.pop();
        }
        pq.push(depart);
        ans=max(ans,(int)pq.size());
    }
    return ans;
}
int main(){
    vector<vector<int>> nums;
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        int a,d;
        cin>> a>>d;
        nums.push_back({a,d});
    }
    cout<<solve(n,nums);
    return 0;
}