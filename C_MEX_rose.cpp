#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> cnt(n + 2);
        for(int i = 0, x; i < n; ++i) cin >> x, cnt[x]++;
        int op = 0;
        for(int i = 0; i < k; ++i) if(!cnt[i]) op++;
        op += cnt[k] > 0;
        cout << op << "\n";
    }
}
