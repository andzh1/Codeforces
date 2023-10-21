#include <bits/stdc++.h>

using namespace std;

#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Input: int64_t rucksackSize, vector<int64_t> data (n) - weights of n items
// Usage: Rucksack::constructFromInput().solve(); or Rucksack(data).solve();
// Returns maximum total weight of items that is less than rucksackSize
class Rucksack {
public:
    explicit Rucksack(int64_t rucksackSize, const std::vector<int64_t>& input): _rucksack_size(rucksackSize), _items(input) {}

    static Rucksack constructFromInput() {
        int64_t n, rucksackSize;
        std::cin >> rucksackSize >> n;
        std::vector<int64_t> input (n);

        for (int64_t& x : input) std::cin >> x;
        return Rucksack(rucksackSize, input);
    }

    int64_t solve() {
        auto N = (int64_t)_items.size();
        int64_t dp[N + 1][_rucksack_size + 1];

        for (int64_t i = 0; i < _rucksack_size + 1; ++i) {
            dp[0][i] = INT64_MIN;
            for (int64_t j = 1; j <= N; ++j) {
                dp[j][i] = 0;
            }
        }
        dp[0][0] = 0;
        for (int64_t i = 1; i <= N; ++i) {
            for (int64_t maxWeight = 1; maxWeight <= _rucksack_size; ++maxWeight) {
                dp[i][maxWeight] = dp[i - 1][maxWeight];
                if (maxWeight - _items[i - 1] >= 0)
                    dp[i][maxWeight] = std::max(dp[i][maxWeight], dp[i - 1][maxWeight - _items[i - 1]] + _items[i - 1]);
            }
        }
        int64_t answer = INT64_MIN;
        for (int64_t i = 0; i <= _rucksack_size; ++i) {
            answer = std::max(answer, dp[N][i]);
        }
        return answer;
    }


private:
    int64_t _rucksack_size;
    std::vector<int64_t> _items;
};

signed main() {
    fast_and_furious
    auto ans = Rucksack::constructFromInput().solve();
    std::cout << ans << '\n';
}

