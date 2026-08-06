#include <bits/stdc++.h>
using namespace std;
int solve(int n,int w,vector<int>& nums){
    sort(nums.begin(),nums.end());
    int ans=0;
    int i=0,j=n-1;
    while(i<j){
        ans++;
        int first=nums[i];
        int last=nums[j];
        if(first+last<=w){
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    if(i==j) ans++;
    return ans;
}
int main(){
    int n,w;
    cin>> n>> w;
    vector<int> child(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>> ele;
        child[i]=ele;
    }
    cout<< solve(n,w,child);
    return 0;
}