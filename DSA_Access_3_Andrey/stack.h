#ifndef H_STACK
#define H_STACK

#include "item.h"

template <typename T>
struct stack
{
   private:
   item<T> *_top = NULL;

   public:
   /// <summary>
   /// Добавляет элемент e в стек
   /// </summary>
   void push (T *e);

   /// <summary>
   /// Выталкивает верхний элемент из стека
   /// </summary>
   void pop ();

   /// <summary>
   /// Возвращает верхний элемент стека
   /// </summary>
   T *top ();

   /// <summary>
   /// Проверяет, пустой ли стек
   /// </summary>
   bool empty ();

   /// <summary>
   /// Очищает стек
   /// </summary>
   void clear ();
};

#endif // !H_STACK