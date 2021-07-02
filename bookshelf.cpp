#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);
#define int long long 

using namespace std;

const int p = 1e15;
const int maxn = 1e5;

vector<vector<int>> val(19, vector<int>());
vector<int> arr;
bool settled[19];

void solve() {
    int n; cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        val[arr[i]].push_back(i);
    }

    int loop = 0;
    for(int i = 0; i < 19; i++) {
        if(val[i].size() == 0) settled[i] = 1;
        else loop++;
    }

    if(loop == 1) cout << "0\n";

    loop--;

    int cur = 0;
    int ans = 0;
    while(loop--) {
        // with each loop find min swap contestant and 
        // keep track of it's length in case clash happens
        int m = p, len = -p, which_val;
        
        for(int i = 1; i < 19; i++) {
            if(!settled[i]) {
                int temp = 0;
                for(int j = 0; j < val[i].size(); j++) {
                    temp += val[i][j] - (cur+j);
                }

                if(temp < m) {
                    m = temp;
                    which_val = i;
                    len = val[i].size();
                }
                else if(temp == m && val[i].size() > len) {
                    which_val = i;
                    len = val[i].size();
                }
            }
        }

        int from = val[which_val][val[which_val].size() - 1];
        int cum = 1;
        for(int i = from - 1; i >= cur; i--) {
            if(arr[i] != which_val) {
                arr[i + cum] = arr[i];
            }
            else cum++;
        } 

        for(int i = 0; i < len; i++) {
            arr[cur + i] = which_val;
        }

        ans += m;
        cur += len; 
        settled[which_val] = 1;

        vector<int> renew(19, 0);

        for(int i = cur; i < n; i++) {
            val[ arr[i] ][ renew[arr[i]]++ ] = i;
        }
    }

    cout << ans << "\n";
    
    // for(int x : arr) cout << x << " ";
    // cout <<"\n"; 
    // cleaning to be done here if required
    for(int i = 1; i < 19; i++) val[i].clear();
    for(int i = 1; i < 19; i++) settled[i] = 0;
}

signed main() {
    fast int t;
    input output
    cin >> t;
    while(t--) solve();
    return 0;
}