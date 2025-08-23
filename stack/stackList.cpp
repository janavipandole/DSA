#include <iostream>
#include <list>

class Stack {
private:
    std::list<int> stackList;

public:
    // Push an element onto the stack
    void push(int value) {
        stackList.push_back(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (!stackList.empty()) {
            stackList.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
    }

    // Get the top element of the stack
    int top() {
        if (!stackList.empty()) {
            return stackList.back();
        } else {
            std::cout << "Stack is empty.\n";
            return -1; // Return an invalid value to indicate an error
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return stackList.empty();
    }

    // Get the size of the stack
    int size() {
        return stackList.size();
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << "\n";
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n";

    std::cout << "Stack size: " << stack.size() << "\n";
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}