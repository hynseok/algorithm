#include <stdio.h>

struct page {
  struct page* next;
  struct page* prev;
  int data;
};
struct page list[10000];
struct page* head;
int num_list;

void init() {
  head = 0;
  num_list = 0;
}

void add_list(int idx, int data) {
  struct page* p;

  p = &list[idx];
  p->data = data;
  if(head) {
    struct page* tail = head->prev;
    tail->next->prev = p;
    tail->next = p;
    p->prev = tail;
    p->next = head;
  } else {
    head = p;
    p->next = p;
    p->prev = p;
  }
  num_list++;
}

int main() {
  init();
  add_list(0,3);
  add_list(1,4);
  add_list(2,5);

  struct page* p;
  p = head;
  do {
    printf("%d", p->data);
    p = p->next;
  } while (p != head);
  printf("%d", head->data);
  head = head->next;
  printf("%d", head->data);
  add_list(3,6);
  p = head;
  do {
    printf("%d", p->data);
    p = p->next;
  } while (p != head);
  return 0;
}