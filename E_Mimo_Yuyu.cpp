#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve_mimo_yuyu() {
    long long n, m;
    int k;
    cin >> n >> m >> k;

    map<long long, int> column_counts;
    for (int i = 0; i < k; ++i) {
        long long r, c;
        cin >> r >> c;
        column_counts[c]++;
    }

    bool mimo_wins = false;
    
    // This loop is compatible with older C++ standards (C++11 and newer).
    for (auto const& pair : column_counts) {
        long long column = pair.first;
        int count = pair.second;

        // Tokens in column 1 cannot be moved and have a Grundy value of 0.
        // They do not affect the game's outcome.
        if (column == 1) {
            continue;
        }

        // The Grundy value g(c) for c>1 is a unique power of two.
        // The total Nim-sum is non-zero if and only if any g(c)
        // appears an odd number of times in the total XOR sum.
        if (count % 2 != 0) {
            mimo_wins = true;
            break; // A winning condition for the first player is found.
        }
    }

    if (mimo_wins) {
        cout << "Mimo\n";
    } else {
        cout << "Yuyu\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve_mimo_yuyu();
    }

    return 0;
}