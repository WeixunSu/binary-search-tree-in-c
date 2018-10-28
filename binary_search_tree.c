#include <stdio.h>
#include <stdlib.h>

struct DoubleLinkedNode{
	struct DoubleLinkedNode* leftChild;
	struct DoubleLinkedNode* rightChild;
	int value;
};

struct DoubleLinkedNode* newNode(int value){
	struct DoubleLinkedNode* new = (struct DoubleLinkedNode*)malloc(sizeof(struct DoubleLinkedNode));
	new->leftChild = NULL;
	new->rightChild = NULL;
	new->value = value;
	return new;
}

struct Tree{
	struct DoubleLinkedNode* root;
};

struct DoubleLinkedNode* treeInsert(struct DoubleLinkedNode* root, int value){
	// If tree/subtree is empty
	if (root == NULL) return newNode(value);
	// If not empty
	if (value < root->value){
		printf("%d is to the left of %d \n", value, root->value);
		root->leftChild = treeInsert(root->leftChild, value);
	}else if (value > root->value) {
		printf("%d is to the right of %d \n", value, root->value);
		root->rightChild = treeInsert(root->rightChild, value);
	}else{
		printf("%d is already in the tree!\n", value);
	}
	return root;
}

// Print tree from left to right
void treeTraversal(struct DoubleLinkedNode* root){
	if (root != NULL){
		treeTraversal(root->leftChild);
		printf("%d\n", root->value);
		treeTraversal(root->rightChild);
	}
	return;
}

int main(){
	struct Tree t = {.root = NULL};

	printf("Insert node in random sequence: \n");
	t.root = treeInsert(t.root, 6);
	treeInsert(t.root, 3);
	treeInsert(t.root, 5);
	treeInsert(t.root, 1);
	treeInsert(t.root, 4);
	treeInsert(t.root, 2);

	printf("Print tree in sorted order: \n");
	treeTraversal(t.root);
	return 0;
}
