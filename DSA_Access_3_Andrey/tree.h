#ifndef H_TREE
#define H_TREE

#include <stdio.h>

struct tree
{
   tree (int _elem = 0, tree *_left = NULL, tree *_right = NULL)
      : elem (_elem), left (_left), right (_right) { }

   int elem;
   tree *left, *right;

   /// <summary>
   /// ������� �������� �� ������� � ���� f
   /// </summary>
   void print_leafs(FILE *f);

   /// <summary>
   /// ��������� ������ �� ����� f
   /// </summary>
   void input(FILE *f);
};

#endif // !H_TREE