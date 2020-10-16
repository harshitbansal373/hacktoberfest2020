#include <stdio.h> //Para printf

#include "list.h"

int main(int argc, char **argv)
{
    generic_linkedList *ptr = initialize_linkedList();

    for (int generic_value = 0; generic_value < 5; generic_value++)
    {
        ptr->push_head(ptr, generic_value);
        ptr->push_rear(ptr, generic_value);
    }

    ptr->show(ptr->head);

    printf("size_q: %d\n", ptr->size(ptr->head));

    return 0;
}