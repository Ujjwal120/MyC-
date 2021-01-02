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
using namespace std;
 
const int p=1e9+7;
const int maxn=1e5+2;
int DP[3000][3000], back_track[3000][3000];  // back_track[i][j] = 0, 1, 2   if(0) => i-- if(1) => j-- if(2) => i-- && j--

void solve() {
    string s, t; cin >> s >> t;
    DP[0][0] = 0;
    if(s[0] == t[0]) {
        DP[0][0] = 1;
        back_track[0][0] = 2;
    }
    int n = s.length();
    int m = t.length();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // not picking 
            if(i > 0) {
                DP[i][j] = DP[i-1][j];
                back_track[i][j] = 0;
            }
            if(j > 0) {
                if(DP[i][j-1] > DP[i][j]) { // if DP[i][j] is not initialised above it contains zero due to global declaration
                    DP[i][j] = DP[i][j-1];
                    back_track[i][j] = 1;
                }
            }

            // picking only when they characters are equal
            if(s[i] == t[j]) {
                int ans = 1;
                if(i > 0 && j > 0) {
                    ans = 1 + DP[i-1][j-1];
                }
                if(ans > DP[i][j]) {
                    DP[i][j] = ans;
                    back_track[i][j] = 2;
                }
            }
        }
    }

    // cout << DP[n-1][m-1] <<"\n";       // optimal max length of common subsequence

    // back_track 1 & 2  correspond to not getting picked
    int i = n-1, j = m-1;
    string ans = "";
    while(i >= 0 && j >= 0) {
        if(back_track[i][j] == 0) {
            i--;
        }
        else if(back_track[i][j] == 1) {
            j--;
        }
        else {
            ans = s[i] + ans;
            i--; j--;
        }
    }
    cout << ans <<"\n";
}

int main() {
    fast 
    // input output
    int t = 1; 
    // cin>>t; 
    while(t--) solve();
    return 0;
}