#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


int safeAccess(const vector<int>& v, int index) {
    try {
        return v.at(index); 
    } catch (const out_of_range& e) {
        cout << "Index out of range!" << endl;
        return -1;
    }
}

template <typename T, typename U>
class PairHolder {
private:
    T first;
    U second;

public:
    PairHolder(T f, U s) : first(f), second(s) {}

    T get_first() const { return first; }
    U get_second() const { return second; }

    bool isSame(const PairHolder<T, U>& other) {
        return (first == other.first && second == other.second);
    }
};


bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

queue<int> unionQueues(queue<int> q1, queue<int> q2) {
    queue<int> result;

    while (!q1.empty()) {
        result.push(q1.front());
        q1.pop();
    }

    while (!q2.empty()) {
        result.push(q2.front());
        q2.pop();
    }

    return result;
}

#endif
