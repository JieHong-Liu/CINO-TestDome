# CINO-TestDome
Cino SW intern test 


+ 前測利用TestDome來測驗應徵者的基本能力：
    + ![](https://i.imgur.com/UkLeuOi.png)

    ```c=
    #include <stdlib.h>
    #include <stdio.h>

    typedef struct Node {
        int value;
        struct Node* left;
        struct Node* right;
    } Node;

    int contains(const Node* root, int value)
    {
        // Waiting to be implemented
        if (!root) return 0;
        else
        {
            if (root->value < value)
            {
                return contains(root->right, value);
            }
            else if (root->value > value)
            {
                return contains(root->left, value);
            }
            else
            {
                return 1;
            }
        }
        return 0;
    }

    #ifndef RunTests
    int main()
    {
        Node n1 = { n1.value = 1, n1.left = NULL, n1.right = NULL };
        Node n3 = { n3.value = 3, n3.left = NULL, n3.right = NULL };
        Node n2 = { n2.value = 2, n2.left = &n1, n2.right = &n3 };

        printf("%d", contains(&n2, 3));
    }
    #endif

    ```
    2. string 括號匹配問題
    ![](https://i.imgur.com/znibATU.png)
    ```c=
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

    ```

    3. zigzag 印字串，網路上可查到PAYPAL出的面試題

