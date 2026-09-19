#ifndef STUDENT_H
#define STUDENT_H

struct NgaySinh{
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    char mssv[20];
    char ten[30];
    int gioiTinh; // 0: Nam, 1: Nu
    struct NgaySinh ns;
    char lop[20];
    char diachi[30];
};

typedef struct SinhVien sv;

void nhapSinhVien(sv a[]);
void nhapDanhSach(sv ds[], int n);

void inSinhVien(sv a[]);
void hienThiDanhSach(sv ds[], int n);

void themSinhVien(sv ds[], int *n);
void xoaSinhVienTheoTen(sv ds[], int *n, char ten[]);

void timKiemSinhVienTheoTen(sv ds[], int n, char ten[]);
void timKiemSinhVienTheoMSSV(sv ds[], int n, char mssv[]);

void sapXepDanhSachSinhVien(sv ds[], int n);

#endif