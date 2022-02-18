#include <stdio.h>
#include <string.h>

typedef struct {
	char MSSV[10];
	char HovaTen[50];
	float DiemLT, TH1, Th2;
}SinhVien;

typedef struct{
	SinhVien A[40];
	int n;
}DanhSach;

void dsRong(DanhSach *L){
	L->n=0;
}
void chencuoi(SinhVien SV, DanhSach *L){
	L->A[L->n]=SV;
	L->n++;
}
void nhap(DanhSach *L){
	int i;
	dsRong(L);
	int n;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("\n%s\n", L->A[i-1].MSSV);
		fgets(L->A[i-1].HovaTen, 50, stdin);
		L->A[i-1].HovaTen[strlen(L->A[i-1].HovaTen)-1]='\0';
		
		scanf("\n%f %f %f", &L->A[i-1].DiemLT, &L->A[i-1].TH1, &L->A[i-1].Th2);
		L->n++;
	}
}

void inDS(DanhSach L){
	int i;
	for (i=1; i<=L.n; i++){
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i-1].MSSV, L.A[i-1].HovaTen, L.A[i-1].DiemLT, L.A[i-1].TH1, L.A[i-1].Th2);
		
	}
}
//
//DanhSach dsDat(DanhSach L){
//	int i;
//	DanhSach Dat;
//	dsRong(&Dat);
//	for (i=1; i<=L.n; i++){
//		float Diem=L.A[i-1].DiemLT+L.A[i-1].TH1+L.A[i-1].Th2;
//		if (Diem>=4.0){
//			  chencuoi(L.A[i-1], &Dat);
//		}
//	}
//	return Dat;
//}

DanhSach dsKhongDat(DanhSach L){
	int i;
	DanhSach KhongDat;
	dsRong(&KhongDat);
	for (i=1; i<=L.n; i++){
		float Diem=L.A[i-1].DiemLT+L.A[i-1].TH1+L.A[i-1].Th2;
		if(Diem<4.0){
			chencuoi(L.A[i-1], &KhongDat);
		}
	}
	return KhongDat;
}
int main (){
	DanhSach L;
	DanhSach KhongDat;
	nhap(&L);
	inDS(L);
	
	KhongDat=dsKhongDat(L);
	printf("Sinh vien KHONG DAT\n");
	inDS(KhongDat);
	return 0;
}
