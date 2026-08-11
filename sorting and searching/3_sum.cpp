#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int target) {
    int n = arr.size();

    vector<pair<int,int>> nums;

    for(int i = 0; i < n; i++) {
        nums.push_back({arr[i], i + 1}); // {value, original index}
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {

        int j = i + 1;
        int k = n - 1;

        while(j < k) {

            long long sum = 1LL * nums[i].first + nums[j].first + nums[k].first;

            if(sum == target) {
                return {
                    nums[i].second,
                    nums[j].second,
                    nums[k].second
                };
            }
            else if(sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return {};
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = solve(nums, target);
    sort(ans.begin(),ans.end());
    if(ans.empty()) {
        cout << "IMPOSSIBLE";
    }
    
    else {
        cout << ans[0] << " " << ans[1] << " " << ans[2];
    }

    return 0;
}