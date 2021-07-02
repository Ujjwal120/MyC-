#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);

#define int long long 
using namespace std;

string bit, temp;
vector<pair<int, int>> clo;
vector<int> clo_ind, ans_ind, prefsum;

void solve() {

    int n, k;
    cin >> n >> k;
    cin >> bit;
    temp = bit;
    
    // check all zero string 
    bool all_zero = true, all_one = true;
    clo.clear(); clo_ind.clear(); ans_ind.clear(); 
    // prefsum.clear();

    for(int i = 0; i < n; i++) {
        if(bit[i] == '0') all_one = false;
        else all_zero = false;
    }

    for(int i = n-1; i >= 0; i--) {
        if(bit[i] == '1') {
            temp += bit.substr(0, i);
            break;
        }
    }

    if(all_zero || all_one) {
        // do your thing 
        cout << k-1 << "\n";
        return;
    }
    
    int one = 0, zero = 0;
    for(int i = 0; i < temp.length(); i++) {
        if(temp[i] =='1') {
            if(zero != 0) {
                clo.push_back({-zero, 0});
                zero = 0;
            }
            one++;
        }
        else {
            if(one != 0) {
                clo.push_back({one, i-one});
                one = 0;
            }
            zero++;
        }
    }

    if(one != 0) clo.push_back({one, n-one});
    if(zero != 0) clo.push_back({-zero, 0});

    // prefsum.resize(clo.size(), 0);

    // prefsum[0] = abs(clo[0].first);

    // for(int i = 1; i < clo.size(); i++) {
    //     prefsum[i] = prefsum[i-1] + abs(clo[i].first);
    // }

    for(auto x : clo) cout << x.first << " ";
    cout << "\n";

    int m = -1, cum = 0;
    for(auto x : clo) {
        if(x.first > 0) m = max(m, x.first);
        cum += abs(x.first);
        if(cum >= n) break;
    }

    cum = 0;
    for(int i = 0; i < clo.size(); i++) {
        if(clo[i].first == m) clo_ind.push_back(i);
        cum += abs(clo[i].first);
        if(cum >= n) break;
    }
    
    // cout << clo_ind.size() << "\n";
    ans_ind.push_back(clo_ind[0]);

    for(int i = 1; i < clo_ind.size(); i++) {
        int ind_next = clo_ind[i];
        int ind_prev = ans_ind.back();

        bool handeled = false;
        cum = clo[ans_ind[0]].first;
        
        // int cnt = 0;
        
        for(int j = 1 ; cum < n ; j++) {
            if(i+1 != clo_ind.size()) {
                if(j > (ind_next - ind_prev)) break;
            }
            
            cum += abs(clo[ans_ind[0] + j].first);

            if(clo[ans_ind[0] + j].first < clo[ind_next + j].first) {
                handeled = true;
                ans_ind.clear();
                ans_ind.push_back(ind_next);
                break;
            }
            else if(clo[ans_ind[0] + j].first > clo[ind_next + j].first) {

                if(j <= ind_next - ind_prev) ans_ind.resize(1);

                handeled = true;
                break;
            }
        }

        // cout << "\n";

        if(!handeled) 
            ans_ind.push_back(clo_ind[i]);
        // cout << ans_ind.size() << " ";

    }

    // cout << "\n";

    cout << ans_ind.size() << "\n";

    cum = 0;
    for(int j = 0; cum < n; j++) {
        cum += abs(clo[ans_ind[0] + j].first);
        if(clo[ans_ind[0] + j].first < clo[ans_ind[ans_ind.size() - 1] + j].first) {
            // handeled = true;
            int pus = ans_ind.back();
            ans_ind.clear();
            ans_ind.push_back(pus);
            break;
        }
        else if(clo[ans_ind[0] + j].first > clo[ans_ind[ans_ind.size()-1] + j].first) {
            ans_ind.resize(1);
            break;
        }
    }

    cout << ans_ind.size() << "\n";

    int ans = clo[ans_ind[0]].second;
    k--;

    ans += (ans_ind.size() != 1) ? k * (clo[ans_ind[1]].second - clo[ans_ind[0]].second) : k * n;
    
    cout << ans << "\n";

}

signed main() {
    fast int t;
    // input 
    output
    cin >> t;
    while(t--) solve();
    return 0;
}