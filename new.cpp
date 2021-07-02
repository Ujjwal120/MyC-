#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("brute_output.txt", "w", stdout);

// #define int long long 
using namespace std;
const int maxn = 1e5+10;


// target value
//  3 5 -4 8 11 1 -1 6 
        
// -4 -1 1 3 5 6 8 11

// vector<int> v;
map<int, int> v;

void solve() {
    int n, target; cin >> n >> target;
    v.clear();

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x] += 1;
    }

    bool found = false; 
    for(auto i : v) {
        int f = target - i.first; // key
        if(f == i.first) {
            // check if the count is atleast 2 for that key
            if(v.count(f) > 1) {
                found = true;
                cout << i.first << " " << i.first << "\n";
            }
        }
        else {
            if(v.count(f) != 0) {
                found = true;
                cout << i.first << " " << f << "\n";
            }
        }
    }

    if(!found) {
        cout << "not possible\n";
    }

}




signed main() {
    fast int t = 1;
    // input output
    // cin >> t;
    while(t--) solve();
    return 0;
}