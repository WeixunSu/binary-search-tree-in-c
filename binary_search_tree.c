#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void flushInputBuffer();

typedef struct _tnode{
	struct _tnode *lNode;
	struct _tnode *rNode;
	int value;
} tnode;

tnode *newNode(int value){
	tnode* new = (tnode*)malloc(sizeof(tnode));
	new->lNode = NULL;
	new->rNode = NULL;
	new->value = value;
	return new;
}

tnode *treeInsert(tnode *root, int value){
	/* If tree/subtree is empty */
	if (root == NULL) return newNode(value);
	/* If not empty */
	if (value < root->value){
		root->lNode = treeInsert(root->lNode, value);
	}else if (value > root->value) {
		root->rNode = treeInsert(root->rNode, value);
	}else{
		fprintf(stderr, "%d is already in the tree!\n", value);
	}
	return root;
}

/* Print tree from left to right */ 
void treeTraversal(tnode *root){
	if (root != NULL){
		treeTraversal(root->lNode);
		printf("%d\n", root->value);
		treeTraversal(root->rNode);
	}
	return;
}

tnode *treeSearch(tnode *root, int val){
	while (root != NULL && root->value != val){
		if (val < root->value) root = root->lNode;
		if (val > root->value) root = root->rNode;
	}
	return root;
}



int main(){
	tnode *root = NULL;
	int val,n;
	char ifAdd;

	printf("Enter nodes into a tree, enter any alpha to exit. \n");
	while ((n = scanf("%d", &val)) > 0){
		root = treeInsert(root, val);
	}
	
	
	printf("\nSearch whether a num exists in the tree.\nEnter a number to search, enter any alpha to exit.\n");
	
	flushInputBuffer();
	
	while ((n = scanf("%d", &val)) > 0){
		if (treeSearch(root, val) != NULL) printf("Number %d is already in the tree\n", val);
		else {
			printf("Number %d is not in the tree. Would you like to add it in? (y/n)\n", val);
			flushInputBuffer();
			scanf("%c", &ifAdd);
			switch (tolower(ifAdd)){
				case 'y':
					root = treeInsert(root, val);
					break;
				case 'n':
					break;
				default:
					printf("Invalid Input\n");
					break;
			}
		}
		printf("\nSearch whether a num exists in the tree.\nEnter a number to search, enter any alpha to exit.\n");
	}
	
	printf("\nPrint tree in sorted order: \n");
	treeTraversal(root);
	return 0;
}

/* Flush Input Buffer */
void flushInputBuffer(){
	getchar();
	fflush(stdin);
}
