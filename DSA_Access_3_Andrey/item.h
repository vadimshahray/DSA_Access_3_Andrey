#ifndef H_ITEM
#define H_ITEM

template <typename T>
struct item
{
   item(T *_elem, item *_next) : elem(_elem), next(_next) { }

   T *elem;
   item *next;
};

#endif // !H_ITEM