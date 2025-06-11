#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}   node;

int main(void)
{
    node *list = NULL;
    for(int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
            return 1;
        printf("Number: ");
        scanf("%d", &(n)->number);
   
    //! n-> next = list;
    //! list = n;

        n->next = NULL;
        //if list is empty
        if(list == NULL)
            list = n;

        // if list hase number
        else
        {
            for(node *ptr = list; ptr != NULL; ptr= ptr ->next)
            {
                // if at end of list
                if(ptr ->next == NULL)
                {
                    ptr ->next =n;
                    break;
                }
            }
        }
    }

    //! node *ptr = list;
    //! while (ptr != NULL)
    //! {
    //!     printf("%d\n",ptr -> number);
    //!     ptr = ptr -> next;
    //! }
    for(node *ptr = list; ptr != NULL; ptr ->next)
    {
        printf("%d\n",ptr -> number);
        ptr = ptr -> next;
    }

    node *ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr ->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}