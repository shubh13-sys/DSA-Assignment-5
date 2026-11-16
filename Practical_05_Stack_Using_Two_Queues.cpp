#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int value) {
        q2.push(value);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q1.pop();
    }

    int top() const {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() const {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
