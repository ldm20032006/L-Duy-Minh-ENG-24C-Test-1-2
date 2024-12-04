#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("MENU\n");
    printf("1. Nh?p kích c? và giá tr? các ph?n t? c?a m?ng\n");
    printf("2. In giá tr? các ph?n t? c?a m?ng theo ma tr?n\n");
    printf("3. In ra các ph?n t? n?m trên du?ng biên và tính tích\n");
    printf("4. In ra các ph?n t? n?m trên du?ng chéo chính\n");
    printf("5. In ra các ph?n t? n?m trên du?ng chéo ph?\n");
    printf("6. S?p x?p du?ng chéo chính theo th? t? tang d?n\n");
    printf("7. Tìm ki?m m?t ph?n t? và in ra v? trí c?a ph?n t? dó trong m?ng\n");
    printf("8. Thoát\n");
}

void nhap_mang(int **mang, int n) {
    printf("Nh?p giá tr? cho các ph?n t? c?a m?ng:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mang[i][j]);
}

void in_ma_tran(int **mang, int n) {
    printf("Ma tr?n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mang[i][j]);
        printf("\n");
    }
}

void bien_va_tich(int **mang, int n) {
    int tich = 1;
    printf("Các ph?n t? n?m trên du?ng biên: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("%d ", mang[i][j]);
                tich *= mang[i][j];
            }
        }
    }
    printf("\nTích c?a các ph?n t? n?m trên du?ng biên: %d\n", tich);
}

void duong_cheo_chinh(int **mang, int n) {
    printf("Các ph?n t? n?m trên du?ng chéo chính: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void duong_cheo_phu(int **mang, int n) {
    printf("Các ph?n t? n?m trên du?ng chéo ph?: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][n-1-i]);
    printf("\n");
}

void sap_xep_cheo_chinh(int **mang, int n) {
    int *chinh = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        chinh[i] = mang[i][i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (chinh[i] > chinh[j]) {
                int temp = chinh[i];
                chinh[i] = chinh[j];
                chinh[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        mang[i][i] = chinh[i];

    free(chinh);
    printf("Ðu?ng chéo chính sau khi s?p x?p: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void tim_kiem_phan_tu(int **mang, int n) {
    int x, found = 0;
    printf("Nh?p giá tr? ph?n t? c?n tìm: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mang[i][j] == x) {
                printf("Ph?n t? %d n?m ? v? trí: (%d, %d)\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found)
        printf("Không tìm th?y ph?n t? %d trong m?ng.\n", x);
}

int main() {
    int n, choice;
    printf("Nh?p kích c? c?a m?ng: ");
    scanf("%d", &n);

    int **mang = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mang[i] = (int *)malloc(n * sizeof(int));

    do {
        display_menu();
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhap_mang(mang, n);
                break;
            case 2:
                in_ma_tran(mang, n);
                break;
            case 3:
                bien_va_tich(mang, n);
                break;
            case 4:
                duong_cheo_chinh(mang, n);
                break;
            case 5:
                duong_cheo_phu(mang, n);
                break;
            case 6:
                sap_xep_cheo_chinh(mang, n);
                break;
            case 7:
                tim_kiem_phan_tu(mang, n);
                break;
            case 8:
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?. Vui lòng ch?n l?i.\n");
                break;
        }
    } while (choice != 8);

    for (int i = 0; i < n; i++)
        free(mang[i]);
    free(mang);

    return 0;
}

