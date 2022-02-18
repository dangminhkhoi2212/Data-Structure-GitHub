#include <stdio.h>
#include<stdlib.h>

typedef struct {
    double he_so;
    int bac;
} DonThuc;
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao(){
	DaThuc L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}
void chenDonThuc(DonThuc s, DaThuc *pD){

	Position P;
	P=(*pD);
	int Found=0;
	while(P->Next!=NULL && !Found){
		if (P->Next->e.bac<=s.bac)
			Found=1;
		else		
			P=P->Next;				
	}
	if(P->Next!=NULL){
		if (s.bac==P->Next->e.bac){
			P->Next->e.he_so+=s.he_so;
		}
		else if(P->Next->e.bac<s.bac){
			Position T;
			T=(struct Node*)malloc(sizeof(struct Node));
			T->e=s;
			T->Next=P->Next;
			P->Next=T;
		}
	}
	else{	
			Position T;
			T=(struct Node*)malloc(sizeof(struct Node));
			T->e=s;
			T->Next=P->Next;
			P->Next=T;
		}
}


void xoaDonThuc(Position P,DaThuc *pD){
	P=(*pD)->Next;
	(*pD)->Next=P->Next;
}
DaThuc nhapDaThuc(){
	DaThuc L;
	L=khoitao();
	int n, i;
	DonThuc D;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		scanf("%lf %d", &D.he_so, &D.bac);
		chenDonThuc(D, &L);
	}
	return L;
}

void inDaThuc(DaThuc L){
	Position P;
	for (P=L; P->Next!=NULL; P=P->Next){
		printf("%.3lfX^%d", P->Next->e.he_so, P->Next->e.bac);
		Position K=P->Next;
		if (K->Next!=NULL)
			printf(" + ");
	}
	printf("\n");
}

DaThuc tinhDaoHam(DaThuc D){
	Position P;
	for (P=D; P->Next!=NULL; P=P->Next){
		P->Next->e.he_so=P->Next->e.he_so*P->Next->e.bac;
		P->Next->e.bac=P->Next->e.bac-1;
	}
	return D;
}

//DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
//	DaThuc Tich;
//	Tich=khoitao();
//	Position P, I;
//	DonThuc T;
//	for (P=D1 ; P->Next!=NULL; P=P->Next){
//	
//		for (I=D2; I->Next!=NULL; I=I->Next){
//			T.he_so=P->Next->e.he_so * I->Next->e.he_so;
//			T.bac=P->Next->e.bac + I->Next->e.bac;
//			chenDonThuc(T, &Tich);
//		}	
//	}
//	return Tich;
//}
DaThuc nhanDaThuc(DaThuc D1 , DaThuc D2){
	DaThuc kq=khoitao();
	Position P = D1;
	
	DonThuc temp;
 

	while (P->Next!=NULL)
    {
        Position Q = D2;    
        while (Q->Next!=NULL)
        {
                temp.he_so= P->Next->e.he_so * Q->Next->e.he_so;
		    	temp.bac = P->Next->e.bac+Q->Next->e.bac;
                chenDonThuc(temp,&kq);
		    	Q=Q->Next;
        }
        P=P->Next;
      
        
    }    
	return kq;
}
DaThuc congDaThuc(DaThuc L1, DaThuc L2){
	DaThuc KQ;
	KQ=khoitao();
	Position P;
	for (P=L1; P->Next!=NULL; P=P->Next){
		chenDonThuc(P->Next->e, &KQ);
	}
	for (P=L2; P->Next!=NULL; P=P->Next){
			chenDonThuc(P->Next->e, &KQ);
		}
	return KQ;
}


int main(){
DaThuc d1=nhapDaThuc();		
DaThuc d2=nhapDaThuc();		
DaThuc d = nhanDaThuc(d1,d2);
inDaThuc(d);
	return 0;
}
