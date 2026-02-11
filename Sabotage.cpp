#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        int opponent_count;
        int max_ops;
        long long chef_score;
        cin >> opponent_count >> chef_score >> max_ops;

        vector<int> scores(opponent_count);
        for (int i = 0; i < opponent_count; ++i) {
            cin >> scores[i];
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int best_rank = opponent_count + 1;

        for (int ops = 0; ops <= max_ops; ++ops) {
            if (ops > opponent_count) {
                break;
            }

            long long new_chef_score = chef_score + (long long)ops * 100;
            
            int opponents_ahead = 0;
            // Manually count stronger opponents from the remaining pool
            for (int j = ops; j < opponent_count; ++j) {
                if (scores[j] > new_chef_score) {
                    opponents_ahead++;
                } else {
                    // Since scores are sorted, no more opponents will be stronger
                    break;
                }
            }
            
            int current_rank = opponents_ahead + 1;
            if (current_rank < best_rank) {
                best_rank = current_rank;
            }
        }
        cout << best_rank << "\n";
    }
    return 0;
}