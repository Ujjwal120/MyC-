#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("brute_output.txt", "w", stdout);

// #define int long long 
using namespace std;

const int maxn = 1e5+10;
// int cs = 0;
const int p = 1e9+7;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

vector<int> ans;
map<pair<int, int>, int> rat;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    rat.clear();
    ans.resize(n);

    // {0, x} => {0, 1} special cases
    // {x, 0} => {1, 0} special cases

    int d = 0, k = 0;
    for(int i = 0; i < n; i++) {
        d += (s[i] == 'D');
        k += (s[i] == 'K');

        if(d == 0 && k != 0) {
            ans[i] = ++rat[{0, 1}];
            continue;
        }
        else if(d != 0 && k == 0) {
            ans[i] = ++rat[{1, 0}];
            continue;
        }

        int g = gcd(d, k);
        pair<int, int> key = {d/g, k/g};
        ans[i] = ++rat[key];
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    fast int t;
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}