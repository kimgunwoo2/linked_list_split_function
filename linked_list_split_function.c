#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
   element data;
   struct ListNode *link;
}ListNode;

void insert_node(ListNode **phead, ListNode **p, ListNode *new_node) {
   ListNode *q;
   q = *p;

   if (*phead == NULL) {
      new_node->link = NULL;
      *phead = new_node;
      *p = new_node;
   }
   else {
      new_node->link = q->link;
      q->link = new_node;
      *p = new_node;
   }
}

void display(ListNode *head) {
   ListNode *p = head;
   printf("head ->");
   while (p != NULL) {
      printf("%d->", p->data);
      p = p->link;
   }
   printf("  NULL");
   printf("\n");
}

ListNode *create_node(element data, ListNode *link) {
   ListNode *new_node;
   new_node = (ListNode*)malloc(sizeof(ListNode));
   if (new_node == NULL) printf("메모리 할당 에러");
   new_node->data = data;
   new_node->link = link;
   return(new_node);

}
void split(ListNode *list1, ListNode **list2, ListNode **list3) {
   ListNode *r = NULL;
   ListNode *s = NULL;
   for (int i = 1; list1 != NULL; list1 = list1->link) {
      if (i % 2 == 0)
         insert_node(list3, &r, create_node(list1->data, NULL));
      if (i % 2 == 1)
         insert_node(list2, &s, create_node(list1->data, NULL));


      i = i + 1;
   }


}

int main(void)
{

   ListNode *list1 = NULL;
   ListNode *list2 = NULL;
   ListNode *list3 = NULL;
   ListNode *p = NULL;
   insert_node(&list1, &p, create_node(10, NULL));
   insert_node(&list1, &p, create_node(20, NULL));
   insert_node(&list1, &p, create_node(30, NULL));
   insert_node(&list1, &p, create_node(40, NULL));
   insert_node(&list1, &p, create_node(50, NULL));
   insert_node(&list1, &p, create_node(60, NULL));
   insert_node(&list1, &p, create_node(70, NULL));
   insert_node(&list1, &p, create_node(80, NULL));
   split(list1, &list2, &list3);
   printf("기존에 저장된 노드");
   display(list1);
   printf("홀수번째 노드");
   display(list2);
   printf("짝수번째 노드");
   display(list3);
}