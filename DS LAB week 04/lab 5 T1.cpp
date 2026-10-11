#include <iostream>
#include <string>
using namespace std;

// Node for dynamic stack
struct Node {
    char data;
    Node *next;
};

Node *top = NULL;

// Push a bracket into stack
void push(char value) {
    Node *p = new Node;

    p->data = value;
    p->next = top;
    top = p;
}

// Remove top element
char pop() {
    if (top == NULL)
        return '\0';

    Node *p = top;
    char value = p->data;

    top = top->next;
    delete p;

    return value;
}

// Check whether brackets match
bool isMatching(char open, char close) {
    if (open == '(' && close == ')')
        return true;

    if (open == '[' && close == ']')
        return true;

    if (open == '{' && close == '}')
        return true;

    return false;
}

// Check balanced brackets
bool isBalanced(string expression) {

    for (int i = 0; i < expression.length(); i++) {

        char ch = expression[i];

        // Opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {

            // No opening bracket available
            if (top == NULL)
                return false;

            char open = pop();

            // Brackets do not match
            if (!isMatching(open, ch))
                return false;
        }
    }

    // Stack must be empty
    return top == NULL;
}

int main() {

    string expression;

    cout << "Enter brackets: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}