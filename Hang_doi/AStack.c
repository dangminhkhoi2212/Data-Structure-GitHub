#include <stdio.h>

#define MaxLength 500
typedef char ElementType;
typedef struct{
	ElementType Element[MaxLength];
	int Top_idx;
}Stack;

	/*	Stack  */
void makenullStack(Stack *pS){
	pS->Top_idx=MaxLength;
}
int emptyStack(Stack S){
	return S.Top_idx==MaxLength;
}
int fullStack(Stack S){
	return S.Top_idx==0;
}
ElementType top(Stack S){
	return S.Element[S.Top_idx];
}
void push(ElementType x, Stack *pS){
	if(!fullStack(*pS)){
		pS->Top_idx--;
		pS->Element[pS->Top_idx]=x;
	}
}
void pop(Stack *pS){
	if(!emptyStack(*pS)){
		pS->Top_idx++;
	}
}


