#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stackPrincipal;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        stackPrincipal.push(val);

        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() {
        int val = stackPrincipal.top();

        if (val == minStack.top())
            minStack.pop();

        stackPrincipal.pop();
    }

    int top() {
        return stackPrincipal.top();
    }

    int getMin() {
        return minStack.top();
    }
};