#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

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

bool is_correct(const vector<pair<int, int>>& pos) {
    for (int i = 0; i < pos.size() - 1; ++i) {
        for (int j = i + 1; j < pos.size(); ++j) {
            if (pos[i].first == pos[j].first) return false;
            if (pos[i].second == pos[j].second) return false;
        }
    }
    return true;
}

struct Monster {
    int health;
    int attack;
    int index;

    bool operator<(const Monster& other) const {
        if (attack != other.attack) return attack < other.attack;
        if (health != other.health) return health < other.health;
        return index < other.index;
    }
};

void solve_test_case() {
    get(n)
    auto health = read(n);
    auto attack = read(n);
    vector<Monster> v_of_m;
    vector<int> close_left (n), close_right(n);
    vector<bool> dead(n, false);
    for (int i = 0; i < n; ++i) {
        close_left[i] = i - 1;
        close_right[i] = i + 1;
    }
    set<Monster> monsters;
    for (int i = 0; i < n; ++i) {
        Monster m;
        m.health = health[i];
        m.attack = attack[i];
        m.index = i;
        monsters.insert(m);
        v_of_m.push_back(m);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto cur = *monsters.begin();
        monsters.erase(cur);
        ans += cur.health;
        if (close_left[cur.index] >= 0) {
            auto& x = v_of_m[close_left[cur.index]];
            monsters.erase(x);
            x.health += cur.attack;
            monsters.insert(x);
        }
        if (close_right[cur.index] < n) {
            auto& x = v_of_m[close_right[cur.index]];
            monsters.erase(x);
            x.health += cur.attack;
            monsters.insert(x);
        }
    }
    cout << ans << '\n';

}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
