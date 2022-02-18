#include <stdio.h>
#include "AListLib.c"


void removeAll(ElementType x, List *pL){
	Position P;
	for(P=1; P<=pL->Last; P++){
		if(locate(x, *pL)==P){
			deleteList(P, pL);
			P--;
		}
	}
}
int main(){
	
List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
{    L.Elements[i] = 2*i;}
L.Elements[i] = 8;
L.Elements[i+1] = 8;
L.Elements[i+2] = 8;
L.Last=8;
removeAll(8,&L);
for(i=0;i<L.Last;i++)
{    printf("%d ",L.Elements[i]);}
	return 0;
}
