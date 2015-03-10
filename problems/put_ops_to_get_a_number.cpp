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

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int getPrecedence(const string& s) {
    if (s == "-" || s == "+") return 1;
    return 2;
}

vector<string> toRPN(const vector<string>& tokens) {
    stack<string> op;
    vector<string> ret;
    for (int i = 0; i < tokens.size(); i++) {
        const auto& token = tokens[i];
        if (isOperator(token)) {
            while(!op.empty() && (getPrecedence(op.top()) >= getPrecedence(token))) {
                ret.push_back(op.top());
                op.pop();
            }
             op.push(token);
        } else {
            ret.push_back(token);
        }
    }

    while(!op.empty()) {
        ret.push_back(op.top());
        op.pop();
    }

    return ret;
}

int evaluate(const vector<string>& tokens) {
    stack<int> args;
    for (int i = 0; i < tokens.size(); i++) {
        auto token = tokens[i];
        if (isOperator(token)) {
            int b = args.top(); args.pop();
            int a = args.top(); args.pop();
            if (token == "+") args.push(a + b);
            else if (token == "-") args.push(a - b); 
            else if (token == "*") args.push(a*b);
            else args.push(a/b);
        } else {
            args.push(atoi(token.c_str()));
        }
    }
    return args.top();
}

void helper(const vector<string>& tokens, const vector<int>& v, int num, vector<string>& ret) {
    if (tokens.size() == 2*v.size() - 1) {
        if (evaluate(toRPN(tokens)) == num) {
            string str;
            for (int i = 0; i < tokens.size(); i++) {
                str += tokens[i];
            }
            ret.push_back(str);
        } 
    } else {
        vector<string> operators = { "+", "-", "*", "/" };
        for (int i = 0; i < 4; i++) {
            vector<string> newTokens(tokens);
            newTokens.push_back(operators[i]);
            newTokens.push_back(to_string(v[(tokens.size() + 1)/2]));
            helper(newTokens, v, num, ret);
        }
    }
}

vector<string> getEvaluations(const vector<int>& v, int num) {
    vector<string> tokens;
    tokens.push_back(to_string(v[0]));
    vector<string> ret;
    helper(tokens, v, num, ret);
    return ret;
}

int main() {
    // the task is to put +, -, * or / between numbers in a vector in such way, that they evaluate to a given number
    // the program should output all possible options on print No luck
    //
    // solution is to recursively cycle through all possible ways to arrange operators and evaluate them using shunting yard aglotithm

    vector<int> v = {6, 3, 3, 5};
    auto evaluations = getEvaluations(v, 10);
    if (evaluations.empty()) {
        cout << "No luck";
    }
    for (const auto& e : evaluations) {
        cout << e << endl;
    }
}











