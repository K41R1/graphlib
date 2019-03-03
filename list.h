#ifndef __LINKED_LIST_X__
#define __LINKED_LIST_X__

#define NODE_VAL(n) (n->data)
#define SET_NODE_VAL(n,val) (n->data = val)
#define SET_NEXT_TO_NULL(n) (n->next = NULL)
#define SET_NEXT(n,elm) (n->next = elm);

#define GET_LAST_NODE(n) { \
  while (n->next != NULL) { \
    n = n->next;\
  }\
}

#define PRINT_LIST(list) {\
  int i = 0; \
  node_t tmp = list; \
  while (tmp != NULL) { \
    fprintf(stdout, "element %d: %c \n",i,tmp->data); \
    tmp = tmp->next; \
    i++; \
  } \
}

typedef struct node* head_t;
typedef struct node* node_t;
typedef struct node node;

struct node {
  char data;
  node_t next;
};

head_t list_init(char);
head_t empty_list_init();
int push_new_element(head_t, char);
int unshift_new_element(head_t*, char);
node_t make_node(char);
int get_list_length(head_t);

#endif /* end of include guard: __LINKED_LIST_X__ */
