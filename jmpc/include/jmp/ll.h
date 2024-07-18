#ifndef __JMPC_LL_H
#define __JMPC_LL_H

#include <jmp/types.h>

typedef struct ll_node {
  struct ll_node *next;
  struct ll_node *prev;
  void *data;
} llnode;

#define ll_data(node, type) (type)node->data
#define ll_read(root, idx, type) (type)ll_get(root, idx)->data

llnode *ll_new(void *data);
void ll_destroy(llnode *root);

void ll_append(llnode *root, void *data);
llnode *ll_get(llnode *root, sz idx);
llnode *ll_end(llnode *root);
sz ll_len(llnode *root);

#endif // __JMPC_LL_H
