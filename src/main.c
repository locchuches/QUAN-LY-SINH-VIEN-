#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/file.h"

void menu() {
    printf("================Danh Sach Sinh Vien================\n");
    printf("1. Nhap moi danh sach sinh vien\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Them sinh vien\n");
    printf("4. Xoa sinh vien theo ten\n");
    printf("5. Tim kiem sinh vien theo ten\n");
    printf("6. Tim kiem sinh vien theo mssv\n");
    printf("7. Sap xep danh sach sinh vien\n");
    printf("8. Ghi danh sach sinh vien vao file\n");
    printf("9. Doc danh sach sinh vien tu file\n");
    printf("0. Thoat\n");
    printf("===================================================\n\n");
    printf("Nhap lua chon cua ban: ");
}
int main() {
    sv ds[100];
    int n=0;
    docDanhSachSinhVien(ds, &n);
    int lc;
    do{
        menu();
        scanf("%d", &lc);
        switch(lc) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                nhapDanhSach(ds, n);
                ghiDanhSachSinhVien(ds, n);
                break;
            case 2:
                hienThiDanhSach(ds, n);
                break;
            case 3:
                printf("Nhap thong tin sinh vien can them:\n");
                themSinhVien(ds, &n);
                ghiDanhSachSinhVien(ds, n);
                break;
            case 4:{
                char ten[50];
                printf("Nhap ten sinh vien can xoa: ");
                getchar();
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                xoaSinhVienTheoTen(ds, &n, ten);
                ghiDanhSachSinhVien(ds, n);
                break;
            }
            case 5:{
                char ten[50];
                printf("Nhap ten sinh vien can tim: ");
                getchar();
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                timKiemSinhVienTheoTen(ds, n, ten);
                break;
            }
            case 6:{
                char mssv[20];
                printf("Nhap MSSV sinh vien can tim: ");
                getchar();
                fgets(mssv, sizeof(mssv), stdin);
                mssv[strcspn(mssv, "\n")] = '\0';
                timKiemSinhVienTheoMSSV(ds, n, mssv);
                break;
            }
            case 7:
                sapXepDanhSachSinhVien(ds , n);
                ghiDanhSachSinhVien(ds, n);
                break;
            case 8:
                ghiDanhSachSinhVien(ds, n);
                printf("Du lieu da duoc luu.\n");
                break;
            case 9:
                docDanhSachSinhVien(ds, &n);
                printf("Du lieu da duoc doc tu file.\n");
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    while(lc!=0);
    return 0;
}