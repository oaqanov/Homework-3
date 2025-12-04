#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::queue;
using std::stack;
using std::string;
using std::cout;
using std::endl;

// Task 1
// Use try-catch around v.at(index). If out of range, print and return -1.
int safeAccess(const vector<int>& v, int index) {
    try {
        return v.at(index); // throws std::out_of_range if invalid
    } catch (const std::out_of_range&) {
        cout << "Index out of range!" << endl;
        return -1;
    }
}

// Task 2
// Class template with two types, stores first and second.
// Constructor, getters, and isSame comparison.
template <typename T, typename U>
class PairHolder {
private:
    T first;
    U second;

public:
    // constructor to initialize both values
    PairHolder(const T& f, const U& s) : first(f), second(s) {}

    // getters
    T get_first() const { return first; }
    U get_second() const { return second; }

    // comparison: true if both values match
    bool isSame(const PairHolder<T, U>& other) const {
        return (first == other.first) && (second == other.second);
    }
};

// Task 3
// Valid parentheses/brackets using stack.
bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        // push openers
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            // if we see a closer with nothing open -> invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // check matching type
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // valid only if no unmatched openers remain
    return st.empty();
}

// Task 4
// Concatenate q1 then q2. Passed by value so originals unchanged.
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

#endif // PROBLEMS_H
