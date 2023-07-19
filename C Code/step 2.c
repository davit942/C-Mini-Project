void allocateBlock(struct list* pList, int* counter, int nNodes) {
  // Iterate through the number of nodes to be added
  for (int i = 0; i < nNodes; i++) {
    // Allocate a new node using allocator
    struct node* newNode = allocator(sizeof(struct node), counter);
    // Set the i value of the new node to -1
    newNode->i = -1;
    // Link the new node to the existing ones in the list
    newNode->prev = pList->right;
    newNode->next = NULL;
    pList->right->next = newNode;
    pList->right = newNode;
    // Increase the length of the list by 1
    pList->length++;
  }
}