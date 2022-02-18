#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left , *Right;
};
typedef struct Node* Tree;

void preOrder(Tree T){
	if(T==NULL)
		return;
	else {
		printf("%d ", T->Key);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
void inOrder(Tree T){
	if(T==NULL)
		return;
	else {
		inOrder(T->Left);
		printf("%d ", T->Key);
		inOrder(T->Right);
	}
}
void postOrder(Tree T){
	if(T==NULL)
		return;
	else {
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d ", T->Key);
	}
}
Tree createTree(int x, Tree l, Tree r){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Key=x;
	T->Left=l;
	T->Right=r;
	return T;
}
void insertNode(KeyType x, Tree *pNode){
	if((*pNode)==NULL){
		(*pNode)=(struct Node*)malloc(sizeof(struct Node));
		(*pNode)->Key=x;
		(*pNode)->Left=(*pNode)->Right=NULL;
	}
	else if(x<(*pNode)->Key)
			insertNode(x, &(*pNode)->Left);
	else if(x>(*pNode)->Key)
			insertNode(x, &(*pNode)->Right);
}
Tree search(KeyType x, Tree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			return searchNode(x, T->Left);
	else if(x>T->Key)
			return searchNode(x, T->Right);
	return T;
}

void printPath(int x,  Tree T){
	if(T==NULL)
		return;
	printf("%d ", T->Key);
	if(x==T->Key){
		printf(" -> Tim thay");
	}
	else if(T->Left==NULL && T->Right==NULL)
			printf(" -> Khong thay");
	else if(x<T->Key)
			printPath(x, T->Left);
	else if(x>T->Key)
			printPath(x, T->Right);

}
KeyType deleteMin(Tree *pT){
	if((*pT)->Left==NULL){
		KeyType temp=(*pT)->Key;
		(*pT)=NULL;
		return temp;
	}
	else return deleteMin(&(*pT)->Left);
}
void deleteNode(KeyType x, Tree *pT){
	if((*pT)==NULL)
		return;
	else if((*pT)->Left==NULL && (*pT)->Right==NULL)
			(*pT)=NULL;
	else if(x<(*pT)->Key)
			deleteNode(x, &(*pT)->Left);
	else if(x>(*pT)->Key)
			deleteNode(x, &(*pT)->Right);	
	else (*pT)->Key=deleteMin(&(*pT)->Right);	
}
int main(){
Tree T=NULL;

int x;

insertNode(27,&T);
insertNode(12,&T);
insertNode(40,&T);
insertNode(4,&T);
insertNode(20,&T);
insertNode(34,&T);
insertNode(30,&T); 
insertNode(50,&T); 
x=12;

deleteNode(50, &T);
inOrder(T);	
	return 0;
}

void insertNode(KeyType x, Tree *pT){
	(*pT)=(Tree)malloc(sizeof(struct Node));
    if((*pT)==NULL){
        (*pT)->Key=x;
        (*pT)->Left=NULL;
        (*pT)->Right=NULL;
    }
	(*pT)->Size=getSize((*pT));
    if(x<(*pT)->Key){
        insertNode(x,&((*pT)->Left));
    }
    else if(x>(*pT)->Key){
        insertNode(x,&((*pT)->Right));
    }
}