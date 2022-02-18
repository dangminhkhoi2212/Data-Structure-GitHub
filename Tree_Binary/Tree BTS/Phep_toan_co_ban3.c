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
		(*pT)=(struct Node*)malloc(sizeof(struct Node));
		(*pT)->Key=x;
		(*pT)->Left=NULL;
		(*pT)->Right=NULL;
	}
	else if(x<(*pT)->Key)
			insertNode(x, &((*pT))->Left);
	else if(x>(*pT)->Key)
			insertNode(x, &((*pT))->Right);
}
	/* bai 1*/
int isEmpty(Tree T){
	return T==NULL;
}
	/* bai 2 */
Tree getParent(int x, Tree T){
	if(T==NULL)
		return NULL;
	else if(x==T->Left->Key || x==T->Right->Key)
			return T;
	else if(x<T->Key)
			return getParent(x, T->Left);
	else if(x>T->Key)
			return getParent(x, T->Right);
	else return NULL;
}

	/*bai 3*/
Tree rightSibling(int x, Tree T){
	if(T==NULL || T->Left==NULL || T->Right==NULL)
		return NULL;
	else if(x==T->Left->Key)
			return T->Right;
	else if(x==T->Right->Key)
			return T->Left;
	else if(x<T->Key)
			return rightSibling(x, T->Left);
	else if(x>T->Key)
			return rightSibling(x, T->Right);
	else return NULL;
}

	/* bai 4 */
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
	if(x==T->Key)
		return getMin(T->Right);
	else if(x==getMax(T)->Key)	
			return NULL;
	else if(x==getMax(T->Left)->Key)
			return T;
	else if(x<T->Key)
			return getNext(x, T->Left);
	else if(x>T->Key)
			return getNext(x, T->Right);
	else return NULL;
}

	/* bai 6 */
int getHeight(Tree T){
	if(T==NULL)
		return 0;
	else {
		int a=getHeight(T->Left)+1;
		int b=getHeight(T->Right)+1;
		if(a>b)
			return a;
		else return b;
	}
}
int hNode(int x, Tree T){
	if(T==NULL)
		return 0;
	else if(x==T->Key)
			return getHeight(T)-1;
	else if(x<T->Key)
			return hNode(x, T->Left);
	else if(x>T->Key)
			return hNode(x, T->Right);
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

x = 3;
printf("Chieu cao %d la %d",x,hNode(x,T));
	return 0;
}

