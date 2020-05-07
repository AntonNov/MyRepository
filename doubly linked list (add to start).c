struct ListItem {
  struct ListItem *prev;
  struct ListItem *next;
  int info;
};

//добавить элемент
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

//Удаление
struct ListItem* DeleteList(struct ListItem* list, struct ListItem* item) {
	if (!item)
		return list;
	if (item->next)
		item->next->prev = item->prev;

	if (item->prev)
		item->prev->next = item->next;
	else
		list = item->next;

	free(item);
	return list;
}

//Печать
void PrintList(struct ListItem* list) {

	while (list) {
		printf(“%d”, list->info);
		list = list->next;
	}
}

//Поиск
struct ListInfo* FindInList(struct ListItem* list, int info) {
	while (list) {
		if (list->info == info)
			return list;

		list = list->next;
	}

	return NULL;
}

//Удаление всего списка
struct ListItem* ClearList(struct ListItem* list) {
	struct ListItem* temp;
	while (list) {
		temp = list;
		list = list->next;
    free(temp);
	}

	return NULL;
}

