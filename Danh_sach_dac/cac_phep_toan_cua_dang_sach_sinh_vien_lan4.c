#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef int Position;
typedef struct
{
    struct SinhVien A[40];
    int n;
} DanhSach;

void hienthi(DanhSach L){
    Position p;
    float s=0;
    for(p=1; p<=L.n; p++){
        s = L.A[p - 1].DiemLT+ L.A[p - 1].DiemTH1+ L.A[p - 1].DiemTH2;
        printf("%10s - %50S - %.2f - %.2f -%.2f -%.2f\n", L.A[p - 1].MSSV, L.A[p - 1].HoTen, L.A[p - 1].DiemLT, L.A[p - 1].DiemTH1, L.A[p - 1].DiemTH2, s);
    }
}
int tim(char x[], DanhSach L)
{
    int p;
    for (p = 1; p <= L.n; p++)
    {
        if (strcmp(x, L.A[p - 1].MSSV) == 0)
            return p;
    }
    return p;
}
int check(char x[], DanhSach L){
    int p;
    for (p = 1; p <= L.n; p++)
    {
        if (strcmp(x, L.A[p - 1].MSSV) == 0)
            return 1;
    }
    return 0;
}
void insertList(struct SinhVien x,int p, DanhSach *pL){
    int i;
    for(i=pL->n; i>=p; p--){
        pL->A[i]=pL->A[i-1];
    }
    pL->A[p]=x;
    pL->n++;
}
void chenCuoi(struct SinhVien x, DanhSach *L)
{
    if (L->n == 40)
        printf("Loi! Danh sach day!");
    else
    {
        L->A[L->n] = x;
        L->n++;
    }
}
DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
}
DanhSach nhap(){
    DanhSach L;
    L=dsRong();
    struct SinhVien sv;
    int n;
    scanf("%d", &n);
    int p;
    for(p=1; p<=n; p++){
        scanf("\n%s\n", sv.MSSV);
        if (check(sv.MSSV, L) == 0)
        {
            fgets(sv.HoTen, 50, stdin);
            sv.HoTen[strlen(sv.HoTen)-1]='\0';
            scanf("%f%f%f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);
            chenCuoi(sv, &L);
        }
    }
    return L;
}
DanhSach chepKhongDat(DanhSach L){
    DanhSach KQ;
    KQ=dsRong();
    float tb;
    int p;
    for(p=1; p<=L.n; p++){
        tb = (L.A[p - 1].DiemLT + L.A[p - 1].DiemTH1 + L.A[p - 1].DiemTH2);
        if(tb<4)
            chenCuoi(L.A[p-1], &KQ);
    }
    return KQ;
}
int main(){
    int i;
    DanhSach L1;
    DanhSach L = {{{"B1806972", "Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
    struct SinhVien s1 = {"B1806872", "Minh Dong", 1.5f, 1.0f, 1.0f};
    struct SinhVien s2 = {"B1806973", "Thai Anh", 4.5f, 1.25f, 1.0f};
    struct SinhVien s3 = {"B1818973", "Dong Nghi", 0.5f, 1.25f, 1.0f};
    L.A[1] = s1;
    L.n++;
    L.A[2] = s2;
    L.n++;
    L.A[3] = s3;
    L.n++;
    L1 = chepKhongDat(L);
    printf("Khong dat:\n");
    for (i = 0; i <= L1.n - 1; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L1.A[i].MSSV, L1.A[i].HoTen, L1.A[i].DiemLT, L1.A[i].DiemTH1, L1.A[i].DiemTH2);
    }
    return 0;
}
