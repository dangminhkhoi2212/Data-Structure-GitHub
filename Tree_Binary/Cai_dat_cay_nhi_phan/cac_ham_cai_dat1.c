#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

void makenullTree(Tree *pT){
	(*pT)=NULL;
}
int emptyTree(Tree T){
	return T==NULL;
}
Tree leftChild(Tree T){
	if(!emptyTree(T))
		return T->Left;
	else return NULL;
}
Tree rightChild(Tree T){
	if(!emptyTree(T))
		return T->Right;
	else return NULL;
}
int idLeaf(Tree T){
	if(!emptyTree(T))
		return leftChild(T)==NULL && rightChild(T)==NULL;
	else return 0;
}
void preOrder(Tree T){
	if(!emptyTree(T)){
			printf("%d ", T->Data);
			preOrder(leftChild(T));
			preOrder(rightChild(T));
	}
}
void inOrder(Tree T){
	if(!emptyTree(T)){
		inOrder(leftChild(T));
		printf("%d ", T->Data);
		inOrder(rightChild(T));
	}
}
void postOrder(Tree T){
	if(!emptyTree(T)){
		postOrder(leftChild(T));
		postOrder(rightChild(T));
		printf("%d ", T->Data);
	}
}
int nb_nodes(Tree T){
	if(emptyTree(T))
		return 0;
	else return 1+nb_nodes(leftChild(T))+ nb_nodes(rightChild(T));
}
int nb_leaf(Tree T){
	if(emptyTree(T))
		return 0;
	if(leftChild(T)== NULL && rightChild(T)==NULL)
		return 1;
	else return nb_leaf(leftChild(T))+ nb_leaf(rightChild(T));
}
Tree createTree2(DataType v, Tree l, Tree r){
	Tree n;
	n=(struct Node*) malloc(sizeof(struct Node));
	n->Data=v;
	n->Left=l;
	n->Right=r;
	return n;
}
int main(){
	struct Node* root = createNode(21);
root->Left = createNode(6);
root->Right = createNode(7);    
root->Left->Left = createNode(-12);
root->Left->Right = createNode(4);    
root->Left->Left->Left = createNode(45);
root->Left->Left->Right = createNode(3);	
root->Left->Right->Right = createNode(18);
root->Right->Right = createNode(15); 	
printf("Duyet tien tu cay da cho: "); 
preOrder(root);
	return 0;
}
