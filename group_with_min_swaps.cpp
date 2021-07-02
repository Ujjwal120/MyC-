#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);
#define int long long 

using namespace std;

const int p = 1e18;
const int maxn = 1e6+10;

int pref_pos[maxn], suff_pos[maxn];

vector<int> imp_pref, imp_suff, val_pref, val_suff;


// can also be donw through medians

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    pref_pos[0] = (s[0] != '*');

    for(int i = 1; i < n; i++) {
        pref_pos[i] = pref_pos[i-1] + (s[i] != '*');
    }

    suff_pos[n-1] = (s[n-1] == '*');

    for(int i = n-2; i >= 0; i--) {
        suff_pos[i] = suff_pos[i+1] + (s[i] != '*');
    }

    imp_pref.clear(); imp_suff.clear();

    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            imp_pref.push_back(pref_pos[i]);
            imp_suff.push_back(suff_pos[i]);
        }
    }

    val_pref = imp_pref;
    val_suff = imp_suff;

    for(int i = (int)imp_pref.size() - 2; i >= 0; i--) {
        imp_pref[i] += imp_pref[i+1];
    }

    for(int i = 1; i < (int)imp_pref.size(); i++) {
        imp_suff[i] += imp_suff[i-1];
    }

    int ans = p;

    int sz = imp_pref.size();
    for(int i = 0; i < sz; i++) {
        int temp = 0;
        temp += (i+1 == imp_pref.size()) ? 0 :  imp_pref[i+1] - (sz-1-i)*val_pref[i];
        temp += (i == 0) ? 0 :  imp_suff[i-1] - i*val_suff[i];

        ans = min(ans, temp);
    }

    cout << ((ans == p) ? 0 : ans) << "\n";
}

signed main() {
    fast int t;
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}