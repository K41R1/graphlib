#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @cost O(1)
 * @param char d
 * @return   head
 */
head_t list_init(char d) {
  node_t h = (node_t)malloc(sizeof(node));
  if (!h) {
    fprintf(stderr, "error: malloc()\n");
    exit(1);
  }
  SET_NODE_VAL(h,d);
  return h;
}

/**
 * @cost O(1)
 * @return empty head
 */
head_t empty_list_init() {
  node_t h = (node_t)malloc(sizeof(node));
  if (!h) {
    fprintf(stderr, "error: malloc()\n");
    exit(1);
  }
  SET_NODE_VAL(h,0);
  SET_NEXT_TO_NULL(h);
  return h;
}

/**
 * add new element at the end
 * @cost O(n)
 * @param head_t l
 * @param char d
 * @return  int error|success
 */
int push_new_element(head_t l, char d) {
  node_t elm = (node_t)malloc(sizeof(node));
  node_t tmp = l;

  if (!elm) {
    fprintf(stderr, "error: malloc()\n");
    return -1;
  }

  if (tmp == NULL) {
    fprintf(stderr, "error: empty list\n");
    return -1;
  }

  SET_NODE_VAL(elm,d);
  GET_LAST_NODE(tmp);
  SET_NEXT(tmp, elm);
  SET_NEXT_TO_NULL(elm);
  return 1;
}

/**
 * add new element at the begining
 * @cost O(1)
 * @param head_t* l head reference
 * @param char d
 * @return   error|success
 */
int unshift_new_element(head_t *l, char d) {
  node_t elm = (node_t)malloc(sizeof(node));

  if (!elm) {
    fprintf(stderr, "error: malloc()\n");
    return -1;
  }

  SET_NODE_VAL(elm,d);
  SET_NEXT(elm, (*l));
  (*l) = elm;

  return 1;
}

/**
 * make_node
 * @cost O(1)
 * @param  d
 * @return  node_t
 */
node_t make_node(char d) {
  node_t n = (node_t)malloc(sizeof(node));
  if (!n) {
    fprintf(stderr, "cannot create a single node: malloc()\n");
    exit(1);
  }
  SET_NODE_VAL(n,d);
  SET_NEXT_TO_NULL(n);
  return n;
}

/**
 * @cost O(n)
 * @param  l
 * @return length
 */
int get_list_length(head_t l) {
  node_t tmp = l;
  int len = 0;
  while (tmp != NULL) {
    len++;
    tmp = tmp->next;
  }
  return len;
}
