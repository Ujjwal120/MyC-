#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("brute_output.txt", "w", stdout);

// #define int long long 
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    vector<pair<int, int>> all_pos;
    vector<int> curCount(n, 0);

    for(int i = 0; i < n; i++) {
        all_pos.push_back({arr[i]+k, i});
        if(arr[i] < k) all_pos.push_back({arr[i]+k, i});
        else all_pos.push_back({arr[i]-k, i});  
    }

    sort(all_pos.begin(), all_pos.end());

    int l = 0, r = 0;

    int cnt = 0;

    for(int i = 0; i < (int)all_pos.size(); i++) {
        if(curCount[all_pos[i].second] == 0) {
            cnt++;
        }
        curCount[all_pos[i].second]++;

        if(cnt == n) {
            break;
        }
        r++;
    }

    int ans = all_pos[r].first - all_pos[l].first;

    int sz = (int)all_pos.size();
    while(l < sz && r < sz) {
        if(curCount[all_pos[l].second] == 1) {
            cnt--;
        }

        curCount[all_pos[l].second]--;
        l++;

        if(cnt < n) {
            r++;
            while(r < sz) {
                if(curCount[all_pos[r].second] == 0) {
                    ans = min(ans, all_pos[r].first - all_pos[l].first);
                    curCount[all_pos[r].second]++;
                    cnt++;
                    break;
                }
                else {
                    curCount[all_pos[r].second]++;
                }
                r++;
            }
        }
        else {
            ans = min(ans, all_pos[r].first - all_pos[l].first);
        }
    }

    return ans;
}

void solve() {

}

signed main() {
    fast int t = 1;
    // input output
    // cin >> t;
    while(t--) solve();
    return 0;
}