#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char ID[10];
	char Name[50];
	float R1, R2, R3;
} Student;

struct Node {
	Student Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;


List getList() {
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}
Position first(List L) {
	return L;
}
Position endList(List L) {
	Position P;
	P=L;
	while(P->Next!=NULL) {
		P=P->Next;
	}
	return P;
}
void insertList(Student x, Position P, List *pL) {
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=x;
	T->Next=P->Next;
	P->Next=T;
}
Position locate(char ID[10], List L) {
	Position P;
	P=L;
	while(P->Next!=NULL) {
		if(strcmp(P->Next->Element.ID, ID)==0) {
			return P;
		}
		P=P->Next;
	}
	return P;

}
int member(char ID[], List L) {
	if(locate(ID, L)==endList(L))
		return 0;
	else return 1;
}
int append(Student x, List *pL) {
	if(!member(x.ID, *pL)) {
		insertList(x, endList(*pL), pL);
		return 1;
	} else return 0;
}
List readList() {
	List L;
	L=getList();
	Student x;
	int i, n;
	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		scanf("\n%s\n", &x.ID);
		fgets(x.Name, 50, stdin);
		x.Name[strlen(x.Name)-1]='\0';
		scanf("\n%f%f%f",&x.R1, &x.R2, &x.R3 );
		append(x,&L);
	}
	return L;
}

void printList(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	int count=0;
	while (P!=E){
		count++;
		float DiemTB=(P->Next->Element.R1+P->Next->Element.R2+P->Next->Element.R3)/3;
		printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count , P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1,P->Next->Element.R2,P->Next->Element.R3, DiemTB);
		P=P->Next;
	}
	printf("\n");
}

void showPassedList(List L){
	Position P;
	int count=0;
	P=L;
	while(P->Next!=NULL){
		
		float DiemTB=(P->Next->Element.R1+P->Next->Element.R2+P->Next->Element.R3)/3;
		if(DiemTB>=4){
			count++;
			printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count , P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1,P->Next->Element.R2,P->Next->Element.R3, DiemTB);
		}
		P=P->Next;
		
	}
	printf("%d students in total", count);
}
int main() {
	List L=readList();
	printList(L);       
         showPassedList(L);
        return 0;
}

