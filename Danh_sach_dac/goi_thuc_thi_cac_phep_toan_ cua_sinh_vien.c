#include <stdio.h>
#include <string.h>
typedef int Position;
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct{
	struct SinhVien A[50];
	int n;
}DanhSach;

void hienthiDat(DanhSach L){
	Position P;
	
	for (P=1; P<=L.n; P++){
		float Diem=L.A[P-1].DiemLT+L.A[P-1].DiemTH1+L.A[P-1].DiemTH2;
		if (Diem>=4.0)
			printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2, Diem);
	}
}

int ktRong(DanhSach L){
	if (L.n==0)
		return 1;
	return 0;
}

Position tim(char MSSV[10],DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++){
		if (strcmp(MSSV, L.A[P-1].MSSV)==0)
			return P;
	}
	return L.n++;
}

void xoaTai(Position P, DanhSach *L){
	Position I;
	for(I=P; I<=L->n; I++){
		L->A[I-1]=L->A[I];
	}
	L->n--;
}

void xoaSinhVien(char MSSV[10], DanhSach *pL){
	xoaTai(tim(MSSV, *pL), pL);
}

void chenCuoi(struct SinhVien S, DanhSach *pL){
	if (pL->n==40)
		printf("Loi! Danh sach day!");
	else {
		pL->A[pL->n]=S;
		pL->n++;
	}
}

void makenullList(DanhSach *L){
	L->n=0;
}

int ktMSSV(char MSSV[10], DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++)	{
		if (strcmp(MSSV, L.A[P-1].MSSV)==0){
			return 1;
		}
	}
	return 0;
}
void read(DanhSach *L){
	
	Position P;
	makenullList(L);
	int n;
	scanf("%d", &n);
	char mssv[10];
	for (P=1; P<=n; P++){
		scanf("\n%s\n", mssv);
		if(ktMSSV(mssv, *L)==0){
			strcpy(L->A[P-1].MSSV, mssv);
			fgets(L->A[P-1].HoTen, 50, stdin);
			L->A[P-1].HoTen[ strlen(L->A[P-1].HoTen)-1 ]='\0';
			scanf("%f %f %f", &L->A[P-1].DiemLT, &L->A[P-1].DiemTH1, &L->A[P-1].DiemTH2);
			chenCuoi(L->A[P-1], L);
		}
	}
	
}

void print(DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++){
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2);
	}
}


void tim_SinhVien(char MSSV[10], DanhSach L){
	Position P;
	P=tim(MSSV, L);
	if (ktMSSV(MSSV, L)){
		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", MSSV);
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2);
	}
	else {
		printf("Khong tim thay sinh vien %s", MSSV);
	}
	
}
int main(){
	DanhSach L;
	read(&L);
	print(L);	
	return 0;
}
