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

template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a) { return a * a; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

vector<int> t;
int n;

void init (int nn) {
	n = nn;
	t.assign (n, 0);
}

int sum (int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta) {
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r) {
	return sum (r) - sum (l-1);
}

void init (vector<int> a) {
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

int main() {
	int n = 10;
	vi a;
	forn(i, n) a.pb(i);
	pv(a);

	init(a);
	pv(t);
}







