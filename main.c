#include <stdio.h>

struct list
{
   int elem = 0;
   list* next = NULL;
} *l = new list;

int input(list* t)
{
   FILE* file;
   int flag = 1;

   if (!fopen_s(&file, "in.txt", "r"))
   {
      for (list* p = t; !feof(file) && flag; )
      {
         p = p->next = new list;
         if (!fscanf_s(file, "%d", &p->elem)) 
            flag = 0;
      }
      fclose(file);
   }
   return flag;
}

void output(list* p, FILE* out)
{
   fprintf_s(out, "%d ", p->elem);
}

void reverse_rec(list* h, FILE* out) {
   list* p = h->next;
   if (p->next != NULL)
      reverse_rec(p, out);
   output(p, out);
}

int main()
{
   if (input(l))
   {
      FILE* out;
      if (!fopen_s(&out, "out.txt", "w"))
      {
         reverse_rec(l, out);
         fclose(out);
      }
   }
   else
      printf("Invalid data\n");

   return 0;
}