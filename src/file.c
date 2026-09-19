#include <stdio.h>
#include <string.h>
#include "../include/file.h"

void ghiDanhSachSinhVien(sv ds[], int n){
    FILE *f=fopen("../data/dataStudent.txt", "w");
    if(f==NULL){
        printf("Khong the mo file!\n");
        return;
    }
    for(int i=0;i<n;i++){
        fprintf(f, "%s\n", ds[i].mssv);
        fprintf(f, "%s\n", ds[i].ten);
        fprintf(f, "%d\n", ds[i].gioiTinh);
        fprintf(f, "%d %d %d\n", ds[i].ns.ngay, ds[i].ns.thang, ds[i].ns.nam);
        fprintf(f, "%s\n", ds[i].lop);
        fprintf(f, "%s\n", ds[i].diachi);
    }
    fclose(f);
}

void docDanhSachSinhVien(sv ds[], int *n){
    FILE *f=fopen("../data/dataStudent.txt", "r");
    if(f==NULL){
        printf("Khong the mo file!\n");
        return;
    }
    *n=0;
    while(fscanf(f, "%19s", ds[*n].mssv)==1){
        fgetc(f);
        fgets(ds[*n].ten, sizeof(ds[*n].ten), f);
        ds[*n].ten[strcspn(ds[*n].ten, "\n")] = '\0';
        fscanf(f, "%d", &ds[*n].gioiTinh);
        fscanf(f, "%d %d %d", &ds[*n].ns.ngay, &ds[*n].ns.thang, &ds[*n].ns.nam);
        fgetc(f);
        fgets(ds[*n].lop, sizeof(ds[*n].lop), f);
        ds[*n].lop[strcspn(ds[*n].lop, "\n")] = '\0';
        fgets(ds[*n].diachi, sizeof(ds[*n].diachi), f);
        ds[*n].diachi[strcspn(ds[*n].diachi, "\n")] = '\0';
        (*n)++;
        printf("======== Sinh vien %d ========\n", *n);
printf("MSSV     : %s\n", ds[*n - 1].mssv);
printf("Ten      : %s\n", ds[*n - 1].ten);
printf("Gioi tinh: %d\n", ds[*n - 1].gioiTinh);
printf("Ngay sinh: %d/%d/%d\n",
       ds[*n - 1].ns.ngay,
       ds[*n - 1].ns.thang,
       ds[*n - 1].ns.nam);
printf("Lop      : %s\n", ds[*n - 1].lop);
printf("Dia chi  : %s\n\n", ds[*n - 1].diachi);
    }
    fclose(f);
}