#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElementType;
typedef struct {
	char ID[10];
	char Name[50];
	float R1, R2, R3;
}Student;
struct Node{
	Student Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
	(*pL)= (struct Node*) malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}

int emptyList(List L){
	return (L->Next==0);
}
Position first(List L){
	return L;
}
Position endList(List L){
	Position P;
	P=first(L);
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
Position next(Position P, List L){
	return P->Next;
}
Position previous(Position P, List L){
	Position E;
	E=P;
	P=first(L);
	while(P!=E){
		if (next(P, L)==E)
			return P;
		else P=next(P, L);
	}
}
void insertList(Student SV, Position P, List *pL){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=SV;
	T->Next=P->Next;
	P->Next=T;
}

void deleteList(Position P, List *pL){
	if (emptyList(*pL)==0){
		Position Temp;
		Temp=(struct Node*)malloc(sizeof(struct Node));
		Temp= P->Next;
		P->Next=Temp->Next;
	}
}
//
Student retrieve(Position P, List L){
//	if (P->Next!=NULL){
		return P->Next->Element;
//	}
}
//
Position locate(char x[10], List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	
	while(P!=E){
		if (strcmp(P->Next->Element.ID,x)==0){
			return P;
		}
		else P=P->Next;
	}
}
int member(char ID[10], List L){
	Position P, E;
//	P=first(L);
	E=endList(L);
	for (P=first(L); P!=E; P=P->Next){
		if (locate(ID, L)==P)
			return 1;
	}
	return 0;
}
int append(Student sv, List *pL){
	if (member(sv.ID, *pL)==0){
		insertList(sv, endList(*pL), pL);
		return 1;
	}
	else return 0;
}

List getList(){
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}

List readList(){
	List L;
	L=getList();
	int i, n;
	scanf("%d", &n);
	
	char id[10];
	Student sv;
	for (i=1; i<=n; i++){
		scanf("\n%s\n", id);
		strcpy(sv.ID, id);
		fgets(sv.Name, 50, stdin);
		sv.Name[strlen(sv.Name)-1]='\0';
		scanf("\n%f%f%f", &sv.R1, &sv.R2, &sv.R3);
		if(append(sv, &L)==0){
			continue;
		}
	}
	return L;
}


void printList(List L){
	struct Node* P;
	int k=0;
	for (P=L; P->Next!=NULL; P=P->Next){
		k++;
	float Diem=P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3;
		printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",k, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1,P->Next->Element.R2,P->Next->Element.R3, Diem);
	}
	printf("\n");
}

void showPassedList(List L){
	struct Node* P;
	int count=0;
	for(P=L; P->Next!=NULL; P=P->Next){
		
		float DiemTB=(P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3)/3;
		if (DiemTB>=4.0){
			count++;
			printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3, DiemTB);
			
		}
	}
	printf("%d students in total", count);
}
int main(){
List L=readList();
	printList(L);       
         showPassedList(L);
	return 0;
}
