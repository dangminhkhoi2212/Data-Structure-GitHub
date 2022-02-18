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
	/*bai 1*/
void printPath(int x, Tree T){
	if(T!=NULL){
		printf("%d ", T->Key);
		if(x==T->Key){
			printf("-> Tim thay");
		}	
		else if(x<T->Key)
			printPath(x, T->Left);
		else if(x>T->Key)
				printPath(x, T->Right);
	}
	else printf("-> Khong thay");
}

	/*bai 2*/
Tree searchNode(int x, Tree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			return searchNode(x, T->Left);
	else if(x>T->Key)
			return searchNode(x, T->Right);
	return T;
}
	/*bai 3*/
Tree getParent(int x, Tree T){
	if(T==NULL)
		return NULL;
	if(x==T->Left->Key || x==T->Right->Key)
		return T;
	else if(x<T->Key)
			return getParent(x, T->Left);
	else if(x>T->Key)
			return getParent(x, T->Right);
	else return NULL;
}
	/*bai 4*/
void posOrder(Tree T){
	if(T==NULL)
		return;
	else{
		posOrder(T->Left);
		posOrder(T->Right);
		printf("%d ", T->Key);
	}
}
	/*bai 5*/
void preOrder(Tree T){
	if(T==NULL)
		return;
	else{
		printf("%d ", T->Key);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
	/*bai 6*/
Tree initTree(){
	Tree T;
	T=NULL;
	return T;
}
int main(){
Tree T = initTree();
if (T==NULL) {
	printf("Da khoi tao thanh cong");
}
else{
	printf("Loi");
}
	return 0;
}
