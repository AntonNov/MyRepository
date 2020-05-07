struct TreeItem {
	struct TreeItem *left;
	struct TreeItem *right;
	char info;
};



struct TreeItem *root = NULL;


struct TreeItem * TreeAdd(struct TreeItem *root,
struct TreeItem *r, char info) {
	if (!r) {
		r = (struct TreeItem *)
			malloc(sizeof(struct TreeItem));

		if (!r) {
			printf("Не хватает памяти\n");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->info = info;

		if (!root)
			return r;

		if (info < root->info)
			root->left = r;
		else
			root->right = r;

		return root;
	}

	if (info < r->info)
		return TreeAdd(r, r->left, info);
	else
		return TreeAdd(r, r->right, info);

	return root;
}

void Tree_inorder(struct TreeItem *root) {
	if (!root)
		return;

	Tree_inorder(root->left);
	if (root->info)
		printf("%c ", root->info);
	Tree_inorder(root->right);
}

void Tree_preorder(struct TreeItem *root) {
	if (!root)
		return;

	if (root->info)
		printf("%c ", root->info);
	printf("(");
	Tree_preorder(root->left);
	printf(",");
	Tree_preorder(root->right);
	printf(")");
}
int Tree_preorder_count(struct TreeItem *root,
	int print) {
	if (!root)
		return 0;

	if (root->info && print)
		printf("%c ", root->info);
	var countl = Tree_preorder_count(root->left, 0);
	var countr = Tree_preorder_count(root->right, 0);
	if ((countl > 0 || countr > 0) && print) {
		printf("(");
		Tree_preorder_count(root->left, 1);
		if (countl > 0 && countr > 0)
			printf(",");
		Tree_preorder_count(root->right, 1);
		printf(")");
	}

	return countl + countr + 1;
}

void Tree_postorder(struct TreeItem *root) {
	if (!root)
		return;

	Tree_postorder(root->left);
	Tree_postorder(root->right);
	if (root->info)
		printf("%c ", root->info);
}

struct TreeItem *Tree_search(struct TreeItem *root, char key) {
	if (!root)
		return NULL;  /* пустое дерево */

	while (root->info != key) {
		if (key < root->info)
			root = root->left;
		else
			root = root->right;

		if (root == NULL)
			break;
	}

	return root;
}

void Tree_clear(struct TreeItem *root) {
	if (!root)
		return;

	Tree_clear(root->left);
	Tree_clear(root->right);

	free(root);
}

struct TreeItem * TreeItemCreate(char info) {
	struct TreeItem *item = (struct TreeItem *)
		malloc(sizeof(struct TreeItem));
	if (!item) {
		printf("Не хватает памяти\n");
		exit(0);
	}

	item->left = NULL;
	item->right = NULL;
	item->info = info;

	return item;
}

struct TreeItem * Tree_Add_not_rec(struct TreeItem *tree, char info) {
	if (!tree) {
		return TreeItemCreate(info);
	}

	struct TreeItem *root = tree;
	while (1) {
		if (root->info == info)
			return tree;

		if (info < root->info) {
			if (root->left)
				root = root->left;
			else {
				root->left = TreeItemCreate(info);
				return tree;
			}
		}
		Else {
			if (root->right)
				root = root->right;
			else {
				root->right = TreeItemCreate(info);
				return tree;
			}
		}
	}
}

void insert(struct TreeItem ** tree, struct TreeItem * item) {
	if (!(*tree)) {
		*tree = item;
		return;
	}
	if (item->val < (*tree)->val)
		insert(&(*tree)->left, item);
	else if (item->val >(*tree)->val)
		insert(&(*tree)->right, item);
}
