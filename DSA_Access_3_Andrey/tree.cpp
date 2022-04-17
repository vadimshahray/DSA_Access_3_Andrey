#include <stdio.h>
#include "tree.h"
#include "stack.h"

void tree::print_leafs(FILE *f)
{
   if (!f) return;

   stack<tree> s;
   tree *t = this;

   do
   {
      if (!t)
      {
         t = s.top()->right;
         s.pop();
      }

      if (t)
      {
         if (!t->left && !t->right)
            fprintf_s(f, "%d ", t->elem);

         s.push(t);
         t = t->left;
      }

   } while (!s.empty());
}

void tree::input(FILE *f)
{
   if (!f) return;

   int v = 0; // Значение узла
   char c = 0; // Символ, считанный из файла
   stack<tree> s;
   tree *t = this; // Узел для перебора дерева

   fscanf_s(f, "%d", &t->elem);

   while (fscanf_s(f, "%c", &c, 1) != EOF)
   {
      switch (c)
      {
         case '[':
            s.push(t);
            if (fscanf_s(f, "%d", &v)) // Узел имеет левого потомка
               t = t->left = new tree(v); break;
         case ',':
            fscanf_s(f, "%d", &v); // Считываем правого потомка
            t = s.top()->right = new tree(v); break;
         default: // Поднимаемся вверх по поддереву
            t = s.top();
            s.pop();
      }
   }
}