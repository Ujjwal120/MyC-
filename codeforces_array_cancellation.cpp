#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("1.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define ll long long int
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpi vector<pii>
#define vpl vector<pll> 
#define ss second 
#define ff first
 
using namespace std;
 
const int p = 1e9+7;
const int maxn = 1e5 + 1;
 
void solve() {
    int n; cin >> n;
    ll pos = 0, neg = 0;
    vl st(n);

    for(int i = 0; i < n ; i++) {
        cin >> st[i];
    }

    for(int i = n-1; i >= 0; i--) {
        if(st[i] > 0) {
            // neutralise this
            ll can = min(st[i], abs(neg));
            pos += st[i] - can;
            neg += can;
        }
        else {
            neg += st[i];
        }
    }
    cout << pos << "\n";
}
 
int main() {
    fast
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}