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

void ll_insert(llnode *root, sz idx, void *data) {
  llnode *node = ll_new(data);
  llnode *curr = ll_get(root, idx);
  
  node->prev = curr->prev;
  curr->prev->next = node;
  curr->prev = node;
  node->next = curr;
}

void ll_append(llnode *root, void *data) {
  llnode *node = ll_new(data);
  llnode *end = ll_end(root);
  
  end->next = node;
  node->prev = end;
}

llnode *ll_get(llnode *root, sz idx) {
  llnode *node = root;
  sz i = 0;
  
  while (node->next && i++ <= idx)
    node = node->next;
  
  return node;
}

sz ll_len(llnode *root) {
  llnode *node = root;
  sz size = 1;
  
  while (node->next) {
    node = node->next;
    size++;
  }
  
  return size;
}

llnode *ll_end(llnode *root) {
  llnode *node = root;
  
  while (node->next)
    node = node->next;
  
  return node;
}
