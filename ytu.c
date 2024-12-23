struct node* deletelast(struct node *head)
{
    if (head == NULL)
    {
        printf("Memory insufficient\n");
        return head;
    }
    if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct node *ptr = head;
        struct node *ptr1;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
 
    }
    printf("One node is deleted from the end\n");
    return head;
}
