#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);

#define int long long 
using namespace std;

const int maxn = 1e5+10;
int cs = 0;

const int p = 1e9+7;
int n, k;

inline int mulmod(int a,int b) { 
    int x = a*b;
    if(x>=p) return x%p; return x;
}

inline int addmod(int a,int b){ return (a+b>=p?a+b-p:a+b); }

int cnt[maxn], kpower[maxn];

void solve() {
    cin >> n >> k;
    string s; cin >> s;

    string temp = s.substr(0, (n+1)/2);

    if(n == 1) {
	    cout << "Case #" << ++cs << ": " << s[0] - 'a' << "\n"; 
        return;
    }

    int sz = (int)temp.length();
	int ans = 0;

    for(int i = 0; i < sz; i++) {
        cnt[i] = s[i]-'a'+1;
    }

    kpower[0] = 1;
    for(int i = 1; i < sz; i++) {
        kpower[i] = mulmod(kpower[i-1], k);
    }

    for(int i = 0; i < sz; i++) {
        ans = addmod(ans, mulmod(cnt[i]-1, kpower[sz-1-i]));
    }

    string test = temp;
    if(n&1) {
        test.pop_back();
    }
    reverse(test.begin(), test.end());

    temp += test;
    if(temp < s) ans = addmod(ans, 1);

	cout << "Case #" << ++cs << ": " << ans << "\n"; 
}

signed main() {
    fast int t;
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}