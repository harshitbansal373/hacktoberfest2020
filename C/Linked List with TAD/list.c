#include <stdio.h> //Para printf

#include "list.h"

void linkedList_push_rear(generic_linkedList *self, const int info)
{

    Node *node_next = linkedList_malloc(Node);

    node_next->this_info = info;
    node_next->next = NULL;

    if (self->head != NULL)
    {
        Node *tmp_ptr = self->head;

        while (tmp_ptr->next != NULL)
            tmp_ptr = tmp_ptr->next;
        tmp_ptr->next = node_next;
    }
    else
        self->head = node_next;
}

void linkedList_push_head(generic_linkedList *self, const int info)
{
    Node *node_next = linkedList_malloc(Node);

    node_next->this_info = info;
    node_next->next = self->head;

    self->head = node_next;
}

void linkedList_show(Node *self)
{
    if (self != NULL)
    {
        printf("%d\n", self->this_info);
        linkedList_show(self->next);
    }
}

int linkedList_size(Node *self)
{
    if (self != NULL)
        return linkedList_size(self->next) + 1;
    return 0;
}

generic_linkedList *initialize_linkedList()
{
    generic_linkedList *tmp = linkedList_malloc(generic_linkedList);

    tmp->head = NULL;

    //Iniciando os métodos de acesso
    tmp->push_head = linkedList_push_head;
    tmp->push_rear = linkedList_push_rear;

    tmp->show = linkedList_show;
    tmp->size = linkedList_size;

    return tmp;
}
