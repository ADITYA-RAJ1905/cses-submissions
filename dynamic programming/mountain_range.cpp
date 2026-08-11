#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> nums(n);
    int maxi=INT_MIN;
    int idx=0;
    for(int i=0;i<n;i++){
        int ele;
        cin>> ele;
        nums[i]=ele;
        if(ele>maxi){
            maxi=ele;
            idx=i;
        }
    }
    cout<< max(idx-0,n-idx);
    return 0;
}