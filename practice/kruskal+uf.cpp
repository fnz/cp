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
#include <initializer_list>
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

class Graph {
public:
    struct Edge {
        Edge(int ex, int ey, int ew) : x(ex), y(ey), w(ew) { }
        int x;
        int y;
        int w;
    };
    std::vector<int> v;
    std::vector<Edge> e;
};

ostream& operator<< (ostream& os, Graph g) {
    cout << "Verts:" << endl;
    for (const auto& v : g.v) {
        cout << v << " ";
    }
    cout << endl << "Edges:" << endl;
    for (const auto& e : g.e) {
        cout << "(" << e.x << ", " << e.y << ") " << e.w << endl;
    }
    return os;
}

template<typename T>
class UnionFind {
public:
    UnionFind(std::initializer_list<T> l) {
        int maxId = 0;
        for (auto it = l.begin() ; it != l.end() ; ++it) {
            id[*it] = maxId++;
        }

        p = vector<int>(l.size(), -1);
    }

    UnionFind(std::vector<T> v) {
        int maxId = 0;
        for (auto it = v.begin() ; it != v.end() ; ++it) {
            id[*it] = maxId++;
        }

        p = vector<int>(v.size(), -1);
    }

    int find(T x) {
        int ret = id[x];
        vector<int> path;
        while(p[ret] != -1) {
            path.push_back(ret);
            ret = p[ret];
        }
        for (const auto& id : path) {
            p[id] = ret;
        }
        return ret;
    }

    void unite(T x, T y) {
        p[find(x)] = find(y);
    }

private:
    unordered_map<T, int> id;
    vector<int> p;
};

int main() {
    int n; cin >> n;
    Graph g;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        g.v.push_back(v);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.e.push_back(Graph::Edge(x, y, w));
    }
    print(g);

    Graph s;
    s.v = g.v;
    auto e = g.e;
    sort(e.begin(), e.end(), [](const Graph::Edge& a, const Graph::Edge& b) -> bool {
        return a.w < b.w;
    });

    UnionFind<int> uf(g.v);
    for (int i = 0; i < e.size(); i++) {
        const auto& edge = e[i];
        cout << uf.find(edge.x) << " " << uf.find(edge.y) << endl;
        if (uf.find(edge.x) != uf.find(edge.y)) {
            s.e.push_back(edge);
            uf.unite(edge.x, edge.y);
            cout << uf.find(edge.x) << " " << uf.find(edge.y) << endl;
            cout << "--" << endl;
        }
    }

    print(s);

}  











