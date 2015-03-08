#include <iostream>
#include <sstream>
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

vector<string> operators;
map<string, int> precedence;

bool isOperator(const string token) {
    for (const auto& op : operators) {
        if (token == op) return true;
    }
    return false;
}

bool isOperator(char ch) {
    return isOperator(string(1, ch));
}

void process(const string& op, stack<int>& args) {
    int b = args.top(); args.pop();
    int a = args.top(); args.pop();
    int ret = 0;
    if (op == "-") {
        ret = a - b;
    } else if (op == "+") {
        ret = a + b;
    } else if (op == "*") {
        ret = a*b;
    } else if (op == "/") {
        ret = a/b;
    }
    args.push(ret);
}

int evaluate(queue<string>& q) {
    stack<int> args;
    while (!q.empty()) {
        auto token = q.front(); q.pop();
        if (isOperator(token)) {
            process(token, args);
        } else {
            args.push(atoi(token.c_str()));
        }
    }
    return args.top();
}

queue<string> tokenize(const string& s) {
    queue<string> ret;
    stringstream ss(s);
    string token = "";
    char ch;
    while (ss >> ch) {
        if (isdigit(ch)) {
            token += ch;
        } else if (isOperator(ch) || ch == '(' || ch == ')') {
            if (!token.empty()) ret.push(token);
            ret.push(string(1, ch));
            token = "";
        }
    }
    if (!token.empty()) ret.push(token);
    return ret;
}

queue<string> shuntingYard(queue<string>& q) {
    queue<string> ret;
    stack<string> op;
    while (!q.empty()) {
        auto token = q.front();
        q.pop();
        if (token == "(") {
            op.push("(");
        } else if (token == ")") {
            while (!op.empty()) {
                auto top = op.top();
                if (top != "(") {
                    ret.push(top);
                    op.pop();
                } else {
                    op.pop();
                    break;
                }
            }
        } else if (isOperator(token)) {
            while (!op.empty()) {
                auto top = op.top();
                if (precedence[top] >= precedence[token]) {
                    ret.push(top);
                    op.pop();
                } else {
                    break;
                }
            }
            op.push(token);
        } else {
            ret.push(token);
        }
    }
    while(!op.empty()) {
        ret.push(op.top());
        op.pop();
    }
    return ret;
}

int main() {
    operators = { "+", "-", "*", "/", "^" };
    precedence["-"] = 2;
    precedence["+"] = 2;
    precedence["*"] = 3;
    precedence["/"] = 3;
    precedence["^"] = 4;

    auto t = tokenize("(10+5)*6 - 2*3*(2 +2 + 2+ 2 + 2)");
    auto q = shuntingYard(t);
    auto q2 = q;
    while (!q.empty()) {
        cout << q.front() << " "; 
        q.pop();
    }
    cout << endl;
    cout << evaluate(q2);
}   










