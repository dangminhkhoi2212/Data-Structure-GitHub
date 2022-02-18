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
	return (a>b)? a:b;
}
int getHeight(AVLTree T){
	if(T==NULL)
		return -1;
	else return T->Height;
}
int getBalance(AVLTree T){
    if(T==NULL)
        return 0;
    return getHeight(T->Left)-getHeight(T->Right);
}
AVLTree searchNode(KeyType x, AVLTree node){
	if(node==NULL)
		return NULL;
	else if(x<node->Key)
			return searchNode(x, node->Left);
	else if(x>node->Key)
			return searchNode(x, node->Right);
	return node;
}
void printNLR(AVLTree T){
	if(T==NULL)
		return;
	else{
		printf("(%d - %d); ",T->Key, getHeight(T));
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
		printf("(%d - %d); ", T->Key, getBalance(T));
	}
}

AVLTree rightRotate(AVLTree node){
	AVLTree temp;
	temp=node->Left;
	node->Left=temp->Right;
	temp->Right=node;
	node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
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
AVLTree createNode(KeyType x, AVLTree node){
	node=(struct Node*)malloc(sizeof(struct Node));
	node->Key=x;
	node->Left=NULL;
	node->Right=NULL;
	node->Height=0;
	return node;
}
AVLTree Rotate(KeyType x,int balance, AVLTree node){
	if(balance>1 && x<node->Left->Key)
		node=rightRotate(node);
	if(balance< -1 && x>node->Right->Key)
		node=leftRotate(node);
	if(balance>1 && x>node->Left->Key)
		node=leftrightRotate(node);
	if(balance<-1 && x<node->Right->Key)
		node=rightleftRotate(node);
	return node;
}
AVLTree insertNode(KeyType x, AVLTree node){
	if(node==NULL)
		node=createNode(x, node);
	else if(x<node->Key)
			node->Left=insertNode(x, node->Left);
	else if(x>node->Key)
			node->Right=insertNode(x, node->Right);
	else return node;
	node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	int balance=getBalance(node);
	node=Rotate(x, balance, node);
	return node;
}


KeyType deleteMin(AVLTree *pT){
	if((*pT)!=NULL){
		if((*pT)->Left==NULL){
			KeyType temp=(*pT)->Key;
			(*pT)=NULL;
			return temp;
		}
		else return deleteMin(&(*pT)->Left);
	}
}
KeyType deleteMax(AVLTree *pT){
	if((*pT)!=NULL){
		if((*pT)->Right==NULL){
			KeyType temp=(*pT)->Key;
			(*pT)=NULL;
			return temp;
		}
		else return deleteMax(&(*pT)->Right);
	}
}
void updateHeight(AVLTree *pT){
	if((*pT)==NULL)
		return;
	else {
		(*pT)->Height=1+max(getHeight((*pT)->Left), getHeight((*pT)->Right));
		updateHeight(&(*pT)->Left);
		updateHeight(&(*pT)->Right);
	}
}

AVLTree deleteNode(KeyType x, AVLTree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			T->Left=deleteNode(x, T->Left);
	else if(x>T->Key)
			T->Right=deleteNode(x, T->Right);
	else {
		if(T->Left==NULL && T->Right==NULL){
			T=NULL;
		}
		else if(T->Left==NULL)
				T=T->Right;
		else if(T->Right==NULL)
				T=T->Left;
		else {
			T->Key=deleteMax(&T->Left);
		}
	}
	return T;
}
//AVLTree Rotate_2(int b,int bleft,int bright,AVLTree T){
//	if(T==NULL)
//		return ;
//	else if(b>2 && )
//	
//}
//	(*pT)=deleteNode(x, (*pT));
//	updateHeight(&(*pT));
//void delete_Rotate(int x,AVLTree *pT){
//	if((*pT)==NULL)
//		return ;
//	int b=getBalance((*pT));
//	int bleft=getBalance((*pT)->Left);
//	int bright=getBalance((*pT)->Right);
//	(*pT)=Rotate_2(b, bleft, bright, T);
//}
int countNodes(AVLTree T){
	static int k=0;
	if(T==NULL)
		return 0;
	int balance=getBalance(T);
	if(-1==balance || balance==1 | balance==0){
		printf("%d ", T->Key);
		k++;
	}
	countNodes(T->Left);
	countNodes(T->Right);
	return k;
}
int main(){
AVLTree T = NULL;
T=insertNode(50,T);
T=insertNode(70,T);
T=insertNode(30,T);
T=insertNode(10,T);
T=insertNode(20,T);
T=insertNode(45,T);
T=insertNode(80,T);
T=insertNode(75,T);
T=insertNode(100,T);
T=insertNode(55,T);
printLRN(T);
printf("\n");
printf("\n%d", countNodes(T));
	return 0;
}
