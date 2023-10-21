#include <bits/stdc++.h>

#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Input: std::vector<int64_t> first (n), second (m)
// Usage: LongestCommonIncreasingSubsequence::constructFromInput().solve(); or LongestCommonIncreasingSubsequence(first, second).solve();
// Returns length of longest common increasing subsequence
class LongestCommonIncreasingSubsequence {
public:
    explicit LongestCommonIncreasingSubsequence(const std::vector<int64_t>& first, const std::vector<int64_t>& second): _first(first), _second(second) {}

    static LongestCommonIncreasingSubsequence constructFromInput() {
        int64_t n, m;
        std::cin >> n >> m;
        std::vector<int64_t> first (n), second (m);

        for (int64_t& x : first) std::cin >> x;
        for (int64_t& x : second) std::cin >> x;
        return LongestCommonIncreasingSubsequence(first, second);
    }

    int64_t solve() {
        auto n = (int64_t)_first.size();
        auto m = (int64_t)_second.size();
        int64_t dp[n + 1][m + 1];
        for (int64_t i = 0; i <= n; ++i) {
            for (int64_t j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int64_t i = 1; i <= n; ++i) {
            int64_t maxLengthForCurrentPrefix = 0;
            for (int64_t j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (_first[i - 1] == _second[j - 1] && dp[i - 1][j] < (maxLengthForCurrentPrefix + 1)) {
                    dp[i][j] = maxLengthForCurrentPrefix + 1;
                }
                if (_first[i - 1] > _second[j - 1] && dp[i - 1][j] > maxLengthForCurrentPrefix) {
                    maxLengthForCurrentPrefix = dp[i - 1][j];
                }
            }
        }
        int64_t answer = 0;
        for (int64_t i = 0; i <= m; ++i) {
            answer = std::max(answer, dp[n][i]);
        }
        return answer;
    }

private:
    std::vector<int64_t> _first;
    std::vector<int64_t> _second;
};

signed main() {
    fast_and_furious
    auto ans = LongestCommonIncreasingSubsequence::constructFromInput().solve();
    std::cout << ans << '\n';
}

