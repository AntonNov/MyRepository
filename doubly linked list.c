struct ListItem {
  struct ListItem *prev;
  struct ListItem *next;
  int info;
};
struct ListItem* AddList(struct ListItem* list, int info) {
  struct ListItem* item = (struct ListItem*) malloc(sizeof(struct ListItem));
  if (!item) {
    exit(-1);
  }
  item->info = info;
  if (list)
    list->prev = item;
  item->next = list;
  item->prev = NULL;
  return item;
}
