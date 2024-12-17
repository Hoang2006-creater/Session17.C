#include <stdio.h>
#include <stdlib.h>

// Ham hien thi menu
void hienThiMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);

    // Cap phat bo nho cho mang
    *arr = (int *)malloc((*n) * sizeof(int));

    if (*arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap tung phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

// Ham hien thi mang
void hienThiMang(int *arr, int n) {
    if (arr == NULL || n == 0) {
        printf("Mang rong!\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham tinh do dai mang
void tinhDoDaiMang(int n) {
    printf("Do dai cua mang la: %d\n", n);
}

// Ham tinh tong cac phan tu trong mang
void tinhTongMang(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    printf("Tong cac phan tu trong mang la: %d\n", tong);
}

// Ham tim phan tu lon nhat
void timPhanTuLonNhat(int *arr, int n) {
    if (arr == NULL || n == 0) {
        printf("Mang rong!\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);
}

int main() {
    int *arr = NULL; 
    int n = 0;       
    int luaChon;     

    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                tinhDoDaiMang(n);
                break;
            case 4:
                tinhTongMang(arr, n);
                break;
            case 5:
                timPhanTuLonNhat(arr, n);
                break;
            case 6:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (luaChon != 6);

    // Giai phong bo nho cap phat dong
    free(arr);

    return 0;
}

