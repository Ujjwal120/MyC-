#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define output freopen("test_output.txt","w",stdout);
// #define int long long 

using namespace std;

void generate() {  
    int sz = rand()%8 + 1;
    int k = rand()%5 + 1;
    cout << sz << " " << k << "\n";
    
    for(int i = 0; i < sz; i++) {
        cout << (char)('a'+rand()%k);
    }
    cout << "\n";
}

signed main() {
    fast int t;
    output
    cin >> t;
    cout << t << "\n";
    while(t--) generate();
    return 0;
}