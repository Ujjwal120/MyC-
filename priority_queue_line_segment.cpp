#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);

using namespace std;

class Compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first); 
        }
};

vector<pair<int, int>> line;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

void solve() {
    int n;
    cin >> n;

    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>();
    line.resize(n);
    for(int i = 0; i < n; i++) cin >> line[i].first;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> line[i].second;

    for(int i = 0; i < n; i++) {
        pq.push({min(line[i].first, line[i].second), max(line[i].first, line[i].second)});
    }

    int ans = 0;
    while(!pq.empty()) {
        if(pq.size() == 1) {
            ans++; break;
        }

        auto one = pq.top();
        pq.pop();
        auto two = pq.top();

        if(one.second < two.first) {
            // no intersection
            ans++;
            continue;
        }
        else {
            pq.pop();
            pq.push({max(one.first, two.first), min(one.second, two.second)});
        }
    }

    cout << ans << "\n";
}

signed main() {
    input output
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}