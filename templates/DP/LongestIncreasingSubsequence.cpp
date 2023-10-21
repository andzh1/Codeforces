#include <bits/stdc++.h>

using namespace std;

using String = std::string;

#define vi vector<int>
#define get(a) int a; cin >> a;
#define repeat(n) for(int i = 0; i < n; ++i)
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define foreach(val, container) for (const auto& val : container)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);



// Input: vector<int64_t> data (n)
// Usage: LongestIncreasingSubsequence::constructFromInput().solve(); or LongestIncreasingSubsequence(data).solve();
// Returns list of numbers from 1 to n - indices of longest increasing subsequence
class LongestIncreasingSubsequence {
public:
    explicit LongestIncreasingSubsequence(const std::vector<int64_t>& input): _data(input) {}

    static LongestIncreasingSubsequence constructFromInput() {
        int64_t n;
        std::cin >> n;
        std::vector<int64_t> input (n);

        for (int64_t& x : input) std::cin >> x;
        return LongestIncreasingSubsequence(input);
    }

    std::vector<int64_t> solve() {
        auto n = (int64_t)_data.size();
        std::vector<int64_t> minLastElementForLen (n + 1, INT64_MAX);
        minLastElementForLen[0] = INT64_MIN;
//        for (int64_t i = 0; i < n; ++i) {
//            _data[i] *= -1;
//        }

        int64_t positionOfLastElementForLen[n + 1];
        std::vector<int64_t> previousFor (n);
        int64_t lengthOfLDS = 0;

        positionOfLastElementForLen[0] = BAD_POSITION;

        for(int64_t i = 0; i < n; ++i) {
            int64_t indexToChange = get_index_to_change(minLastElementForLen, n, _data[i]);
            minLastElementForLen[indexToChange] = _data[i];
            positionOfLastElementForLen[indexToChange] = i;
            previousFor[i] = positionOfLastElementForLen[indexToChange - 1];
            lengthOfLDS = std::max(lengthOfLDS, indexToChange);
        }


        int64_t startPosition = positionOfLastElementForLen[lengthOfLDS];
        return get_answer(previousFor, startPosition);
    }


private:
    static int64_t get_index_to_change(std::vector<int64_t>& minLastElementForLen, int64_t n, int64_t replacement) {
        int64_t leftIndex = 0, rightIndex = n;
        while (rightIndex != leftIndex) {
            int64_t middleIndex = (leftIndex + rightIndex) / 2;
            if (minLastElementForLen[middleIndex] > replacement) {
                rightIndex = middleIndex;
            } else {
                leftIndex = middleIndex + 1;
            }
        }
        return rightIndex;
    }

    static std::vector<int64_t> get_answer(std::vector<int64_t> previousFor, int64_t start_index) {
        std::vector<int64_t> answer;
        int64_t currentPosition = start_index;
        while (currentPosition != BAD_POSITION) {
            answer.push_back(currentPosition + 1);
            currentPosition = previousFor[currentPosition];
        }

        for (int64_t i = 0; i < answer.size() / 2; ++i) {
            std::swap(answer[i], answer[answer.size() - 1 - i]);
        }
        return answer;
    }

    static const int64_t BAD_POSITION = -1;

    std::vector<int64_t> _data;
};

signed main() {
    fast_and_furious
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> data (n);
    for (auto& x : data) {
        std::cin >> x;
        x *= -1;
    }
    auto ans = LongestIncreasingSubsequence(data).solve();
    std::cout << ans.size() << '\n';
    for (auto& x : ans) std::cout << x << ' ';
    std::cout << '\n';
}

