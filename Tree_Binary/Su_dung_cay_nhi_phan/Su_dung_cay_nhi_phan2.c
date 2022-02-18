#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;
void makenullTree(Tree *pT){
	(*pT)=NULL;
}
int emptyTree(Tree T){
	return T==NULL;
}
Tree createNode(int x){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=NULL;
	T->Right=NULL;
	return T;
}
Tree createTree(int x, Tree l, Tree r){
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Left=l;
	T->Right=r;
	return T;
}
Tree leftChild(Tree T){
	if(!emptyTree(T))
		return T->Left;
	else return NULL;
}
Tree rightChild(Tree T){
	if(!emptyTree(T))
		return T->Right;
	else return NULL;
}
void preOrder(Tree T, int x[], int *len){
	if(T==NULL)
		return;
	else{
		printf("%d ", T->Data);
		x[*len]=T->Data;
		(*len)++;
		preOrder(T->Left, x, len);
		preOrder(T->Right, x, len);
	}
}

void inOrder(Tree T, char x[], int len){
	if(T==NULL)
		return;
	else{
		inOrder(T->Left, x, len);
		printf("%d ", T->Data);
		x[len++]=T->Data;
		inOrder(T->Right, x, len);
	}
}
void postOrder(Tree T){
	if(T!=NULL){
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d ", T->Data);
	}
}
	/*bai 1*/
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
 
       else
             i++;
   }
   return i;
}  
//Tree createTree(char pre[], char in[], int start, int end){
//	static int i=0;
//	Tree T;
//	T=(struct Node*)malloc(sizeof(struct Node));
//	if(start>end)
//		return NULL;
//	else if(start==end){
//		T->Data=pre[i];
//		i++;
//		T->Left=NULL;
//		T->Right=NULL;
//	}
//	else{
//		T->Data=pre[i];
//		i++;
//		int inOrderIndex=findIndex(T->Data, in, start, end);
//		T->Left=createTree(pre, in, start, inOrderIndex-1);
//		T->Right=createTree(pre, in, inOrderIndex+1, end);
//	}
//}
	/*bai 2*/
int max(int a, int b){
	if(a>b)
		return a;
	return b;
}
int findMax(Tree T){
	if(T==NULL)
		return 0;
	return max(T->Data, max(findMax(T->Left),findMax(T->Right)));
}
	/*bai 3*/
Tree findElement(int x, Tree T){
	if(T!=NULL){
		if(x==T->Data)
			return T;
		else{
			Tree temp=findElement(x, T->Left);
			if(temp==NULL){
				return findElement(x, T->Right);
			}
			return temp;
		}	
	}
	else return NULL;
}
	/*bai 4*/
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
	/*bai 5*/

void getDiameter(Tree T, int *diameter){
	if(T==NULL)
		*diameter= 0;
	*diameter=(getHeight(T->Left)+1) + (getHeight(T->Right)+1) +1;
	if(T->Left==NULL)
		getDiameter(T->Right, diameter);
	else if(T->Right==NULL)
			getDiameter(T->Left, diameter);
}
	/* bai 5*/
int getFullNodes(Tree T){
	static int a=0;
	if(T==NULL)
		return 0;
	if(T->Left!=NULL && T->Right!=NULL)
			a++;
	getFullNodes(T->Left);
	getFullNodes(T->Right);
	return a;
}
 /* bai 6*/
 
Tree convertTree (Tree T){
	if(T==NULL){
		return NULL;
	}
	else {	
		Tree temp;
		temp=(struct Node*) malloc(sizeof(struct Node));
		temp->Data=T->Data;
		temp->Right=convertTree(T->Left);
		temp->Left=convertTree(T->Right);
		return temp;
	}	
}

	/* bai 7*/
int isMirrors(Tree T1, Tree T2){
	if(T1==NULL && T2==NULL)
		return 1;
	else if(T1->Data!=T2->Data)
		return 0;
	else if(T1==NULL || T2==NULL)
		return 0;
	else return isMirrors(T1->Left, T2->Right) && isMirrors(T1->Right, T2->Left);
}

 /* bai 8*/
void printArray(int path[], int len){
 	int i;
 	for(i=0;i<len;i++)
    	printf("%d ",path[i]);
	printf("\n");
}
void printAllPaths(Tree T, int path[], int len, int pathlen){
	if(T==NULL || len>pathlen)
		return;
	path[len]=T->Data;
	len++;
	if(T->Left==NULL && T->Right==NULL &&len>pathlen)
		printArray(path, len);
	else{
		printAllPaths(T->Left, path, len , pathlen);
		printAllPaths(T->Right, path, len , pathlen);
	}
}
int main(){
DataType path[100];
int len=0,pathlen;	
Tree T,T1,T2;
T1 = createNode(6);
T1->Left = createNode(21);
T1->Right = createNode(-53);
T1->Left->Right = createNode(3);
T1->Right->Left = createNode(-8);
T1->Right->Right = createNode(30);
T1->Right->Left->Left = createNode(49);
T1->Right->Left->Right = createNode(17);
T2=createTree(10,createTree(7,createTree(4,NULL,NULL),NULL),createTree(25,createTree(32,NULL,NULL),NULL));	
T=createTree(-5,T1,T2);	
preOrder(T1, path, &len);
printf("\n");
printArray(path, len);
	return 0;
}
