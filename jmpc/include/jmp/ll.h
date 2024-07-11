#ifndef __JMPC_LL_H
#define __JMPC_LL_H

typedef struct ll_node {
  struct ll_node *next;
  struct ll_node *prev;
  void *data;
} llnode;

llnode *ll_new(void *data);
void ll_destroy(llnode *root);

llnode *ll_end(llnode *root);

#endif // __JMPC_LL_H
