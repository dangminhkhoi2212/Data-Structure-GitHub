#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;
typedef struct{
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

void khoitao(NganXep *pS){
	pS->Dinh=SoPhanTu;
}

ElementType giatriDinh(NganXep S){
	return S.DuLieu[S.Dinh];
}



int ktRong(NganXep S){
	return (S.Dinh==SoPhanTu);
}

void them(int x, NganXep *pS){
	if(!ktDay(*pS)){
		pS->Dinh--;
		pS->DuLieu[pS->Dinh]=x;
	}
}
void xoa(NganXep *pS){
	if(!ktRong(*pS)){
		pS->Dinh++;
	}
}

int ktDay(NganXep S){
	return S.Dinh==0;
}

int ktrong(NganXep S){
	return S.Dinh==SoPhanTu;
}
void hienthi(NganXep *pS){
	while(!ktRong(*pS)){
		printf("%d ", pS->DuLieu[pS->Dinh]);
		xoa(pS);
	}
}

void doiNhiPhan(ElementType n,NganXep *pS){
	khoitao(pS);
	while(n!=0){
		them(n%2, pS);
		n=n/2;
	}
}

int main(){
NganXep S;
int n;
scanf("%d", &n);
doiNhiPhan(n, &S);
hienthi(&S);
	return 0;
}
