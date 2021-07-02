#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);
#define int long long 

using namespace std;

set<int> indexes;
vector<pair<int, int>> maxm;
const int p = 1e9+7;
int two_power;

inline int mul (int a, int b) {
    int r = a*b;
    return (r >= p) ? r%p : r;
}

inline int add (int a, int b) {
    int r = a+b;
    return (r >= p) ? (r-p) : r;
}


int taakat(int x, int y) { 
    int r = 1;    
    while(y > 0) { 
        if (y & 1) r = mul(r,x); 
        y = y>>1;  x = mul(x,x); 
    } 
    return r; 
}

int AP(int l, int r) {
    int sum = r*(r+1)/2;
    if(sum >= p) sum %= p;
    return(mul(two_power, mul(l, add(sum, add(sum, mul(l-1, r))))));
}

void solve() {
    indexes.clear();
    maxm.clear();
    
    int n; cin >> n;
    maxm.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> maxm[i].first;
        maxm[i].second = i;
    }

    sort(maxm.begin(), maxm.end(), [&] (pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    int ans = 0;
    for(int i = 0; i < n; i++) {
        indexes.insert(maxm[i].second);
        auto ind = indexes.lower_bound(maxm[i].second);
        
        if(ind == indexes.begin() && next(ind) == indexes.end()) {
            ans = add(ans, mul(maxm[i].first, AP(*ind + 1, n - (*ind))));
        }
        else if(ind == indexes.begin()) {
            ans = add(ans, mul(maxm[i].first, AP(*ind + 1, *next(ind) - (*ind))));
        }
        else if(next(ind) == indexes.end()) {
            ans = add(ans, mul(maxm[i].first, AP(*(ind) - *prev(ind), n - (*ind))));
        }
        else {
            ans = add(ans, mul(maxm[i].first, AP((*ind) - *prev(ind), *next(ind) - (*ind))));
        }
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    two_power = taakat(2, p-2);
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}