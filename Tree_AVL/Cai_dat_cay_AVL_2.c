
#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	int Height;
	struct Node *Left, *Right;
};
typedef struct Node* AVLTree;
int max(int a, int b){
	return (a>b)? a: b;
}
int getHeight(AVLTree node){
	if(node==NULL)
		return -1;
	else return node->Height;
}
void printNLR(AVLTree T){
	if(T==NULL)
		return;
	else{
		printf("(%d - %d); ", T->Key, getBalance(T));
		printNLR(T->Left);
		printNLR(T->Right);
	}
}
void printLRN(AVLTree T){
	if(T==NULL)
		return;
	else {
		printLRN(T->Left);
		printLRN(T->Right);
		printf("(%d - %d); ", T->Key, T->Height);
	}
}
int getBalance(AVLTree T){
	if(T==NULL)
		return 0;
	else return getHeight(T->Left)-getHeight(T->Right);
}
AVLTree rightRotate(AVLTree node){
	AVLTree temp;
	temp=node->Left;
	node->Left=temp->Right;
	temp->Right=node;
	node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	temp->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	return temp;
}
AVLTree leftRotate(AVLTree node){
	AVLTree temp;
	temp=node->Right;
	node->Right=temp->Left;
	temp->Left=node;
	node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
	return temp;
}
AVLTree leftrightRotate(AVLTree node){
	node->Left=leftRotate(node->Left);
	return rightRotate(node);
}
AVLTree rightleftRotate(AVLTree node){
	node->Right=rightRotate(node->Right);
	return leftRotate(node);
}
AVLTree insertNode(KeyType x, AVLTree T){
	if(T==NULL){
		T=(struct Node*)malloc(sizeof(struct Node));
		T->Key=x;
		T->Left=NULL;
		T->Right=NULL;
	}
	else if(x<T->Key)
			T->Left=insertNode(x, T->Left);
	else if(x>T->Key)
			T->Right=insertNode(x, T->Right);
	else return T;
	T->Height=1+max(getHeight(T->Left), getHeight(T->Right));
	int balance=getBalance(T);
	if(balance>1 && x<T->Left->Key)
		return rightRotate(T);
	if(balance<-1 && x> T->Right->Key)
		return leftRotate(T);
	if(balance>1 && x>T->Left->Key)
		return leftrightRotate(T);
	if(balance <-1 && x<T->Right->Key)
		return rightleftRotate(T);
	return T;
}
void printHeight(int Height, AVLTree T){
	if(T==NULL)
		return ;
	else if(Height==getHeight(T))
			printf("%d ", T->Key);
	printHeight(Height, T->Left);
	printHeight(Height, T->Right);
}
int countNodes(AVLTree T){
	static int k=0;
	if(T==NULL)
		return 0;
	int balance=getBalance(T);
	if(-1<=balance && balance<=1){
		printf("%d ", T->Key);
		k++;
	}
	countNodes(T->Left);
	countNodes(T->Right);
	return k;
}
int main(){
	
AVLTree T = NULL;
int height; 
T=insertNode(50,T);
//T=insertNode(70,T);
T=insertNode(30,T);
T=insertNode(20,T);
T=insertNode(10,T);
T=insertNode(45,T);
//T=insertNode(80,T);
//T=insertNode(75,T);
//T=insertNode(100,T);
//T=insertNode(55,T);
printNLR(T);
printf("\n");
printf("\n%d", countNodes(T));
	return 0;
}
