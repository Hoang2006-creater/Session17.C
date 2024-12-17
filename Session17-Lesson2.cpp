#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ham kiem tra chu cai
int laChuCai(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Ham kiem tra chu so
int laChuSo(char c) {
    return (c >= '0' && c <= '9');
}

// Ham kiem tra ky tu khong phai chu cai va chu so
int laKyTuDacBiet(char c) {
    return !laChuCai(c) && !laChuSo(c) && c != ' ';
}

// Ham hien thi menu
void hienThiMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi\n");
    printf("3. Dem so luong chu cai trong chuoi va in ra\n");
    printf("4. Dem so luong chu so trong chuoi va in ra\n");
    printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham dem so luong chu cai trong chuoi
int demChuCai(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (laChuCai(str[i])) {
            count++;
        }
    }
    return count;
}

// Ham dem so luong chu so trong chuoi
int demChuSo(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (laChuSo(str[i])) {
            count++;
        }
    }
    return count;
}

// Ham dem so luong ky tu dac biet trong chuoi
int demKyTuDacBiet(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (laKyTuDacBiet(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char *str = NULL; 
    int luaChon;
    int length;

    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        getchar(); // Xoa ky tu xuong dong con lai trong bo dem

        switch (luaChon) {
            case 1: // Nhap vao chuoi
                printf("Nhap vao do dai toi da cua chuoi: ");
                scanf("%d", &length);
                getchar(); 

                // Cap phat bo nho cho chuoi
                str = (char *)malloc((length + 1) * sizeof(char));
                if (str == NULL) {
                    printf("Khong the cap phat bo nho!\n");
                    exit(1);
                }

                printf("Nhap chuoi: ");
                fgets(str, length + 1, stdin);
                str[strcspn(str, "\n")] = '\0'; 
                break;

            case 2: // In ra chuoi
                if (str == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    printf("Chuoi vua nhap: %s\n", str);
                }
                break;

            case 3: // Dem chu cai
                if (str == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    int soChuCai = demChuCai(str);
                    printf("So luong chu cai trong chuoi: %d\n", soChuCai);
                }
                break;

            case 4: // Dem chu so
                if (str == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    int soChuSo = demChuSo(str);
                    printf("So luong chu so trong chuoi: %d\n", soChuSo);
                }
                break;

            case 5: // Dem ky tu dac biet
                if (str == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    int soKyTuDacBiet = demKyTuDacBiet(str);
                    printf("So luong ky tu dac biet trong chuoi: %d\n", soKyTuDacBiet);
                }
                break;

            case 6: // Thoat
                printf("Thoat chuong trinh. Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (luaChon != 6);

    // Giai phong bo nho cap phat dong
    free(str);

    return 0;
}

