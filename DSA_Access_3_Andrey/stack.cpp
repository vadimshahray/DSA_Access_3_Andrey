#include <stdio.h>
#include "stack.h"
#include "item.h"
#include "tree.h"

template <typename T>
void stack<T>::push (T *e)
{
   _top = new item<T> (e, _top);
}

template <typename T>
T *stack<T>::top ()
{
   return _top->elem;
}

template <typename T>
void stack<T>::pop ()
{
   if (!empty ())
   {
      item<T> *t = _top;
      _top = t->next;

      delete t;
   }
}

template <typename T>
bool stack<T>::empty ()
{
   return !_top;
}

template <typename T>
void stack<T>::clear ()
{
   for (; !empty (); pop ());
}

template struct stack<tree>;