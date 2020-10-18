Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 ->10 -> 5 -> 5 -> 8

ListNode* partition(ListNode* head, int x)
{
    ListNode *left = NULL, *right = NULL, *i = NULL, *j = NULL;
    while (head)
    {
        if (head->val < x)
        {
            if (!left) left = head, i = head;
            else i->next = head, i = i->next;
        }
        else
        {
            if (!right) right = head, j = head;
            else j->next = head, j = j->next;
        }
        head = head->next;
    }
    if (j) j->next = NULL;
    if (i) i->next = right;
    return (left) ? left : right;
}