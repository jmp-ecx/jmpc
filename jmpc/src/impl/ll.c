#include <jmp.h>

llnode *ll_new(void *data) {
  llnode* node = malloc(sizeof(llnode));
  if (!node) exit(-1);
  
  node->next = 0;
  node->prev = 0;
  node->data = data;

  return node;
}

void ll_destroy(llnode *root) {
  llnode *node = ll_end(root);
  
  while (node->prev) {
    node = node->prev;
    free(node->next);
  }
  free(node);
}

llnode *ll_end(llnode *root) {
  llnode *node = root;
  
  while (node->next) {
    node = node->next;
  }
  
  return node;
}
