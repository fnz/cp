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

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {};
};

int getMomentum(const std::vector<int>& v, int start, int len, bool rev) {
    int ret = 0;
    if (rev) {
        for (int i = start, j = len; i < start + len; i++, j--) {
            ret += v[i]*j;
        }
    } else {
        for (int i = start, j = 1; i < start + len; i++, j++) {
            ret += v[i]*j;
        }
    }
    return ret;
}

vector<int> staves(const std::string& s) {
    vector<int> ret;
    vector<int> elements;
    for (int i = 0; i < s.length(); i++) elements.push_back(s[i] - '0');
    int n = elements.size();
    int len = n/2;
    for (int k = len; k > 0; k--) {
        vector<pair<int, int>> momentums; 
        for (int i = 0; i < n - k + 1; i++) {
            momentums.push_back(make_pair(getMomentum(elements, i, k, false), i));
            momentums.push_back(make_pair(getMomentum(elements, i, k, true), i));
        }
        sort(momentums.begin(), momentums.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.first > b.first;
        });
        for (int i = 0; i < momentums.size() - 1; i++) {
            const auto& a = momentums[i];
            const auto& b = momentums[i + 1];
            if (a.first == b.first && abs(a.second - b.second) >= k) {
                ret.push_back(k);
                ret.push_back(a.second);
                ret.push_back(b.second);
                cout << a.first << " " << b.first << endl;
                return ret;
            }
        }
    }

    return ret;
}

int main() {
    /*auto root = new Node(4);
    auto rl = new Node(2);
    root->left = rl;
    auto rr = new Node(6);
    root->right = rr;
    auto rll = new Node(1);
    rl->left = rll;
    auto rlr = new Node(100);
    rl->right = rlr;*/
   
    string branch = "1141145545341111113434824524565345453405430955454545434222233453111";
    auto ret = staves(branch);
    cout << branch.substr(ret[1], ret[0]) << " " << branch.substr(ret[2], ret[0]);

}











