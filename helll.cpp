#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define input freopen("test_output.txt", "r", stdin);
#define output freopen("pro_output.txt", "w", stdout);

int p = 1e9+7;

inline int mulmod(int a,int b) { 
    int x= a*b;
    if(x>=p) return x%p; return x;
}

inline int addmod(int a,int b){ return (a+b>=p?a+b-p:a+b); }

int maximumNumber(string A, vector<int> F){
    
    int l=-1;
    int r=-1;

    for(int i=0;i<A.length();i++){
        int index = A[i]-'0';
        if(F[index-1]>index){
            l=i;
            r=i;
            break;
        }
    }

    if(l!=-1){

        for(int i=r;i<A.length();i++){
            int index = A[i]-'0';
            if(F[index-1]>=index){
                r=i;
            }
            else break;
        }

        for(int i=l;i<=r;i++){
            if(i<A.length()){
                int index = A[i]-'0';
                A[i]  = F[index-1]+'0';
            }
        }
    }

    
    int ans = A[0] - '0';
    for(int i=1;i<A.length();i++){
        // ans = ans*10%p;
        ans = mulmod(ans, 10);
        // ans = (ans+(A[i]-'0'))%p;
        ans = addmod(ans, A[i]-'0');
    }
    return ans;
    
}

signed main(){
    input output
    int t;
    cin>>t;
    string A;

    while(t--){
        cin>>A;
        vector<int> F(9);
        for(int i=0;i<9;i++){
            cin>>F[i];
        }
        
        int result;
        result = maximumNumber(A,F);
        cout<<result<<endl;
    }

    return 0;
}