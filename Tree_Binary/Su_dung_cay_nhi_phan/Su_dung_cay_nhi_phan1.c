#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
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
	if(T!=NULL){
		printf("%d ", T->Data);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
void inOrder(Tree T){
	if(T!=NULL){
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

Tree createTree(int x, Tree l, Tree r){
	Tree n;
	n=(struct Node*) malloc(sizeof(struct Node));
	n->Data=x;
	n->Left=l;
	n->Right=r;
	return n;
}

/*int getHeight(Tree T){
	if(T==NULL)
		return 0;
	int a=getHeight(T->Left)+1;
	int b=getHeight(T->Right)+1;
	if(a>b)
		return a;
	else return b;
}
int isLeaf(Tree T){
	return T->Left==NULL && T->Right==NULL;
}*/
int getLeaves(Tree T){
	if(T==NULL)
		return 0;
	if(isLeaf(T))
		return 1;
	return getLeaves(T->Left)+ getLeaves(T->Right);
}

		/* bai 1 */

/*Option1*/
/*
int findIndex(DataType x, char in[], int start, int end){
    while (start<end){
         if (x==in[start])
             return start;
         else
             start++;
   }
   return start;
}
   Tree createTree(char pre[], char in[], int start, int end){
	static int i=0;
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	if(start>end)
		return NULL;
	if(start==end){
		T->Data=pre[i];
		T->Left=NULL;
		T->Right=NULL;
		i++;
		return T;
	}
	else {
		T->Data=pre[i];
		i++;
		int inOrderIndex=findIndex(T->Data, in, start, end);	
		T->Left=createTree(pre, in,start, inOrderIndex-1);
		T->Right=createTree(pre, in,inOrderIndex+1, end);
	}	
	return T;
}*/
/* Option2
Tree findElement(char x, Tree T){
    if(T==NULL){
        return NULL;
    }
    else {
        if(x==T->Data){
            return T;
        }
        else{
            return findElement(x,T->Left);
            return findElement(x,T->Right);
        }
    }
    
}
void Delete(char x[]){
	int i, end=strlen(x);
	for(i=0; i<=end-1; i++){
		x[i]=x[i+1];
	}
	x[end-1]='\0';
}
Tree createTree(char pre[], char in[]){
	static int i=0;
	int start=0, end=strlen(in)-1;
	Tree T;
	T=(struct Node*)malloc(sizeof(struct Node));
	if(start>end)
		return NULL;
	if(start==end){
		T->Data=pre[i];
		Delete(in);
		T->Left=NULL;
		T->Right=NULL;
		i++;
		return T;
	}
	else {
		T->Data=pre[i];
		Delete(in);
		i++;
		int inOrderIndex=findIndex(T->Data, in);	
		T->Left=createTree(pre, in);
		T->Right=createTree(pre, in);
	}	
	return T;
}
*/


		/* bai2 */

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}
int findMax(Tree T){
	if(emptyTree(T))
		return 0;
	char a=max(findMax(leftChild(T)), T->Data);
	char b=max(findMax(rightChild(T)), T->Data);
	return max(a, b);
}
	/*bai 3*/

Tree findElement(char x, Tree T){
    if(!emptyTree(T)){
 		if(x==T->Data)
		 	return T;
		else{
			Tree tempt=findElement(x,leftChild(T));
			if(tempt==NULL)
				tempt=findElement(x,rightChild(T));
			return findElement(x, tempt);
		}
	}
	return NULL;
}

	/*bai 4*/
int isLeaf(Tree T){
	if(T!=NULL){
		if(T->Left==NULL && T->Right==NULL)
			return 1;
	}
	return 0;
}
int getHeight(Tree T){
	if(emptyTree(T))
		return 0;
	int leftHeight=getHeight(leftChild(T))+1;
	int rightHeight=getHeight(rightChild(T))+1;
	if(leftHeight>rightHeight)
		return leftHeight;
	else return rightHeight;
}

//void getDiameter(Tree T, int *diameter){
//	if(emptyTree(T)){
//		*diameter=0;
//	}
//	*diameter=getHeight(leftChild(T))+getHeight(rightChild(T))+1;
//	if(emptyTree(rightChild(T))){
//		if(isLeaf(leftChild(T)))
//			*diameter+=1;
//		else getDiameter(leftChild(T), diameter);
//	}	
//	else if(emptyTree(leftChild(T))){
//			if(isLeaf(rightChild(T)))
//				*diameter+=1;
//			else getDiameter(rightChild(T), diameter);
//	}
//}
void getDiameter(Tree T, int *diameter){
	if(emptyTree(T))
		*diameter=0;
	if(!isLeaf(T))
		(*diameter)++;
	getDiameter(leftChild(T), diameter);
	getDiameter(rightChild(T), diameter);
}
		/* bai 5*/
		
int getFullNodes(Tree T){
	static int a=0;
	if(emptyTree(T))
		return 0;
	if(leftChild(T)!=NULL && rightChild(T)!=NULL)
		a++;
	getFullNodes(leftChild(T));
	getFullNodes(rightChild(T));
	return a;
}
		/*bai 6*/
Tree convertTree(Tree T){
	if(T==NULL)
		return NULL;
	else{
		Tree Mirror;
		Mirror=(struct Node*)malloc(sizeof(struct Node));
		Mirror->Data=T->Data;
		Mirror->Left=convertTree(T->Right);
		Mirror->Right=convertTree(T->Left);
		return Mirror;
	}	
}
		/* bai 7 */
int isMirrors(Tree T1, Tree T2){
	if(T1==NULL && T2==NULL)
		return 1;
	else if(T1==NULL || T2==NULL)
		return 0;
	else if(T1->Data!=T2->Data)
		return 0;
	return isMirrors(T1->Left, T2->Right)&& isMirrors(T1->Right, T2->Left);
}	
	/* bai 8 */
void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d ",path[i]);
    printf("\n");
}
void printAllPaths(Tree T, int path[], int len, int pathlen){
	if(emptyTree(T) || len>pathlen ){
		return;		
	}
	path[len]=T->Data;
	len++;	
	if(isLeaf(T)&& len>pathlen)
		printArray(path, len);
	else{
		printAllPaths(leftChild(T), path, len, pathlen);
		printAllPaths(rightChild(T), path, len, pathlen);	
	}
}
int main(){
	
	
int diameter=0;
struct Node* root = createNode('A');
root->Left = createNode('B');
root->Right = NULL;
root->Left->Left = createNode('C');
root->Left->Right = createNode('D');
root->Left->Left->Left = createNode('E');
root->Left->Left->Right = createNode('F');
root->Left->Right->Right = createNode('G');
getDiameter(root,&diameter);
printf("Duong kinh cua cay da cho la: %d", diameter);
	return 0;
}
