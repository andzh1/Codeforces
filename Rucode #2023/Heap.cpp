#include <bits/stdc++.h>

template<typename T>
struct Compatible {
    T value;

    bool operator<(const Compatible& other) const {
        return value < other.value;
    }
};

template<>
struct Compatible<int> {
    int value;

    bool operator<(const Compatible& other) const {
        return value < other.value;
    }
};

template<typename T>
struct Heap {
public:
    T GetMin() const {
        return _items.begin()->value;
    }

    void Insert(const T& element) {
        _items.insert({element});
    }

private:
    std::set<Compatible<T>> _items;

    
};


signed main() {
//    int n;
//    std::cin >> n;
    Heap<int> h;
    h.Insert({1});
    h.Insert(2);
    h.Insert(3);
    std::cout << h.GetMin() << '\n';
}
