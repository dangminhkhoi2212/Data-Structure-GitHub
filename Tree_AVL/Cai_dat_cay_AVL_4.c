#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	int Height;
	struct Node *Left , *Right;
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
	else return getHeight(T->Left)-getHeight(T->Right);
}
int isAVL(AVLTree T){
	return -1<=getBalance(T)&& getBalance(T)<=1;
}
AVLTree search(KeyType x, AVLTree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			return search(x, T->Left);
	else if(x>T->Key)
			return search(x, T->Right);
	return T;
}
void printNLR(AVLTree T){
	if(T==NULL)
		return;
	else {
		printf("(%d - %d); ", T->Key, getHeight(T));
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
		printf("(%d - %d); ", T->Key, getHeight(T));
	}
}
void printLeaves(AVLTree T){
	if(T==NULL)
		return;
	else if(T->Left==NULL && T->Right==NULL)
			printf("%d ", T->Key);
	printLeaves(T->Left);
	printLeaves(T->Right);
}
void printHeight(int x, AVLTree T){
	if(T==NULL)
		return;
	else if(x==T->Height)
			printf("%d ", T->Key);
	printHeight(x, T->Left);
	printHeight(x, T->Right);
}
AVLTree leftRotate(AVLTree T){
	AVLTree temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp=T->Right;
	T->Right=temp->Left;
	temp->Left=T;
	T->Height=1+max(getHeight(T->Left), getHeight(T->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
	return temp;
}
AVLTree rightRotate(AVLTree T){
	AVLTree temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp=T->Left;
	T->Left=temp->Right;
	temp->Right=T;
	T->Height=1+max(getHeight(T->Left), getHeight(T->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
	return temp;
}
AVLTree leftrightRotate(AVLTree T){
	T->Left=leftRotate(T->Left);
	return rightRotate(T);
}
AVLTree rightleftRotate(AVLTree T){
	T->Right=rightRotate(T->Right);
	return leftRotate(T);
}
AVLTree insertNode(KeyType x, AVLTree T){
	if(T==NULL){
		T=(struct Node*)malloc(sizeof(struct Node));
		T->Key=x;
		T->Left=NULL;
		T->Right=NULL;
		T->Height=0;
	}
	else if(x<T->Key)
			T->Left=insertNode(x, T->Left);
	else if(x>T->Key)
			T->Right=insertNode(x, T->Right);
	T->Height=1+max(getHeight(T->Left), getHeight(T->Right));
	int b=getBalance(T);
	if(b>1 && x<T->Left->Key)
		T=rightRotate(T);
	if(b<-1 && x>T->Right->Key)
			T=leftRotate(T);
	if(b>1 && x>T->Left->Key)
			T=leftrightRotate(T);
	if(b<-1 && x<T->Right->Key)
			T=rightleftRotate(T);
	return T;
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
//void Rotate()
AVLTree deleteNode(int x, AVLTree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			T->Left=deleteNode(x, T->Left);
	else if(x>T->Key)
			T->Right=deleteNode(x, T->Right);
	else {
		if(T->Left==NULL && T->Right==NULL)
			T=NULL;
		else if(T->Left==NULL){
			T=T->Right;
			T->Right=NULL;
		}	
		else if(T->Right==NULL){
			T=T->Left;
			T->Left=NULL;
		}		
		else T->Key=deleteMin(&T->Right);
	}
	updateHeight(&T);
	int b=getBalance(T);
	if(b>1 && x<T->Left->Key)
		T=rightRotate(T);
	if(b<-1 && x>T->Right->Key)
		T=leftRotate(T);
	if(b>1 && x>T->Left->Key)
		T=leftrightRotate(T);
	if(b<-1 && x<T->Right->Key);
		T=rightleftRotate(T);
	return T;
}

int main(){
AVLTree T = NULL;
int height; 
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
printNLR(T);
printf("\n");
T=deleteNode(10, T);

printLRN(T);

scanf("%d",&height);
printf("\nCac nut co cung chieu cao %d: ",height);
printHeight(height,T);
scanf("%d",&height);
printf("\nCac nut co cung chieu cao %d: ",height);
printHeight(height,T);
	return 0;
}
