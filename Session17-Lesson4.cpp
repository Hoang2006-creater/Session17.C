#include <stdio.h>
#include <stdlib.h>

// Ham hien thi menu chinh
void hienThiMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu la so chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("6. Tim kiem phan tu trong mang\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham kiem tra so nguyen to
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &(*arr)[i]);
    }
}

// Ham in cac phan tu la so chan
void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Ham in cac phan tu la so nguyen to
void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Ham dao nguoc mang
void daoNguocMang(int *arr, int n) {
    printf("Mang sau khi dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham sap xep mang tang dan
void sapXepTangDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham sap xep mang giam dan
void sapXepGiamDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham tim kiem phan tu trong mang
void timKiemPhanTu(int *arr, int n) {
    int x, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d tim thay o vi tri %d.\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai trong mang.\n", x);
    }
}

// Ham xu ly menu con cho sap xep mang
void menuSapXep(int *arr, int n) {
    int luaChonSapXep;
    printf("\n===== MENU SAP XEP =====\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &luaChonSapXep);

    switch (luaChonSapXep) {
        case 1:
            sapXepTangDan(arr, n);
            break;
        case 2:
            sapXepGiamDan(arr, n);
            break;
        default:
            printf("Lua chon khong hop le!\n");
    }
}

int main() {
    int *arr = NULL; // Con tro mang
    int n = 0;       // So phan tu
    int luaChon;

    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (arr != NULL) inSoChan(arr, n);
                else printf("Mang chua duoc nhap!\n");
                break;
            case 3:
                if (arr != NULL) inSoNguyenTo(arr, n);
                else printf("Mang chua duoc nhap!\n");
                break;
            case 4:
                if (arr != NULL) daoNguocMang(arr, n);
                else printf("Mang chua duoc nhap!\n");
                break;
            case 5:
                if (arr != NULL) menuSapXep(arr, n);
                else printf("Mang chua duoc nhap!\n");
                break;
            case 6:
                if (arr != NULL) timKiemPhanTu(arr, n);
                else printf("Mang chua duoc nhap!\n");
                break;
            case 7:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 7);

    // Giai phong bo nho
    if (arr != NULL) free(arr);
    return 0;
}


