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

int tim(char MSSV[10],DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++){
		if (strcmp(MSSV, L.A[P-1].MSSV)==0)
			return P;
	}
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
	Position P;
	if (pL->n==40)
		printf("Loi! Danh sach day!");
	else {
		pL->A[pL->n]=S;
		pL->n++;
	}
}

