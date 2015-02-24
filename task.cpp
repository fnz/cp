#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define forz(i, n) fore (i, 1, n + 1)
#define forn(i, n) fore (i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define forit(i, a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pv(v) forn(i, sz(v)) cout << v[i] << " "; cout << endl;
#define pa(a, n) forn(i, n) cout << a[i] << " "; cout << endl;

template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a) { return a * a; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

vector<int> d;
vector<int> h;

int dist(int i, int j, const vector<int>& v) {
    int ret = 0;
    for (int t = i; t < j; t++) {
        ret += d[v[t]];
    } 
    return ret;
}

int energy(int i, int j, const vector<int>& v) {
    return 2*(h[v[i]] + h[v[j]]) + dist(i, j, v);
}

int main() {
    int n, m;
    cin >> n >> m;
    d = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    h= vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<pair<int, int>> days;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        days.push_back(make_pair(a - 1, b - 1));
    }

    for (auto p : days) {
        vector<int> t;
        if (p.first <= p.second) {
            for (int i = p.second + 1; i < d.size(); i++) {
                t.push_back(i);
            }
            for (int i = 0; i < p.first; i++) {
                t.push_back(i);
            }
        } else {
            for (int i = p.second + 1; i < p.first; i++) {
                t.push_back(i);
            }
        }
 
    int max = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = i + 1; j < t.size(); j++) {
            int e = energy(i, j, t);
            if (e > max) {
                max = e;
            }
        }
    }

    cout << max << endl; 

    }
}










