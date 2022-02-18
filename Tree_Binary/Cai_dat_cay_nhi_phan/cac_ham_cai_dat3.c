#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

Tree initTree(){
	Tree T;
	T=NULL;
	return T;
}
int isEmpty(Tree T){
	return T==NULL;
}
Tree createNode(DataType x, Tree T){
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=NULL;
	T->Right=NULL;
	return T;
}
void preOrder(Tree T){
	if(T==NULL)
		return;
	else {
		printf("%d ", T->Data);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
void inOrder(Tree T){
	if(T==NULL)
		return;
	else{
		inOrder(T->Left);
		printf("%d ", T->Data);
		inOrder(T->Right);
	}
}
void postOrder(Tree T){
	if(T==NULL)
		return;
	else {
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d ", T->Data);
	}
}
Tree createTree(int x, Tree l, Tree r){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=l;
	T->Right=r;
	return T;
}
int max(int a, int b){
	return (a>b)?a:b;
}
int getHeight(Tree T){
	if(T==NULL)
		return -1;
	else return max(getHeight(T->Left)+1, getHeight(T->Right)+1);
}
int getLeaves(Tree T){
	static int count=0;
	if(T==NULL)
		return 0;
	else if(T->Left==NULL && T->Right==NULL)
			count++;
	getLeaves(T->Left);
	getLeaves(T->Right);
	return count;
}
int main(){
	
	return 0;
}
