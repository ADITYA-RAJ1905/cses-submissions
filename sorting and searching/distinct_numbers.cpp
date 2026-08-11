#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> st;

    while (n--) {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << st.size();
}