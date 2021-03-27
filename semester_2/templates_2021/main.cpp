#include <iostream>
#include <vector>

using namespace std;

template<typename T> 
T max_(T a, T b) {
    if (a < b) return b;

    return a;
}

int main() {
    auto f = max_<int>;
    auto res = max_(42.07, 13.13);
    cout << res << endl;
    auto res2 = f(42, 13);

    float a;
    float b;
    max_(a, b);
    return 0;
}