#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("brute_output.txt", "w", stdout);

#define int long long 
using namespace std;

const int maxn = 1e5+10;
const int p = 1e9+7;
vector<int> a;
vector<int> diff;
vector<int> cnt;
vector<pair<pair<int, int>, int>> op;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    a.resize(n);
    diff.resize(n);
    cnt.resize(m, 0);
    op.resize(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> op[i].first.first >> op[i].first.second >> op[i].second;
    }

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cnt[x]++;
        if(y+1 < m) cnt[y+1]--;
    }

    for(int i = 1; i < m; i++) {
        cnt[i] += cnt[i-1];
    }

    diff[0] = a[0];
    for(int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i-1];
    }

    for(int i = 0; i < m; i++) {
        int increase = op[i].second * cnt[i];
        int l = op[i].first.first-1; 
        int r = op[i].first.second-1;
        diff[l] += increase;
        if(r+1 < n) diff[r+1] -= increase;
    }

    for(int i = 1; i < n; i++) {
        diff[i] += diff[i-1];
    }

    for(int x : diff) cout << x << " ";
    cout << "\n";
}

signed main() {
    fast int t = 1;
    // input output
    // cin >> t;
    while(t--) solve();
    return 0;
}