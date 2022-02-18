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
//Tree createTree(int x, Tree l, Tree r){
//	Tree T;
//	T=(struct Node*)malloc(sizeof(struct Node));
//	T->Data=x;
//	T->Left=l;
//	T->Right=r;
//	return T;
//}
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
void preOrder(Tree T){
	if(T==NULL)
		return;
	else{
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

Tree createTree(char pre[], char in[], int start, int end){
	static int i=0;
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	if(start>end)
		return NULL;
	else if(start==end){
		T->Data=pre[i++];
		T->Left=T->Right=NULL;
		return T;
	}
	else{
		T->Data=pre[i++];
		int index=findIndex(T->Data, in, start,end);
		T->Left=createTree(pre, in, start, index-1);
		T->Right=createTree(pre, in, index+1, end);
		return T;
	}	
}

	/*bai 2*/
// int max(int a, int b){
// 	return (a>b)? a:b;
// }

int findMax(Tree T){
	if(T==NULL)
		return 0;
	else return max(T->Data, max(findMax(T->Left), findMax(T->Right)));
}
	/*bai 3*/
Tree findElement(int x, Tree T){
	if(T==NULL)
		return NULL;
	if(x==T->Data)
		return T;
	else {
		Tree temp=findElement(x, T->Left);
		if(temp==NULL)
			return findElement(x, T->Right);
		return temp;
	}
}
	/*bai 4*/
int getHeight(Tree T){
	if(T==NULL)
		return -1;
	else return max(getHeight(T->Left)+1, getHeight(T->Right)+1);
}
void getDiameter(Tree T, int *diameter){
	if(T==NULL)
		return;
	(*diameter)=1+getHeight(T->Left)+1+getHeight(T->Right)+1;
	if(T->Left==NULL)
		getDiameter(T->Right, diameter);
	else if(T->Right==NULL)
		getDiameter(T->Left, diameter);
}

	/*bai 5*/

int getFullNodes(Tree T){
	static int k=0;
	if(T==NULL)
		return 0;
	else if(T->Left!=NULL && T->Right!=NULL)
			k++;
	getFullNodes(T->Left);
	getFullNodes(T->Right);
	return k;
}

	/* bai 6*/
Tree convertTree(Tree T){
	
	if(T==NULL )
		return NULL;
	else {
		Tree M;
		M=(struct Node*) malloc(sizeof(struct Node));
		M->Data=T->Data;
		M->Left=convertTree(T->Right);
		M->Right=convertTree(T->Left);
		return M;
	}
	
}
	/* bai 7*/
int isMirrors(Tree T1, Tree T2){
	if(T1==NULL && T2==NULL)
		return 1;
	else if(T1==NULL || T2==NULL)
		return 0;
	else if(T1->Data!=T2->Data)
		return 0;
	else {
		return isMirrors(T1->Left, T2->Right)&&isMirrors(T1->Right, T2->Left);
	}
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
	path[len++]=T->Data;
	if(T->Left==NULL && T->Right==NULL && len>pathlen)
		printArray(path,len);
	printAllPaths(T->Left, path, len, pathlen);
	printAllPaths(T->Right, path, len, pathlen);
}
int main(){

	Tree T;
	char pre[100], in[100];
	fgets(pre, 100, stdin);
	if (pre[strlen(pre) - 1] == '\n')
	{
		pre[strlen(pre) - 1] = '\0';
	}
	fgets(in, 100, stdin);
	if (in[strlen(in) - 1] == '\n')
	{
		in[strlen(in) - 1] = '\0';
	}
	T = createTree(pre, in, 0, strlen(in) - 1);
	printf("Ket qua duyet hau tu: ");
	if (T != NULL)
		postOrder(T);
	return 0;
}
