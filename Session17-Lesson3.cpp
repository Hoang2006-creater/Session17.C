#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm ki?m tra ký t? kho?ng tr?ng
int laKhoangTrang(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Hàm chuy?n ký t? thành ch? in hoa
char chuyenInHoa(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

// Hàm hi?n th? menu
void hienThiMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi dao nguoc\n");
    printf("3. Dem so luong tu trong chuoi\n");
    printf("4. Nhap vao chuoi khac, so sanh voi chuoi ban dau\n");
    printf("5. In hoa tat ca chu cai trong chuoi\n");
    printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Hàm nh?p chu?i
void nhapChuoi(char **str) {
    char temp[1000]; // Chu?i t?m
    printf("Nhap chuoi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Xóa ký t? xu?ng dòng

    *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    strcpy(*str, temp);
}

// Hàm in chu?i d?o ngu?c
void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Hàm d?m s? t? trong chu?i
int demSoTu(char *str) {
    int count = 0, inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!laKhoangTrang(str[i])) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

// Hàm so sánh hai chu?i
void soSanhChuoi(char *str1) {
    char *str2;
    nhapChuoi(&str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }

    free(str2);
}

// Hàm in hoa chu?i
void inHoaChuoi(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = chuyenInHoa(str[i]);
    }
    printf("Chuoi sau khi in hoa: %s\n", str);
}

// Hàm n?i chu?i khác vào chu?i ban d?u
void noiChuoi(char **str1) {
    char *str2;
    nhapChuoi(&str2);

    *str1 = (char *)realloc(*str1, strlen(*str1) + strlen(str2) + 1);
    if (*str1 == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    strcat(*str1, str2);
    printf("Chuoi sau khi noi: %s\n", *str1);

    free(str2);
}

int main() {
    char *chuoi = NULL;
    int luaChon;

    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        getchar(); // Xóa ký t? xu?ng dòng còn l?i trong b? d?m

        switch (luaChon) {
            case 1:
                nhapChuoi(&chuoi);
                break;

            case 2:
                if (chuoi == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    inChuoiDaoNguoc(chuoi);
                }
                break;

            case 3:
                if (chuoi == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    int soTu = demSoTu(chuoi);
                    printf("So luong tu trong chuoi: %d\n", soTu);
                }
                break;

            case 4:
                if (chuoi == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    soSanhChuoi(chuoi);
                }
                break;

            case 5:
                if (chuoi == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    inHoaChuoi(chuoi);
                }
                break;

            case 6:
                if (chuoi == NULL) {
                    printf("Chua nhap chuoi!\n");
                } else {
                    noiChuoi(&chuoi);
                }
                break;

            case 7:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (luaChon != 7);

    free(chuoi);
    return 0;
}

