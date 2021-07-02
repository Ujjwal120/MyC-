#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);
#define int long long 

using namespace std;

const int p = 1e18;
const int maxn = 1e6+10;
int cs = 0;
string s[110], word;
int n, m;

bool h(int j) {
    return (m-j) >= (int)word.length();
}

bool v(int i) {
    return (n-i) >= (int)word.length();
}

void solve() {
    int ans = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[i];

    cin >> word;

    //check diagonal only if size is atleast two of word
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(h(j) && v(i) && (int)word.length() > 1) {
                bool same = true;
                string temp = "";
                for(int x = 0; x < (int)word.length(); x++) {
                    temp += s[x+i][x+j];
                }

                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;

                same = true;
                reverse(temp.begin(), temp.end());
                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;
            }

            if(h(j)) {
                bool same = true;
                string temp = "";

                for(int x = 0; x < (int)word.length(); x++) {
                    temp += s[i][x+j];
                }

                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;

                same = true;
                reverse(temp.begin(), temp.end());
                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;
            }

            if(v(i)) {
                bool same = true;
                string temp = "";

                for(int x = 0; x < (int)word.length(); x++) {
                    temp += s[i+x][j];
                }

                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;

                same = true;
                reverse(temp.begin(), temp.end());
                for(int x = 0; x < (int)word.length(); x++) {
                    if(temp[x] != word[x]) {
                        same = false;
                        break;
                    }
                }
                if(same) ans++;

            }
        }
    }

    if((int)word.length() > 1) {
        for(int i = 0; i < n; i++) {
            reverse(s[i].begin(), s[i].end());
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(h(j) && v(i)) {
                    bool same = true;
                    string temp = "";
                    for(int x = 0; x < (int)word.length(); x++) {
                        temp += s[x+i][x+j];
                    }

                    for(int x = 0; x < (int)word.length(); x++) {
                        if(temp[x] != word[x]) {
                            same = false;
                            break;
                        }
                    }
                    if(same) ans++;

                    same = true;
                    reverse(temp.begin(), temp.end());
                    for(int x = 0; x < (int)word.length(); x++) {
                        if(temp[x] != word[x]) {
                            same = false;
                            break;
                        }
                    }
                    if(same) ans++;
                }
            }
        }
    }
    
    cout << "Case " << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    // input output
    cin >> t;
    while(t--) solve();
    return 0;
}