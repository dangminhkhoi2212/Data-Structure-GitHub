#include <stdio.h>
#include <string.h>
#define Maxlength 40
typedef int Position;

struct SinhVien{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef struct{
    struct SinhVien A[Maxlength];
    int n;
}DanhSach;

void xoaTai(Position P, DanhSach *pL){
	Position I;
	if (pL->n==0){
		printf("Danh sach rong");
	}
	else {
		I=P;
		while(I!=pL->n+1){
			pL->A[I-1]=pL->A[I];
			I++;
		}
		pL->n--;
	}
}

void chenCuoi(struct SinhVien SV, DanhSach *pL){
	pL->A[pL->n]=SV;
	pL->n++;
}

Position tim(char MSSV[10], DanhSach L){
	Position P;
	P=1;
	while (P!=L.n){
		if (strcmp(MSSV,L.A[P-1].MSSV)==0)
			return P;
		P++;
	}
	return L.n++;
}

void dsRong(DanhSach *pL){
	pL->n=0;
}


int kt_MSSV(char MSSV[10], DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++){
		if (strcmp(MSSV, L.A[P-1].MSSV)==0){
			return 1;
		}
	}
	return 0;
}
DanhSach nhap(){
	Position P;
	DanhSach L;
	dsRong(&L);
	int n;
	scanf("%d", &n);
	char mssv[10];
	for (P=1; P<=n; P++){
		scanf("\n%s\n", mssv);
		if (kt_MSSV(mssv, L)==0){
			strcpy(L.A[P-1].MSSV, mssv);
			
			fgets(L.A[P-1].HoTen, 50, stdin);
			L.A[P-1].HoTen[strlen(L.A[P-1].HoTen)-1]='\0';
			scanf("\n%f %f %f", &L.A[P-1].DiemLT, &L.A[P-1].DiemTH1, &L.A[P-1].DiemTH2);
			chenCuoi(L.A[P-1], &L);

		}
	}
	return L;
}

void inDanhSach(DanhSach L){
	Position P;
	for (P=1; P<=L.n; P++){
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2);
	}
}
DanhSach chepKhongDat(DanhSach L){
	Position P;
	DanhSach L1;
	dsRong(&L1);
	for (P=1; P<=L.n; P++){
		float Diem=L.A[P-1].DiemLT+L.A[P-1].DiemTH1+L.A[P-1].DiemTH2;
		if (Diem<4.0){
			chenCuoi(L.A[P-1], &L1);
		}
	}
	return L1;
}

int ktRong(DanhSach L){
	if (L.n==0)
		return 1;
	else return 0;
}

void xoaSinhVien(char MSSV[10], DanhSach *pL){
	if (pL->n==0)
		printf("Danh sach rong");
	else {
		xoaTai(tim(MSSV, *pL), pL);
	}
}

void DS_dat(DanhSach L){
	Position P;
	printf("Sinh vien DAT\n");
	for (P=1; P<=L.n; P++){
		float Diem=L.A[P-1].DiemLT+L.A[P-1].DiemTH1+L.A[P-1].DiemTH2;
		if (Diem >=4.0){
			printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2);		}
	}
}
int main(){
	DanhSach L;
	L=nhap();
	inDanhSach(L);
	DS_dat(L);
	return 0;
}
