void skipMdeleteN(struct node  *head, int M, int N)
{
    struct node *curr = head, *t;
    int count;
 
    // The main loop that traverses through the whole list
    while (curr)
    {
        // Skip M nodes
        for (count = 1; count<M && curr!= NULL; count++)
            curr = curr->next;
 
        // If we reached end of list, then return
        if (curr == NULL)
            return;
 
        // Start from next node and delete N nodes
        t = curr->next;
        for (count = 1; count<=N && t!= NULL; count++)
        {
            struct node *temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t; // Link the previous list with remaining nodes
 
        // Set current pointer for next iteration
        curr = t;
    }
}
