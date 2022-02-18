#include <stdio.h>
#include <string.h>

struct SinhVien
{
    char MSSV[10], Name[50];
    float LT, TH1, TH2;
};
typedef struct
{
    struct SinhVien A[40];
    int n;
} DanhSach;
void makenullDanhSach(DanhSach *L)
{
    L->n = 0;
}
int member(char x[], DanhSach L)
{
    int p;
    for (p = 1; p <= L.n; p++)
    {
        if (strcmp(L.A[p - 1].MSSV, x) == 0)
            return 1;
    }
    return 0;
}
void chenCuoi(struct SinhVien x, DanhSach *L)
{
    if (L->n != 40)
    {
        L->A[L->n] = x;
        L->n++;
    }
}
void Nhap(DanhSach *L)
{
    makenullDanhSach(L);
    struct SinhVien sv;
    int p, n;
    scanf("%d", &n);
    for (p = 1; p <= n; p++)
    {
        scanf("\n%s\n", sv.MSSV);
        if (!member(sv.MSSV, *L))
        {
            fgets(sv.Name, 50, stdin);
            sv.Name[strlen(sv.Name) - 1] = '\0';
            scanf("%f%f%f", &sv.LT, &sv.TH1, &sv.TH2);
            chenCuoi(sv, L);
        }
    }
}
void in(DanhSach L)
{
    int p;
    for (p = 1; p <= L.n; p++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[p - 1].MSSV, L.A[p - 1].Name, L.A[p - 1].LT, L.A[p - 1].TH1, L.A[p - 1].TH2);
    }
}
void timSinhVien(char x[], DanhSach *KQ, DanhSach L)
{
    int p;
    for(p=1; p<=L.n; p++){
        if (member(x, L))
        {
            chenCuoi(L.A[p - 1], KQ);
            break;
        }

    }
}
void khongdat(DanhSach *KQ, DanhSach L){
    int p;
    for(p=1 ; p<=L.n; p++){
        float diem=L.A[p-1].LT+L.A[p-1].TH1+L.A[p-1].TH2;
        if(diem <4){
            chenCuoi(L.A[p-1], KQ);
        }
    }
}
int main()
{
    DanhSach L, KQ;
    makenullDanhSach(&KQ);
    Nhap(&L);
    in(L);
    khongdat(&KQ, L);
    printf("Sinh vien KHONG DAT\n");
    in(KQ);
    return 0;
}