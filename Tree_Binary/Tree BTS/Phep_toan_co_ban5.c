#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

void insertNode(int x, Tree *pT){
	if((*pT)==NULL){
		(*pT)=(struct Node*) malloc(sizeof(struct Node));
		(*pT)->Key=x;
		(*pT)->Left=(*pT)->Right=NULL;
	}
	else if(x<(*pT)->Key)
			insertNode(x, &((*pT)->Left));
	else if(x>(*pT)->Key)
			insertNode(x, &((*pT)->Right));
}

/* bai 1*/
Tree getMin(Tree T){
	if(T!=NULL){
		if(T->Left==NULL)
			return T;
		else return getMin(T->Left);
	}
	else return NULL;
}
Tree getMax(Tree T){
	if(T!=NULL){
		if(T->Right==NULL)
			return T;
		else return getMax(T->Right);
	}
	else return NULL;
}
Tree getNext(int x, Tree T){
	if(T==NULL)
		return NULL;
	else if(x==T->Key)
		return getMin(T->Right);
	else if(x==getMax(T->Left)->Key)
			return T;
	else if(x==getMax(T->Right)->Key)
			return NULL;
	else if(x<T->Key){
		return getNext(x, T->Left);
	}
	else if(x>T->Key)
			return getNext(x, T->Right);
}
/* bai 2*/
Tree rightSibling(int x, Tree T){
	if(T==NULL)
		return NULL;
	else if(T->Left!=NULL && x==T->Left->Key)
			return T->Right;
	else if(T->Right!=NULL && x==T->Right->Key)
			return T->Left;
	else if(x<T->Key)
			return rightSibling(x, T->Left);
	else if(x>T->Key)
			return rightSibling(x, T->Right);
	else return NULL;
}

/* bai 3*/
int isEmpty(Tree T){
	return T==NULL;
}
/* bai 4*/
Tree getPrevious(int x, Tree T){
	if(x==T->Key)
		return getMax(T->Left);
	else if(x==getMin(T->Left)->Key)
			return NULL;
	else if(x==getMax(T->Right)->Key || x==getMin(T->Right)->Key)
			return T;
	else if(x<T->Key)
			return getPrevious(x, T->Left);
	else if(x>T->Key)
			return getPrevious(x, T->Right);
	else return NULL;
}
/* bai 5*/
int max(int a, int b){
	return (a>b)?a:b;
}
int getHeight(Tree T){
	if(T==NULL)
		return -1;
	else return max(getHeight(T->Left)+1, getHeight(T->Right)+1);
}
int main(){
Tree T=NULL;
Tree p;
int x;

insertNode(27,&T);
insertNode(12,&T);
insertNode(40,&T);
insertNode(4,&T);
insertNode(20,&T);
insertNode(34,&T);
insertNode(30,&T); 
insertNode(50,&T); 
x=27;

p = getPrevious(x,T);
if (p==NULL)
   printf("%d khong co nut dung truoc",x);
else printf("Nut dung truoc la %d",p->Key);
return 0;
}
