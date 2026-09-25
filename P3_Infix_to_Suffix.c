#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// Push Operation
void push(char ch)
{
    stack[++top] = ch;
}

// Pop Operation
char pop()
{
    return stack[top--];
}

// Peek Operation
char peek()
{
    return stack[top];
}

// Precedence
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 3;

    return 0;
}

int main()
{
    char infix[100], suffix[100];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            suffix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                suffix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }

        // Operator
        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                suffix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        suffix[j++] = pop();
    }

    suffix[j] = '\0';

    printf("Suffix Expression: %s\n", suffix);

    return 0;
}