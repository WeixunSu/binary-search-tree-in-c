#include <stdio.h>
#include <stdlib.h>

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
	// If tree/subtree is empty
	if (root == NULL) return newNode(value);
	// If not empty
	if (value < root->value){
		root->lNode = treeInsert(root->lNode, value);
	}else if (value > root->value) {
		root->rNode = treeInsert(root->rNode, value);
	}else{
		fprintf(stderr, "%d is already in the tree!\n", value);
	}
	return root;
}

// Print tree from left to right
void treeTraversal(tnode *root){
	if (root != NULL){
		treeTraversal(root->lNode);
		printf("%d\n", root->value);
		treeTraversal(root->rNode);
	}
	return;
}

int main(){
	tnode *root;
	int val,n;

	printf("Enter nodes into a tree, enter any alpha to exit. \n");
	while (n = scanf("%d", &val) > 0){
		root = treeInsert(root, val);
	}
	
	printf("Print tree in sorted order: \n");
	treeTraversal(root);
	return 0;
}
