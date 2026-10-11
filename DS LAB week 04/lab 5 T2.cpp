#include <iostream>
#include <string>
using namespace std;

// Node for dynamic stack
struct Node {
    char data;
    Node *next;
};

Node *top = NULL;

// Push into stack
void push(char value) {
    Node *p = new Node;

    p->data = value;
    p->next = top;
    top = p;
}

// Pop from stack
char pop() {
    if (top == NULL)
        return '\0';

    Node *p = top;
    char value = p->data;

    top = top->next;
    delete p;

    return value;
}

// Return top element
char peek() {
    if (top == NULL)
        return '\0';

    return top->data;
}

// Check operator priority
int precedence(char op) {

    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

// Check whether character is operator
bool isOperator(char ch) {

    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' || ch == '^')
        return true;

    return false;
}

// Convert infix to postfix
string infixToPostfix(string infix) {

    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        // If operand, directly add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (top != NULL && peek() != '(') {
                postfix += pop();
            }

            // Remove '('
            if (top != NULL)
                pop();
        }

        // Operator
        else if (isOperator(ch)) {

            while (top != NULL &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch)) {

                postfix += pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != NULL) {
        postfix += pop();
    }

    return postfix;
}

int main() {

    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}