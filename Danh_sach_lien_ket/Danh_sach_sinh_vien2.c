#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

List getList(){
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}

struct Node* locate(char x[10], List L){
	Position P;
	P=L;
	while(P->Next!=NULL){
		if(strcmp(x, P->Next->Element.ID)==0){
			return P;
		}
		else P=P->Next;
	}
	return P;
}

int append(Student x, List *pL){
	Position P;
	P=(*pL);
	while(P->Next!=NULL){
		if (x.ID!=P->Next->Element.ID){
			P->Next=P->Next->Next;
			P->Next->Element=x;
			return 1;
		}
		else {
			return 0;
			P=P->Next;
		}
	}
}

List read(){
	List L;
	L=getList();
	int n, i;
	scanf("%d", &n);
	Student sv;
	
	for (i=1; i<=n; i++){
		scanf("%s", sv.ID);
		fgets(sv.Name, 50, stdin);
		sv.Name[strlen(sv.Name)-1]='\0';
		scanf("%f%f%f", &sv.R1, &sv.R2, &sv.R3);
		append(sv, &L);
	}
}

void printList(List L){
	Position P;
	P=L;
	int count=0;
	while(P->Next!=NULL){
		count++;
		float Tong=P->Next->Element.R1+P->Next->Element.R2+P->Next->Element.R3;
		printf("%d - %10s - %50s - %.3f - %.3f -%.3f - %.3f\n", count, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3, Tong/3);
		P=P->Next;
	}
}

List getFailedList(List L){
	Position P;
	List KQ;
	KQ=getList();
	P=L;
	while(P->Next!=NULL){
		float TB=(P->Next->Element.R1+P->Next->Element.R2+P->Next->Element.R3)/3; 
		if(TB<=4.0){
			append(P->Next->Element, &KQ);
		}
		P=P->Next;
	}
	return KQ;
}
int main(){
List L = (struct Node*)malloc(sizeof(struct Node));
L->Next=NULL;
struct Node *p, *q;
	
Student s;		

strcpy(s.ID,"123" );
strcpy(s.Name,"Hai Long" );
s.R1 = 1.2f;
s.R2 = 5.6f;
s.R3 = 5.6f;
	
p=L;
q = (struct Node*)malloc(sizeof(struct Node));
q->Element = s;
q->Next=NULL;
p->Next = q;
	
	
p=p->Next;	
strcpy(s.ID,"567" );
strcpy(s.Name,"Minh Bien" );
s.R1 = 1.2f;
s.R2 = 1.3f;
s.R3 = 5.6f;
	
q = (struct Node*)malloc(sizeof(struct Node));
q->Element = s;
q->Next=NULL;
p->Next = q;
	
p = locate("567", L);
if(p->Next==NULL)
   printf("NOT FOUND 567");
else
{
   float R = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3)/3;
      printf("FOUND %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",p->Next->Element.ID, 
      p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
      p->Next->Element.R3,R);
  }
	return 0;	
}

