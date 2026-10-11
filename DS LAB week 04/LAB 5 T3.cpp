#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Node for dynamic stack
struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

// Push value into stack
void push(int value) {

    Node *p = new Node;

    p->data = value;
    p->next = top;

    top = p;
}

// Pop value from stack
int pop() {

    if (top == NULL)
        return 0;

    Node *p = top;

    int value = p->data;

    top = top->next;

    delete p;

    return value;
}

// Return top value
int peek() {

    if (top == NULL)
        return 0;

    return top->data;
}

// Perform operation
int calculate(int a, int b, char op) {

    if (op == '+')
        return a + b;

    if (op == '-')
        return a - b;

    if (op == '*')
        return a * b;

    if (op == '/')
        return a / b;

    return 0;
}

// Evaluate postfix expression
int evaluatePostfix(string postfix) {

    int values[26];
    bool entered[26] = {false};

    for (int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // If operand is a variable
        if (isalpha(ch)) {

            int index = toupper(ch) - 'A';

            // Ask value only once
            if (!entered[index]) {

                cout << "Enter value of "
                     << char('A' + index) << ": ";

                cin >> values[index];

                entered[index] = true;
            }

            push(values[index]);
        }

        // If operator
        else {

            int b = pop();
            int a = pop();

            int result = calculate(a, b, ch);

            push(result);
        }
    }

    return pop();
}

int main() {

    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result;

    return 0;
}