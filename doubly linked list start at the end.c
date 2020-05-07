
struct ListItem {
	struct ListItem *prev;
	struct ListItem *next;

	int data;
	...
};

struct List {
	struct ListItem *start;
	struct ListItem *end;
       int count;
}

//инициализация
void Init(struct List* list) {
	list->start = NULL;
	list->end = NULL;
}

//добавление в конец списка
void Add(struct List* list, int numb) {
	struct ListItem* temp = (struct ListItem*)malloc(sizeof(struct ListItem));
  
	temp->next = NULL;
	temp->prev = list->end;
	temp->data = numb;

	if (!list->start) {
		list->start = temp;
	}
	else {
		list->end->next = temp;
	}

	list->end = temp;
}

//удаление элемента
void Delete(struct List* list, struct ListItem* li) {
	if (!li)
		return;

	if (li->prev)
		li->prev->next = li->next;
	else {
		//deleting first item
		list->start = li->next;
		if (list->start)
			list->start->prev = NULL;
	}

	if (li->next)
		li->next->prev = li->prev;
	else {	
//deleting last item
		list->end = li->prev;
		if (list->end)
			list->end->next = NULL;
	}
	free(li);
}

//печать
void Print(struct List* list) {
	ListItem* li = list->start;
	while (li) {
		printf("%d ", li->data);
		...
			li = li->next;
	}
}

//поиск
ListItem* Find(struct ListItem* li, int numb) {
	while (li) {
		if (li->data == numb)
			return li;

		li = li->next;
	}

	return NULL;
}

ListItem* FindFirst(struct List* list, int numb) {
	ListItem* li = list->start;

	return Find(li, numb);
}

ListItem* from = FindFirst(&list, 55);
  while (from) {
	  from = Find(from->next, 55);
}

void DeleteItem(struct List* list, int numb) {
	ListItem* li = Find(list, numb);
	Delete(list, li);
}

void Clear(struct List* list) {
	ListItem* li = list->start, temp;
	 while (li){
     temp = li;
		 li = li->next;
		 free(temp);
	  }

	list->start = NULL;
	list->end = NULL;
}

void CopyList(struct List* listFrom,
struct List* listTo) {
	//Clear(listTo);

	ListItem* li = listFrom->start;
	while (li) {
		Add(listTo, li->data);
		li = li->next;
	}
}

