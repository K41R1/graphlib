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