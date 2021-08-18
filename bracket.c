#include <stdio.h>
#include <stdlib.h>
struct stackNode
{
    int data;
    struct stackNode* nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;
int isEmpty(StackNodePtr* topPtr);
int getStackSize(StackNodePtr* topPtr);
int pop(StackNodePtr* topPtr);
void push(StackNodePtr* topPtr, int value);

int isValid(const char* s)
{
    StackNodePtr topPtr = NULL;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') // left part
        {
            push(&topPtr,s[i]);
        }
        else // right part
        {
            char topValue = pop(&topPtr);
            if (topValue == '(' && s[i] == ')')
            {
                continue;
            }
            else if (topValue == '[' && s[i] == ']')
            {
                continue;
            }
            else if (topValue == '{' && s[i] == '}')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    if (isEmpty(&topPtr))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef RunTests
int main()
{
    printf("%d", isValid("([)]"));
}
#endif



int getStackSize(StackNodePtr* topPtr)
{
    StackNodePtr tmpPtr = *topPtr;
    int count = 0;
    while (tmpPtr != NULL)
    {
        count++;
        tmpPtr = tmpPtr->nextPtr;
    }
    return count;
}
int isEmpty(StackNodePtr* topPtr)
{
    if (*topPtr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(StackNodePtr* topPtr)
{
    int pop_value;
    if (*topPtr != NULL)
    {
        StackNodePtr tmpPtr = *topPtr;
        pop_value = tmpPtr->data;
        *topPtr = (*topPtr)->nextPtr;
        free(tmpPtr);
    }

    return pop_value;
}

void push(StackNodePtr* topPtr, int value)
{
    StackNodePtr newPtr = (StackNodePtr)malloc(sizeof(StackNode));
    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("there is no memory for you to push!\n");
    }
    //printf("The %d is been push!\n", value);
}

