#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack(int size = MAX) 
    { 
        top = -1; 
    }
    bool isEmpty() 
    { 
        return top == -1; 
    }
    void push(char c) 
    { 
        arr[++top] = c; 
    }
    char pop() 
    { 
        return arr[top--]; 
    }
    char peek() 
    { 
        return arr[top]; 
    }
};

class IntStack
{
    int arr[MAX];
    int top;

public:
    IntStack() 
    { 
        top = -1; 
    }
    bool isEmpty() 
    { 
        return top == -1; 
    }
    void push(int x) 
    { 
        arr[++top] = x; 
    }
    int pop() 
    { 
        return arr[top--]; 
    }
};

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            s.push(c);

        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(')
                s.pop();
        }

        else
        {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int evaluatePostfix(string postfix)
{
    IntStack s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (isdigit(c))
            s.push(c - '0');

        else
        {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }

    return s.pop();
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
