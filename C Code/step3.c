// Push a digit onto the list
void pushInt(struct list* pList, int* counter, int i) {
  // Check if there are any free nodes in the list
  if (pList->length == 0) {
    // Allocate a block of nodes if the free space is empty
    allocateBlock(pList, counter, BLOCKSIZE);
  }
  // Check if i is odd or even
  if (i % 2 == 1) {
    // Store the digit on the first available node on the right of the head-side stack
    pList->left->next->i = i;
    // Move the left pointer to the next node
    pList->left = pList->left->next;
  } else {
    // Store the digit on the first available node on the left of the tail-side stack
    pList->right->prev->i = i;
    // Move the right pointer to the previous node
    pList->right = pList->right->prev;
  }
  // Decrement the length of the list
  pList->length--;
}

void pullInt(struct list* pList, int* counter, int i) {
  // Check if i is odd or even
  if (i % 2 == 0) {
    // Check that there is at least one even integer in the list
    if (pList->right != pList->tail) {
      // Replace the even integer in the node pointed by pList->right with -1
      pList->right->i = -1;
      // Move pList->right to pList->right->next
      pList->right = pList->right->next;
      // Increment the length of the free space
      pList->length++;
    }
  } else {
    // Check that there is at least one odd integer in the list
    if (pList->left != pList->head) {
      // Replace the odd integer in the node pointed by pList->left with -1
      pList->left->i = -1;
      // Move pList->left to pList->left->prev
      pList->left = pList->left->prev;
      // Increment the length of the free space
      pList->length++;
    }
  }
  // Check if the size of the free space is larger than BLOCKSIZE
  if (pList->length > BLOCKSIZE) {
    // Deallocate BLOCKSIZE free nodes from the free space
    deAllocateBlock(pList, counter, BLOCKSIZE);
  }
}

void clearList(struct list* pList, int* counter) {
  // Remove all digits in the head-side stack
  while (pList->left != pList->head) {
    pullInt(pList, counter, 1);
  }
  // Remove all digits in the tail-side stack
  while (pList->right != pList->tail) {
    pullInt(pList, counter, 0);
  }
  // Remove all free nodes
  deAllocateBlock(pList, counter, pList->length);
  // Free the list
  freeList(pList, counter);
}