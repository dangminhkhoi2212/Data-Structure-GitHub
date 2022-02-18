#include <stdio.h>
#include "AListLib.c"
int member(ElementType x, List L){
    Position p;
    for(p=1; p<=L.Last; p++){
        if(x==L.Elements[p-1])
            return 1;
    }
    return 0;
}
void nhap(List *pL){
    makenullList(pL);
    int n;
    scanf("%d", &n);
    int p,x;
    for(p=1; p<=n; p++){
        scanf("%d", &x);
        if(!member(x, *pL)){
            insertList(x,endList(*pL), pL);
        }
       
    }
}
void in(List L){
    int p;
    for(p=1; p<=L.Last; p++){
        printf("%d ", L.Elements[p-1]);
    }
    printf("\n");
}
void even(List L, List *pL){
    int p;
    for(p=1; p<=L.Last; p++){
        if(L.Elements[p-1]%2==0)
            insertList(L.Elements[p-1],endList(*pL), pL);
    }
}
float average(List L){
    float tb=0;
    int p;
    for(p=1; p<=L.Last; p++){
        tb+=L.Elements[p-1];
    }
    return tb/L.Last;
}
ElementType getMax(List L){
    int p;
    int max=L.Elements[0];
    for(p=1; p<=L.Last; p++){
        if(L.Elements[p-1]>max)
            max=L.Elements[p-1];
    }
    return max;
}
int sumList(List L){
    int s=0;
    Position p;
    for(p=1; p<=L.Last; p++){
        s+=L.Elements[p-1];
    }
    return s;
}

void diffirence(List L1, List L2, List *pL){
    Position P;
    for(P=1; P<=L1.Last; P++){
        if(!member(L1.Elements[P-1], L2)){
            insertList(retrieve(P,L1), endList(*pL), pL);
        }
    }
}
int main(){
    List L1, L2, KQ;
    makenullList(&KQ);
    nhap(&L1);
    nhap(&L2);
    in(L1);
    in(L2);
    diffirence(L1, L2, &KQ);
    in(KQ);
}

