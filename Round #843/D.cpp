#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int modpow(const int& x, const int& power, const int& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}

struct SparceTable {
    vector<vector<int>> data_;

    SparceTable(const vector<int>& v) {
        int n = v.size();
        int logn = log2(n) + 1;
        data_ = vector<vector<int>>(logn + 1, vector<int>(n));
        data_[0] = v;
        for (int i = 1; i <= logn; ++i) {
            int pow = (1 << (i - 1));
            for (int j = 0; j + pow < n; ++j) {
                data_[i][j] = std::min(data_[i - 1][j], data_[i - 1][j + pow]);
            }
        }
    }

    // [left, right]
    int GetMinOnSegment(int left, int right) const {
        int len = right - left + 1;
        if (len == 1) return data_[0][left];
        int pow = 0;
        while ((1 << (pow + 1)) < len) ++pow;
        int ans1 = data_[pow][left];
        int ans2 = data_[pow][right - (1 << pow) + 1];
        return std::min(ans1, ans2);
    }

    // True, if on (left, right) interval there are no value greater then on left and right position
    bool NoMaxOnInterval(int left, int right) const {
        if (right - left == 1) {
            return true;
        }
        return GetMinOnSegment(left + 1, right - 1) <= data_[0][left]; // Assume that v[left] == v[right]
    }
};


template<typename T = int>
vector<T> read(int n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int>
vector<vector<T>> read(int n, int m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

template<typename T = int>
void sortv(vector<T>& v) {
    std::sort(v.begin(), v.end());
} 

bool is_prime(int x) {
    if (x == 2) return true;
    if (x == 3) return true;
    if (x == 5) return true;
    // if (x == 7) return true;
    // if (x == 11) return true;
    for (int i = 2; i <= sqrt(x) + 1; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve_test_case() {
    get(n)
    auto v = read(n);
    // int max_n = 0;
    // loop(n) {
    //     max_n = max(max_n, v[i]);
    // }
    // vector<int> primes;
    // for (int i = 2; i <= max_n; ++i) {
    //     if (is_prime(i)) primes.push_back(i);
    // }
    // int number_of_primes = primes.size();
    // vector<vector<int>> graph(n);
    // map<int, set<int>> adj_to_prime;
    // loop(n) {
    //     for (int j = 0; j < number_of_primes; ++j) {
    //         int prime = primes[j];
    //         if (v[i] % prime == 0) {
    //             graph[i].push_back(prime);
    //             adj_to_prime[prime].insert(i);
    //         }
    //     }
    // }
    get(start)
    get(term)
    --start;
    --term;
    if (start == term) {
        cout << "1\n" << start + 1 << '\n';
        return;
    }
    vector<int> parent_start(n, -1);
    vector<int> parent_end(n, -1);
    vector<int> dist_start(n, -1);
    vector<int> dist_end(n, -1);
    dist_start[start] = 0;
    dist_end[term] = 0;
    set<int> non_visited_start;
    loop(n) {
        if (i != start) non_visited_start.insert(i);
    }
    set<int> non_visited_end;
    loop(n) {
        if (i != start) non_visited_end.insert(i);
    }

    queue<int> to_process_start;
    queue<int> to_process_end;
    to_process_start.push(start);
    to_process_end.push(term);
    bool finish = false;
    int min_vertice = -1;
    int min_dist = 1e9;
    while (!finish && !to_process_start.empty() && !to_process_start.empty() && dist_end[start] < 0 && dist_start[term] < 0) {
        int cur = to_process_start.front();
        to_process_start.pop();
        vector<int> to_erase;
        for (const auto& next : non_visited_start) {
            if (__gcd(v[next], v[cur]) == 1) continue;
            if (next == cur) continue;
            dist_start[next] = dist_start[cur] + 1;
            parent_start[next] = cur;
            if (dist_end[next] != -1) {
                finish = true;
                min_vertice = next;
                min_dist = dist_end[next] + dist_start[next];
                break;
            }
            to_process_start.push(next);
            to_erase.push_back(next);
        }
        if (finish) break;
        for (const auto& x : to_erase) non_visited_start.erase(x);
        cur = to_process_end.front();
        to_process_end.pop();
        to_erase.clear();
        for (const auto& next : non_visited_end) {
            if (__gcd(v[next], v[cur]) == 1) continue;
            if (next == cur) continue;
            dist_end[next] = dist_end[cur] + 1;
            parent_end[next] = cur;
            if (dist_start[next] != -1) {
                finish = true;
                min_vertice = next;
                min_dist = dist_end[next] + dist_start[next];
                break;
            }
            to_process_end.push(next);
            to_erase.push_back(next);
        }
        for (const auto& x : to_erase) non_visited_end.erase(x);
    }
    while ((!to_process_start.empty() || !to_process_start.empty()) && dist_start[to_process_start.front()] + dist_end[to_process_end.front()] < min_dist) {
        int cur = to_process_start.front();
        to_process_start.pop();
        vector<int> to_erase;
        for (const auto& next : non_visited_start) {
            if (__gcd(v[next], v[cur]) == 1) continue;
            if (next == cur) continue;
            dist_start[next] = dist_start[cur] + 1;
            parent_start[next] = cur;
            if (dist_end[next] != -1) {
                if (dist_start[next] + dist_end[next] < min_dist) {
                    min_vertice = next;
                    min_dist = dist_start[next] + dist_end[next];
                }
            }
            to_erase.push_back(next);
        }
        for (const auto& x : to_erase) non_visited_start.erase(x);
        cur = to_process_end.front();
        to_process_end.pop();
        to_erase.clear();
        for (const auto& next : non_visited_end) {
            if (__gcd(v[next], v[cur]) == 1) continue;
            if (next == cur) continue;
            dist_end[next] = dist_end[cur] + 1;
            parent_end[next] = cur;
            if (dist_start[next] != -1) {
                if (dist_start[next] + dist_end[next] < min_dist) {
                    min_vertice = next;
                    min_dist = dist_start[next] + dist_end[next];
                }
            }
            to_erase.push_back(next);
        }
        for (const auto& x : to_erase) non_visited_end.erase(x);
    }

    // if (dist[term] == -1) {
    //     cout << "-1\n";
    //     return;
    // }
    if (min_vertice == -1) {
        cout << "-1\n";
        return;
    }
    cout << dist_end[min_vertice] + dist_start[min_vertice] + 1 << '\n';
    vector<int> answer;
    int cur = min_vertice;
    while (cur != start) {
        answer.push_back(cur + 1);
        cur = parent_start[cur];
    }
    answer.push_back(start + 1);
    reverse(answer.begin(), answer.end());
    cur = parent_end[min_vertice];
    while (cur != term) {
        answer.push_back(cur + 1);
        cur = parent_end[cur];
    }
    answer.push_back(term + 1);
    print(answer);

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    // cin >> tests;
    while(tests--) solve_test_case();
}
