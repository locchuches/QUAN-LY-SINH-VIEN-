# Quan Ly Sinh Vien

Project C co ban dung de quan ly danh sach sinh vien. Chuong trinh chay tren terminal, cho phep nhap, hien thi, them, xoa, tim kiem, sap xep, luu va doc du lieu sinh vien tu file.

## Chuc nang

- Nhap moi danh sach sinh vien
- Hien thi danh sach sinh vien
- Them sinh vien
- Xoa sinh vien theo ten
- Tim kiem sinh vien theo ten
- Tim kiem sinh vien theo MSSV
- Sap xep danh sach sinh vien theo ten
- Ghi danh sach sinh vien vao file
- Doc danh sach sinh vien tu file

## Cau truc thu muc

```text
QuanLiSinhVien/
├── data/
│   └── dataStudent.txt
├── include/
│   ├── file.h
│   └── student.h
├── src/
│   ├── file.c
│   ├── main.c
│   └── student.c
└── README.md
```

## Cach bien dich va chay

Yeu cau may da cai GCC, vi du MSYS2 MinGW/UCRT64.

Mo PowerShell hoac terminal tai thu muc `src`:

```powershell
cd "C:\Users\ADMIN\OneDrive - Hanoi University of Science and Technology\Desktop\CodeC\QuanLiSinhVien\src"
gcc main.c student.c file.c -o main
.\main
```

Hoac neu dang o thu muc goc project:

```powershell
gcc src\main.c src\student.c src\file.c -o src\main
cd src
.\main
```

Luu y: chuong trinh dang doc va ghi du lieu tai `../data/dataStudent.txt`, vi vay nen chay file `.exe` tu thu muc `src` de duong dan file hoat dong dung.

## Dinh dang du lieu

File `data/dataStudent.txt` luu moi sinh vien theo 6 dong:

```text
MSSV
Ten sinh vien
Gioi tinh
Ngay Thang Nam
Lop
Dia chi
```

Vi du:

```text
20240001
Nguyen Van A
0
1 1 2006
CNTT01
Ha Noi
```

Trong do:

- `0`: Nam
- `1`: Nu

## Tac gia

Loc
