#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//void makenullTree(Tree *pT){
//	(*pT)=NULL;
//}
//int emptyTree(Tree T){
//	return T==NULL;
//}
//Tree leftChild(Tree T){
//	return T->Left;
//}
//Tree rightChild(Tree T){
//	return T->Right;
//}
//void preOrder(Tree T){
//	if(emptyTree(T))
//		return;
//	else {
//		printf("%d ", T->Data);
//		preOrder(leftChild(T));
//		preOrder(rightChild(T));
//	}
//}
//void inOrder(Tree T){
//	if(emptyTree(T))
//		return;
//	else{
//		inOrder(leftChild(T));
//		printf("%d ", T->Data);
//		inOrder(rightChild(T));
//	}
//}
//void postOrder(Tree T){
//	if(emptyTree(T))
//		return;
//	else {
//		postOrder(leftChild(T));
//		postOrder(rightChild(T));
//		printf("%d ", T->Data);
//	}
//}
//int nb_nodes(Tree T){
//	if(emptyTree(T))
//		return 0;
//	else return 1+nb_nodes(leftChild(T))+nb_nodes(rightChild(T));
//}
Tree createTree(DataType x, Tree l, Tree r){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=l;
	T->Right=r;
	return T;
}
Tree createNode(DataType x){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=NULL;
	T->Right=NULL;
	return T;
}
Tree initTree(){
	Tree T;
	T=NULL;
	return T;
}
int isEmpty(Tree T){
	return T==NULL;
}
int getHeight(Tree T){
	if(T==NULL)
		return -1;
	int leftHeight=getHeight(T->Left)+1;
	int rightHeight=getHeight(T->Right)+1;
	if(leftHeight>rightHeight)
		return leftHeight;
	else return rightHeight;
}
int isLeaf(Tree T){
	if(T!=NULL){
		if(T->Left==NULL && T->Right==NULL)
			return 1;
	}
	return 0;
}
int getLeaves(Tree T){
	if(T==NULL)
		return 0;
	if(isLeaf(T))
		return 1;
	return getLeaves(T->Left)+getLeaves(T->Right);
}
int main(){
Tree T;
T=createTree(45,createTree(16,createTree(24,NULL,NULL),createTree(-12,
   createTree(5,NULL,NULL),createTree(8,createTree(6,NULL,NULL),NULL))),
   createTree(33,createTree(9,NULL,NULL),createTree(-60,NULL,NULL)));
printf("So nut la cua cay da cho: %d",getLeaves(T)); 
	return 0;
}
