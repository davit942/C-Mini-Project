void* allocator(int size, int* counter) {
  // Allocate memory for a single node using malloc
  void* p = malloc(size);
  // Increment the counter for each successful allocation
  (*counter)++;
  // Return the pointer to the allocated memory
  return p;
}

void deAllocator(void* p, int* counter) {
  // Free the memory pointed to by p using free
  free(p);
  // Decrement the counter for each successful deallocation
  (*counter)--;
}

void initialiseList(struct list *pList, int *counter) {
  // Allocate memory for the head and tail nodes using allocator
  pList->head = allocator(sizeof(struct node), counter);
  pList->tail = allocator(sizeof(struct node), counter);
  // Initialize the values of the fields in the list structure
  pList->head->next = pList->tail;
  pList->tail->prev = pList->head;
  pList->head->prev = NULL;
  pList->tail->next = NULL;
  pList->head->i = 0;
  pList->tail->i = 0;
  pList->left = pList->head;
  pList->right = pList->tail;
  pList->length = 0;
}

void freeList(struct list* pList, int* counter) {
  // Free the head and tail of the list using deAllocator
  deAllocator(pList->head, counter);
  deAllocator(pList->tail, counter);
  // Set all pointers in the list to NULL
  pList->head = NULL;
  pList->left = NULL;
  pList->tail = NULL;
  pList->right = NULL;
  // Set the length of the list to -1
  pList->length = -1;
}
