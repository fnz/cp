#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <limits.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second

//template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a) { return a * a; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) {for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl; return cout; }
void print() { cout << endl; }
template<typename T, typename... Ts> void print(T x, Ts... xs) { cout << x << " "; print(xs...); };

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

template <typename number_type>
number_type gcd (number_type a, number_type b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template <typename number_type>
number_type lcm (number_type a, number_type b) {
    return (a/gcd (a, b))*b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vull a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vull lcm_(n + 1, 0);
    vull q(n + 1, INT_MAX);
    for (int t = 1; t <=n; t++) {
        for (int i = 1; i <= n - t + 1; i++) {
            if (lcm_[i] == 0) lcm_[i] = a[i];
            else lcm_[i] = lcm(lcm_[i], a[i + t - 1]);
            q[t] = min(q[t], lcm_[i]%1000000007);
        }
    }
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << q[t] << endl;
    }
}











