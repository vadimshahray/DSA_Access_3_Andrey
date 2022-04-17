#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include "tree.h"

int main()
{
   setlocale(0, "");

   FILE *f = NULL;
   errno_t err = fopen_s(&f, "in.txt", "r");

   if (f)
   {
      tree *t = new tree();
      t->input(f);
      fclose(f);

      fopen_s(&f, "out.txt", "w");
      t->print_leafs(f);
      fclose(f);

      printf_s("ОК");
   }
   else perror("Не удалось открыть файл с деревом");

   return 0 * _getch() + err;
}