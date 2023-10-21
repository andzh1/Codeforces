#include <bits/stdc++.h>

using namespace std;

#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Returns longest common substring of 2 strings.
// Complexity - O(nm).
class LongestCommonSubstring {
public:
    LongestCommonSubstring(std::string first, std::string second): _first(std::move(first)), _second(std::move(second)) {}
    
    static LongestCommonSubstring constructFromInput() {
        std::string first, second;
        std::cin >> first >> second;
        return {first, second};
    }
    
    std::string solve() {
        std::vector<bool> dp [_first.size() + 1];
        for (int64_t i = 0; i <= _first.size(); ++i) {
            dp[i].resize(_second.size() + 1);
        }
        for (int64_t i = 0; i <= _first.size(); ++i) {
            dp[i][0] = false;
        }
        for (int64_t i = 0; i <= _second.size(); ++i) {
            dp[0][i] = false;
        }
        int64_t answerForPreviousPrefix[_first.size() + 1];
        int64_t answerForCurrentPrefix[_first.size() + 1];
        for (int64_t i = 0; i <= _first.size(); ++i) {
            answerForCurrentPrefix[i] = 0;
            answerForPreviousPrefix[i] = 0;
        }
        for (int64_t i = 1; i <= _second.size(); ++i) {
            for (int64_t j = 1; j <= _first.size(); ++j) {
                answerForCurrentPrefix[j] = std::max(answerForCurrentPrefix[j - 1], answerForPreviousPrefix[j]);
                if (_first[j - 1] == _second[i - 1]) {
                    answerForCurrentPrefix[j] = std::max(answerForCurrentPrefix[j], answerForPreviousPrefix[j - 1] + 1);
                }
                dp[j][i] = (answerForCurrentPrefix[j] % 2);
            }
            for (int64_t j = 1; j <= _first.size(); ++j) {
                answerForPreviousPrefix[j] = answerForCurrentPrefix[j];
            }
        }

        int64_t maxLength = 0, indexOfAnswer = 0;
        for (int64_t i = 1; i <= _first.size(); ++i) {
            if (answerForCurrentPrefix[i] > maxLength) {
                maxLength = answerForCurrentPrefix[i];
                indexOfAnswer = i;
            }
        }
        std::string answer;
        int64_t indexInFirstString = indexOfAnswer;
        auto indexInSecondString = (int64_t) _second.length();
        while (indexInFirstString > 0 && indexInSecondString > 0) {
            while(indexInSecondString > 0 &&
                  dp[indexInFirstString][indexInSecondString - 1] == dp[indexInFirstString][indexInSecondString]) {
                --indexInSecondString;
            }
            while(indexInFirstString > 0 &&
                  dp[indexInFirstString - 1][indexInSecondString] == dp[indexInFirstString][indexInSecondString]) {
                --indexInFirstString;
            }
            if (indexInFirstString != 0)
                answer.push_back(_first[indexInFirstString - 1]);
            --indexInFirstString;
            --indexInSecondString;
        }
        for (int64_t i = 0; i < answer.length() / 2; ++i) {
            std::swap(answer[i], answer[answer.length() - 1 - i]);
        }

        return answer;
    }
private:
    std::string _first;
    std::string _second;
};

signed main() {
    fast_and_furious
    cout << LongestCommonSubstring::constructFromInput().solve();
}

