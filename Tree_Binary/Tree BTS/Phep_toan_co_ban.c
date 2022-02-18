#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int KeyType;
struct Node{
	KeyType Key;
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
}
Tree rightChild(Tree T){
	if(!emptyTree(T))
		return T->Right;
}
void preOrder(Tree T){
	if(T==NULL)
		return;
	else {
		printf("%d ", T->Key);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
//void inOrder(Tree T){
//	if(T==NULL)
//		return;
//	else {
//		inOrder(T->Left);
//		printf("%d ", T->Key);
//		inOrder(T->Right);
//	}
//}
void postOrder(Tree T){
	if(T==NULL)
		return;
	else {
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d ", T->Key);
	}
}
//Tree search(int x, Tree T){
//	if(T==NULL)
//		return NULL;
//	else if(x==T->Key)
//		return T;
//	else if(x<T->Key)
//			search(x, T->Left);
//	else if(x>T->Key)
//			search(x, T->Right);	
//}

KeyType deleteMin(Tree *pT){
	if((*pT)->Left== NULL && (*pT)->Right==NULL){
		KeyType temp=(*pT)->Key;
		(*pT)=NULL;
		return temp;
	}
	else return deleteMin(&((*pT)->Left));
}
void deleteNode(int x, Tree *pT){
	if((*pT)!=NULL){
		if(x<(*pT)->Key)
			deleteNode(x,&((*pT)->Left));
		else if(x>(*pT)->Key)
				deleteNode(x, &(*pT)->Right);
		else {
			if((*pT)->Left==NULL && (*pT)->Right==NULL)
				(*pT)=NULL;
			else if((*pT)->Right==NULL)
					(*pT)=(*pT)->Left;
			else if((*pT)->Left==NULL)
					(*pT)=(*pT)->Right;
			else (*pT)->Key=deleteMin(&(*pT)->Right);
		}
	}
}

		/* Bai 4*/
		
Tree search(int x, Tree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			search(x, T->Left);
	else if(x>T->Key)
			search(x, T->Right);
	else return T;
}
int getHeight(Tree T){
	if(T==NULL)
		return -1;
	else{
		int a=getHeight(T->Left)+1;
		int b=getHeight(T->Right)+1;
		if(a>b)
			return a;
		else return b;
	}
}
int hNode(int x, Tree T){
	if(!search(x, T))
		return -1;
	else{
		if(x<T->Key)
			return hNode(x, T->Left);
		else if(x>T->Key)
				return hNode(x, T->Right);
		else return getHeight(T);
	}
}

	/* Bai 5*/
Tree getMax(Tree T){
	if(T!=NULL){
		if(T->Right==NULL )
			return T;
		else return getMax(T->Right);
	}
	return NULL;	
}
Tree getMin(Tree T){
	if(T!=NULL){
		if(T->Left==NULL )
			return T;
		else return getMin(T->Left);
	}
	return NULL;	
}
Tree getPrevious(int x, Tree T){
	if(T!=NULL){
		
		if(x==T->Key)
				return getMax(T->Left);
		if(x==getMin(T->Right)->Key)
			return T;
		else if(x==getMin(T->Left)->Key)
			return NULL;
		else if(x<T->Key)
				return getPrevious(x, T->Left);
		else if(x>T->Key)
				return getPrevious(x, T->Right);
	}
	return NULL;
	
}
	/* Bai 6*/
void insertNode(int x, Tree *pT){
	if((*pT)==NULL){
		(*pT)=(struct Node*) malloc(sizeof(struct Node));
		(*pT)->Key=x;
		(*pT)->Left=NULL;
		(*pT)->Right=NULL;
	}
	else{
		if(x<(*pT)->Key)
			insertNode(x, &(*pT)->Left);
		else if(x>(*pT)->Key)
				insertNode(x, &(*pT)->Right);
	}
}
Tree createNode(int x){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Key=x;
	T->Left=NULL;
	T->Right=NULL;
	return T;
}
int isBST(Tree T){
    if(T==NULL)
        return 1;
	if(T->Left==NULL || T->Right==NULL)
		return 1;
	if(T->Left->Key>T->Key || T->Right->Key<T->Key)
		return 0;
	else{
		return isBST(T->Left) && isBST(T->Right);
	}
}
void inOrder(Tree T, char x[], int *len){
	if(T==NULL)
		return;
	else {
		x[*len++]=T->Key;
		printf("%d ", T->Key);
		inOrder(T->Left, x, len);
		inOrder(T->Right, x, len);
	}
}

int main(){
char infix[100];
char st[100];
int len=0;
fgets(infix,100,stdin);
if(infix[strlen(infix)-1]=='\n'){
    infix[strlen(infix)-1]='\0';
}
Tree T=createTree(infix);
printf("Bieu thuc trung to: ");
inOrder(T,st,&len);
st[len]='\0';
printf("%s", st);
	return 0;
}
