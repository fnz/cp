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
template<typename T> ostream& operator << (ostream& os, vector<T> v) {for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl; }
void print() { cout << endl; }
template<typename T, typename... Ts> void print(T x, Ts... xs) { cout << x << " "; print(xs...); };

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull> 

vector<vector<int>> m;

int area(int llx, int lly, int urx, int ury) {
    return (urx - llx + 1)*(ury - lly + 1);
}

bool ones(int llx, int lly, int urx, int ury) {
    for (int i = llx; i < urx + 1; i++) {
        for (int j = lly; j < ury + 1; j++) {
            if (!m[i][j]) return false;
        }
    }
    return true;
}
    
int main() {
    int n; cin >> n;
    m = vector<vector<int>>(5, vector<int>(5));
    int maxArea = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];
    for (int llx = 0; llx < n - 1; llx++) for (int lly = 0; lly < n - 1; lly++) 
        for (int urx = 1; urx < n; urx++) for (int ury = 1; ury < n; ury++) {
            int newArea = area(llx, lly, urx, ury);
            if ((newArea > maxArea) && (ones(llx, lly, urx, ury))) {rr
                maxArea = newArea;
            }
        }

    cout << maxArea;
}   










