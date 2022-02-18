#include <stdio.h>
#include <math.h>
#include <string.h>
#define Maxlength 10
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}List;
void makenullList(List *pL)
{
	(*pL).Last=0;	
	
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

int emptyList(List L)
{
	return L.Last==0;
}

Position first (List L)
{
	return 1;
}

Position endList(List L){
    return L.Last+1;
}

Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

void insertList(ElementType x, Position p, List *pL)
{
	if (fullList(*pL))
		printf("Danh sach day");	
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else 
	{
	  Position q;   
	  for(q=pL->Last; q>=p; q--)
		 pL->Elements[q]=pL->Elements[q-1];	  
	  pL->Elements[p-1]=x;	  
	  pL->Last++;
	 }
}

// Ham xoa phan tu
void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(emptyList(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  int k=0;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
		 k++;
	  }
	  printf("%d\n", k);
	  L->Last--;
	}
}

// Tim vi tri dau tien chua x
Position locate (ElementType x, List L)
{
	Position p=first(L);
	int f=0;
	while (p!=endList(L)&& f==0)
	{
		if (retrieve (p,L)==x)
			f=1;
		else 
			p=next(p,L)	;
	}
	return p;
}
int main(){
	List L;
	int i;
	L.Last = 0;
	for (i = 1; i <= 10; i++)
	{
		L.Elements[i-1] =  i;
	}
	L.Last = 10;
	printf("%d\n", endList(L));
	deleteList(endList(L), &L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}