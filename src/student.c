#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/student.h"

void nhapSinhVien(sv a[]){
        printf("Nhap thong tin sinh vien:\n");
        printf("Nhap MSSV: ");
        scanf("%s", a->mssv);
        getchar();
        printf("Nhap ten: ");
        fgets(a->ten, sizeof(a->ten), stdin);
        a->ten[strlen(a->ten) - 1] = '\0'; 
        printf("Nhap gioi tinh (0: Nam, 1: Nu): ");
        scanf("%d", &a->gioiTinh);
        getchar();
        printf("Nhap ngay sinh (ngay thang nam): ");
        scanf("%d %d %d", &a->ns.ngay, &a->ns.thang, &a->ns.nam);
        getchar();
        printf("Nhap lop: ");
        fgets(a->lop, sizeof(a->lop), stdin);
        a->lop[strlen(a->lop) - 1] = '\0'; 
        printf("Nhap dia chi: ");
        fgets(a->diachi, sizeof(a->diachi), stdin);
        a->diachi[strlen(a->diachi) - 1] = '\0'; 
}
void nhapDanhSach(sv ds[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&ds[i]);
    }
}

void inSinhVien(sv a[]) {
    printf("%-12s ", a->mssv);
    printf("%-25s ", a->ten);
    printf("%-10s ", a->gioiTinh == 0 ? "Nam" : "Nu");
    printf("%02d/%02d/%04d ", a->ns.ngay, a->ns.thang, a->ns.nam);
    printf("  ");
    printf("%-10s ", a->lop);
    printf("%-30s\n", a->diachi);
}

void hienThiDanhSach(sv ds[], int n) {
    printf("-------------------------------------------Danh Sach Sinh Vien-------------------------------------------\n");
    printf("%-12s %-25s %-10s %-12s %-10s %-30s\n", "MSSV", "Ten", "Gioi Tinh", "Ngay Sinh", "Lop", "Dia Chi");
    for(int i = 0; i < n; i++) {
        inSinhVien(&ds[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

void themSinhVien(sv ds[], int *n){
    nhapSinhVien(&ds[*n]);
    (*n)++;
}

void xoaSinhVienTheoTen(sv ds[], int *n, char ten[]) {
    for(int i=0;i<*n;i++){
        if(strcmp(ds[i].ten, ten)==0){
            for(int j=i;j<*n-1;j++){
                ds[j]=ds[j+1];
            }
            (*n)--;
        }
    }
}

void timKiemSinhVienTheoTen(sv ds[], int n, char ten[]){
    int found=0;
    for(int i=0;i<n;i++){
        if(strcmp(ds[i].ten, ten)==0){
            inSinhVien(&ds[i]);
            found=1;
        }
    }
    if(!found){
        printf("Khong tim thay sinh vien co ten %s\n", ten);
    }
}

void timKiemSinhVienTheoMSSV(sv ds[], int n, char mssv[]){
    int found=0;
    for(int i=0;i<n;i++){
        if(strcmp(ds[i].mssv, mssv)==0){
            inSinhVien(&ds[i]);
            found=1;
        }
    }
    if(!found){
        printf("Khong tim thay sinh vien co MSSV %s\n", mssv);
    }
}

int cmp(const void *a, const void *b){
    sv *x=(sv *)a;
    sv *y=(sv *)b;
    return strcmp(x->ten, y->ten);
}

void sapXepDanhSachSinhVien(sv ds[], int n){
    qsort(ds, n, sizeof(sv), cmp);
}