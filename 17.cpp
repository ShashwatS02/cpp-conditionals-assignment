#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n, rK, cK, rD, cD;
        cin >> n >> rK >> cK >> rD >> cD;

        long long ans;
        if (rK == rD) {
            ans = (cK < cD) ? cD : (n - cD);
        } else if (cK == cD) {
            ans = (rK < rD) ? rD : (n - rD);
        } else {
            auto far = [&](long long x){ return max(x, n - x); };
            ans = max(far(rD), far(cD));
        }
        cout << ans << '\n';
    }
    return 0;
}
