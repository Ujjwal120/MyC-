#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("brute_output.txt", "w", stdout);

#define int long long 
using namespace std;

const int maxn = 1e5+10;
// int cs = 0;
const int p = 1e9+7;
vector<int> start[26];

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < 26; i++) start[i].clear();

    for(int i = 0; i < n; i++) {
        start[s[i]-'a'].push_back(i);
    }

    string x = "a";

    while(1) {
        bool found = false;

        int ind = x[0] - 'a';

        for(int j = 0; j < start[ind].size(); j++) {
            string temp = "";
            if(start[ind][j]+(int)x.length()-1 < n) {
                for(int i = 0; i < (int)x.length(); i++) {
                    temp += s[start[ind][j] + i];
                }
                
                if(temp == x) {
                    found = true; break;
                }
            }
            else break;
        }

        if(found) {
            bool increase = true;
            for(int j = (int)x.length()-1; j >= 0; j--) {
                if(x[j] != 'z') {
                    increase = false;
                    x[j]++;
                    for(int i = j+1; i < (int)x.length(); i++) x[i] = 'a'; 
                    break;
                }
            }

            if(increase) {
                int sz = (int)x.length();
                x = "";
                for(int j = 0; j < sz+1; j++) {
                    x += 'a';
                }
            }
        }
        else break;
    }

    cout << x << "\n";
}

signed main() {
    fast int t;
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}