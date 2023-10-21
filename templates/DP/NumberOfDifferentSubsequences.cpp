#include <bits/stdc++.h>

#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// @param std::vector<int64_t> input (n)
// Usage: NumberOfDifferentSubsequences::constructFromInput().solve(); or NumberOfDifferentSubsequences(data).solve();
// Returns number of different subsequences in data, mod MODULO,
class NumberOfDifferentSubsequences {
public:
    explicit NumberOfDifferentSubsequences(const std::vector<int64_t>& data): _data(data) {}

    static NumberOfDifferentSubsequences constructFromInput() {
        int64_t n;
        std::cin >> n;
        std::vector<int64_t> data (n);

        for (int64_t& x : data) std::cin >> x;
        return NumberOfDifferentSubsequences(data);
    }

    int64_t solve() {
        int64_t answerForPrefix[_data.size() + 1]; // answerForPrefix[i] - number of different sequences that end up in inputSequence[i].
        std::map<int64_t, int64_t> positionsOfValue; // positionsOfValue[x] - all positions of value x

        int64_t currentSum = 0;
        answerForPrefix[0] = 0;
        for (int64_t i = 1; i <= _data.size(); ++i) {
            answerForPrefix[i] = 1 + currentSum;
            answerForPrefix[i] -= positionsOfValue[_data[i - 1]];
            positionsOfValue[_data[i - 1]] += answerForPrefix[i];
            currentSum = (currentSum + answerForPrefix[i] + MODULO) % MODULO;
        }

        return currentSum;
    }

private:
    static const int64_t MODULO = 1e9 + 7;
    std::vector<int64_t> _data;
};

signed main() {
    fast_and_furious
    auto ans = NumberOfDifferentSubsequences::constructFromInput().solve();
    std::cout << ans << '\n';
}

