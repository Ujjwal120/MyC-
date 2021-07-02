#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

vector<int> a, c;

void solve() {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    c.resize(k);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(c.begin(), c.end());
    
    int ans = 0;
    for(int i = 0; i < k; i++) ans += a[i];

    int l_ind = 0, cnt = 0;

    for(int i = 0; i < k; i++) {
        if(c[i] == 0) {
            ans += a[i];
            l_ind++;
        }
        else break;
    }

    for(int i = k; i < n; i++) {
        if(c[l_ind] == 1) {
            ans += a[i];
            l_ind++;
        } 
        else c[l_ind]--;
    }

    cout << ans << "\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}