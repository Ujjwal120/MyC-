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

const int p = 1e9 + 7;
const int maxn = 1e5 + 1;

void solve() {
    int n; cin >> n;
    int tone = 0, bit = 0, slone = -1, zero = -1, orig = n;
    if(n == 0) cout << "0\n";
    else {
        if(n == 2) cout << "2\n";
        else {
            while(n > 0) {
                bit++;
                if(n&1) {
                    if(n != 1) { slone = bit; }
                    tone++;
                }
                else zero = bit;
                n >>= 1;
            }
            
            if(bit == tone) cout << ((bit<<1)-1) << "\n";  
            else {
                if(zero > slone) cout << bit-1 + max(zero-1, __builtin_popcount(orig)) << "\n";
                else cout << ((bit<<1)-2) << "\n";
            }
        }
    }
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}