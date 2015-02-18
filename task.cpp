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

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

int n, m, w;
vi a;

bool check(int x) {
	int ms = 0;
	vi eff(n, 0);
	int effc = 0;
	forn(i, n) {
		if (i - w >= 0) effc -= eff[i - w];
		int diff = x - a[i] - effc;
		if (diff <= 0) continue;
		
		ms += diff;
		if (ms > m) return false;
		eff[i] = diff;
		effc += diff;	 
	}
	return ms <= m;
}

int main() {
	cin >> n >> m >> w;
	a.resize(n);
	forn(i, n) cin >> a[i];
	
	int l = 1;
	int r = *std::max_element(all(a)) + m;
	int x;
	while (l <= r) {
        int md = (l + r) >> 1;
        if (check(md)) {
            x = md;
            l = md + 1;
        } else
            r = md - 1;
    }
	cout << x;
}










