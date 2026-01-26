#include <iostream>
#include <vector>

using namespace std;

void process_single_scenario() {
    int participant_count;
    cin >> participant_count;
    
    // The total number of matches is always 2 * n - 2.
    int total_games = (participant_count * 2) - 2;
    
    cout << total_games << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases > 0) {
        process_single_scenario();
        num_test_cases--;
    }

    return 0;
}