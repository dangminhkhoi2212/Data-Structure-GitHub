#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node* AVLTree;


AVLTree search(int x,AVLTree T){
	if(T==NULL)
		return NULL;
	else if(x<T->Key)
			search(x,T->Left);
	else if(x>T->Key)
			search(x,T->Right);
	else return T;
}
int max(int a, int b){
    return(a>b)? a:b;
}
int getHeight(AVLTree T){
    if(T==NULL)
        return -1;
    else return T->Height;
}
void printNLR(AVLTree node){
    if(node==NULL)
        return;
    else{
		printf("(%d - %d); ", node->Key, getHeight(node));
        printNLR(node->Left);
        printNLR(node->Right);
        
    }
}
void printLRN(AVLTree node){
    if(node==NULL)
        return;
    else{
        printLRN(node->Left);
        printLRN(node->Right);
        printf("(%d - %d); ", node->Key, getHeight(node));
    }
}
int getBalance(AVLTree node){
    if(node==NULL)
        return 0;
	else return getHeight(node->Left)-getHeight(node->Right);
}
AVLTree leftRotate(AVLTree node){
    AVLTree temp;
    temp=node->Right;
    node->Right=temp->Left;
    temp->Left=node;
    node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
    return temp;
}
AVLTree rightRotate(AVLTree node){
	AVLTree temp;
	temp=node->Left;
	node->Left=temp->Right;
	temp->Right=node;
    node->Height=1+max(getHeight(node->Left), getHeight(node->Right));
	temp->Height=1+max(getHeight(temp->Left), getHeight(temp->Right));
	return temp;
}
AVLTree leftrightRotate(AVLTree node){
    node->Left=leftRotate(node->Left);
    return rightRotate(node);
}
AVLTree rightleftRotate(AVLTree node){
	node->Right=rightRotate(node->Right);
	return leftRotate(node);
}
int isAVL(AVLTree root){
	return -1<=getBalance(root) && getBalance(root)<=1;
}
AVLTree insertNode(KeyType key, AVLTree root){
	if(root==NULL){
		root=(struct Node*)malloc(sizeof(struct Node));
		root->Key=key;
		root->Left=NULL;
		root->Right=NULL;
		root->Height=0;
	}
	else if(key<root->Key)
			root->Left=insertNode(key, root->Left);
	else if(key>root->Key)
			root->Right=insertNode(key, root->Right);
	else return root;
	
	root->Height=1+max(getHeight(root->Left), getHeight(root->Right));
	int balance=getBalance(root);
	if(balance>1 && key<root->Left->Key)
		return rightRotate(root);
	if(balance <-1 && key>root->Right->Key)
		return leftRotate(root);
	if(balance>1 && key>root->Left->Key)
		return leftrightRotate(root);
	if(balance<-1 && key<root->Right->Key)
		return rightleftRotate(root);
	return root;
}

void printLeaves(AVLTree T){
	if(T==NULL)
		return;
	if(T->Left==NULL && T->Right==NULL)
			printf("%d ", T->Key);
	printLeaves(T->Left);
	printLeaves(T->Right);
}
int main(){
AVLTree T = NULL,N=NULL;
int k;
T=insertNode(27,T);
T=insertNode(12,T);
T=insertNode(40,T);
T=insertNode(4,T);
T=insertNode(20,T);
T=insertNode(34,T);
T=insertNode(50,T);
T=insertNode(30,T);
T=insertNode(32,T);
printNLR(T);
scanf("%d",&k);
N=search(k,T);	
printf("\nHe so can bang cua nut co khoa %d la %d",k,getBalance(N));
scanf("%d",&k);
N=search(k,T);	
printf("\nHe so can bang cua nut co khoa %d la %d",k,getBalance(N));
    return 0;
}

