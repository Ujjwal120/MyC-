#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);
#define int long long 

using namespace std;

const int p = 1e18;
const int maxn = 1e6+10;
int cs = 0;
string s[110];
int n, m;
bool visited[110][110];

int alpha[26];

int temp_alpha[26];   // make zero before every travel call

void travel(int i, int j) {
    if(i < 0 || j == m || i == n || j < 0) return;
    if(visited[i][j]) return;
    if(s[i][j] == '#') return;

    visited[i][j] = 1;

    if(s[i][j] != '.') {
        temp_alpha[s[i][j] - 'a'] = 1;
    }
    travel(i-1, j);
    travel(i, j-1);
    travel(i, j+1);
    travel(i+1, j);
}

void solve() {
    // int ans = 0;
    int contested = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') visited[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                for(int x = 0; x < 26; x++) temp_alpha[x] = 0;
                travel(i, j); 
                
                int cont = 0;
                for(int x = 0; x < 26; x++) {
                    if(temp_alpha[x] != 0) cont++;
                    if(cont > 1) break;
                }

                if(cont > 1) contested++;
                else 
                if(cont == 1) {
                    for(int x = 0; x < 26; x++) {
                        if(temp_alpha[x] != 0) {
                            alpha[x]++;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "Case " << ++cs << ":" << "\n";
    for(int i = 0; i < 26; i++) {
        if(alpha[i] != 0) cout << (char)('a'+i) << " " << alpha[i] << "\n";
    }
    cout << "contested " << contested << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < 26; i++) alpha[i] = 0;
}

signed main() {
    fast int t;
    // input 
    // output
    cin >> t;
    while(t--) solve();
    return 0;
}