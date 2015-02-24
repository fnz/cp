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
#define pv(v) forz(i, sz(v)) cout << v[i] << " "; cout << endl;
#define pa(a, n) forz(i, n) cout << v[i] << " "; cout << endl;

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

ll f(int n, int m, ll x) {
	ll r = 0;
	x--;
	forz(i, n) r += min((ll)m, x/i);
	return r;
}

int main() {
	int n, m;
	ll k;
	cin >> n >> m >> k;
	ll l = 1;
	ll r = 1LL*n*m + 1;
	ll x;
	while(l < r) {
		x = (l + r) >> 1;
		if (f(n, m, x) < k) l = x + 1;
		else r = x;
	}
	cout << l - 1;
}








