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

   int v = 0; // �������� ����
   char c = 0; // ������, ��������� �� �����
   stack<tree> s;
   tree *t = this; // ���� ��� �������� ������

   fscanf_s(f, "%d", &t->elem);

   while (fscanf_s(f, "%c", &c, 1) != EOF)
   {
      switch (c)
      {
         case '[':
            s.push(t);
            if (fscanf_s(f, "%d", &v)) // ���� ����� ������ �������
               t = t->left = new tree(v); break;
         case ',':
            fscanf_s(f, "%d", &v); // ��������� ������� �������
            t = s.top()->right = new tree(v); break;
         default: // ����������� ����� �� ���������
            t = s.top();
            s.pop();
      }
   }
}