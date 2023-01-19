#include <bits/stdc++.h>

using namespace std;
// #define int64_t long long;

template<typename T = long long>
vector<T> read(long long n) {
    vector<T> v_to_read_in (n);
    for (long long i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

struct Vertice {
    int divisor;
    int start_val;
    int index;

    int get_val() const {
        return start_val / divisor;
    }

    Vertice(int start_val, int index): divisor(1), start_val(start_val), index(index) {}
    bool operator<(const Vertice& other) const {
        if (start_val / divisor != other.start_val / other.divisor) return start_val / divisor < other.start_val / other.divisor;
        // if (start_val != other.start_val) return start_val < other.start_val;
        return index < other.index;
    }
};

// template<typename T = long long>
// vector<vector<T>> read2(long long n, long long m) {
//     vector<vector<T>> v_to_read_in(n, vector<T>(m));
//     for (auto& v : v_to_read_in) {
//         for (T& el : v) {
//             cin >> v;
//         }
//     }
// }


void solve_test_case() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a = read(n);
    set<Vertice> vertices;
    for (int i = 0; i < n; ++i) {
        vertices.insert(Vertice(a[i], i));
    }
    int min_ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    int upper_bound = *max_element(a.begin(), a.end()) / k - *min_element(a.begin(), a.end()) / k;
    int lower_bound = *max_element(a.begin(), a.end()) / k - *min_element(a.begin(), a.end());
    lower_bound = max(0, lower_bound);
    if (lower_bound == upper_bound) {
        cout << lower_bound << '\n';
        return;
    }
    while (true) {
        auto el = *(--vertices.end());
        vertices.erase(el);
        if (el.divisor == k) break;
        el.divisor++;
        vertices.insert(el);
        int cr_ans = (--vertices.end())->get_val() - vertices.begin()->get_val();
        min_ans = min(min_ans, cr_ans);
        if (min_ans == lower_bound) {
            cout << lower_bound << '\n';
            return;
        }
    }

    cout << min_ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    long long number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}