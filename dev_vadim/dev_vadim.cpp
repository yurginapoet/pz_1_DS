#include <stdio.h>

struct list
{
   int elem = 0;
   list* next = NULL;
} *l = new list;

void input(list* t)
{
   FILE* f;

   if (!fopen_s(&f, "in.txt", "r"))
   {
      for (list* p = t; !feof(f); )
      {
         p = p->next = new list;
         fscanf_s(f, "%d", &(p->elem));
      }
      fclose(f);
   }
}

list* reverse(list* h)
{
   list* p = h->next->next ? reverse(h->next) : h->next;
   h->next->next = h;
   h->next = NULL;

   return p;
}

void output(list* t)
{
   FILE* f;

   if (!fopen_s(&f, "out.txt", "w"))
   {
      for (list* p = t; p->next != NULL; p = p->next)
         fprintf_s(f, "%d ", p->elem);

      fclose(f);
   }
}

int main()
{
   input(l);
   output(reverse(l));
   return 0;
}