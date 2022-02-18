#include <stdio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} List;
void makenullList(List *L)
{
    L->Last = 0;
}
int emptyList(List L)
{
    return L.Last == 0;
}
int fullList(List L)
{
    return L.Last == Maxlength - 1;
}
ElementType retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}
Position locate(ElementType x, List L)
{
    int i = 0;
    while (i <= L.Last)
    {
        if (x == L.Elements[i])
            return i;
        i++;
    }
}
Position first(List L)
{
    return 1;
}
Position endList(List L)
{
    return L.Last + 1;
}
Position next(Position p, List L)
{
    return p + 1;
}
Position previous(Position p, List L)
{
    return p - 1;
}

void insertList(ElementType x, Position P, List *L)
{
    int i;
    for (i = L->Last; i >= P; i--)
    {
        L->Elements[i] = L->Elements[i - 1];
    }
    L->Elements[P-1] = x;
    L->Last++;
}
void deleteList(Position p, List *L)
{
    int i;
    for (i = p; i < L->Last; i++)
    {
        L->Elements[i-1] = L->Elements[i];
    }
    L->Last--;
}
int member(ElementType x, List L){
    int p;
    for(p=1; p<=L.Last; i++){
        if(x==L.Elements[p-1])
            return 1;
    }
    return 0;
}
void insertSet(ElementType x, List *L){
    L->Elements[L->Last]=x;
    L->Last++;
}
void sort(List *L){
    int i, j;
    for(i=0; i<=L->Last; i++){
        for(j=i+1; j<=L->Last; j++){
            if(L->Elements[j]<L->Elements[i]){
                int temp;
                temp=L->Elements[i];
                L->Elements[i]=L->Elements[j];
                L->Elements[j]=temp;
            }
        }
    }
}
void normalize(List *pL){
    int i, j;
    for (i = 0; i < pL->Last; i++)
    {
        for(j=i+1; j<pL->Last; j++){
            if (pL->Elements[i]==pL->Elements[j])
            {
                deleteList(j+1, pL);
                j--;
            }
        }
    }
}
void erase(int x, List *pL){
    deleteList(locate(x, *pL), pL);
}
void intersection(List L1, List L2, List *pL)
{
    int i;
    makenullList(pL);
    for (i = 1; i <= L1.Last; i++)
    {
        if (member(L1.Elements[i - 1], L2))
        {
            insertSet(L1.Elements[i - 1], pL);
        }
    }
}
void difference(List L1, List L2, List *pL)
{
    makenullList(pL);
    int P;
    for (P = 1; P <= L1.Last; P++)
    {
        if (!member(L1.Elements[P - 1], L2))
        {
            insertSet(L1.Elements[P - 1], pL);
        }
    }
}
int main()
{
    List L;
    int i;
    L.Last = 0;
    for (i = 0; i < 10; i++)
    {
        L.Elements[i] = 2 * i;
    }
    L.Last = 10;
    erase(0, &L);
    for (i = 0; i < L.Last; i++)
    {
        printf("%d ", L.Elements[i]);
    }
    return 0;
}