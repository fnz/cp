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

const int maxn = 1000005;

int a[maxn];
int b[maxn];
int l[maxn];
int r[maxn];
int fen[maxn];

void add(int x, int val)
{
    for (int i = x + 1; i < maxn; i += i & (-i)) fen[i] += val;
}

int get(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= i & (-i)) ans += fen[i];
    return ans;
}

int sum(int x, int y)
{
    return get(y) - get(x);
}

int f(int l, int r, int x) {
	int cnt = 0;
	for(int i = l; i <= r; i++) {
		if (a[i] == x) cnt++;
	}
	return cnt++;
} 

int main() {
	int n;
	cin >> n;
	forn(i, n) { 
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);
	int sz = unique(b, b + n) - b;
	forn(i, n) a[i] = lower_bound(b, b + sz, a[i]) - b;

	for (int i = n-1; i >= 0; i--) {
		l[a[i]]++;
		add(l[a[i]], 1);
		r[i] = l[a[i]];
	}

	memset(l, 0, sizeof l);
    long long ans = 0;
    for (int i = 0; i < n; i ++) {
        add(r[i], -1);
        l[a[i]] ++;
        ans += sum(1, l[a[i]]);
    }

    cout << ans << endl;
    return 0;
}










