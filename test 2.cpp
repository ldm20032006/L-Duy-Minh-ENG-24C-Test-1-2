#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("MENU\n");
    printf("1. Nh?p k�ch c? v� gi� tr? c�c ph?n t? c?a m?ng\n");
    printf("2. In gi� tr? c�c ph?n t? c?a m?ng theo ma tr?n\n");
    printf("3. In ra c�c ph?n t? n?m tr�n du?ng bi�n v� t�nh t�ch\n");
    printf("4. In ra c�c ph?n t? n?m tr�n du?ng ch�o ch�nh\n");
    printf("5. In ra c�c ph?n t? n?m tr�n du?ng ch�o ph?\n");
    printf("6. S?p x?p du?ng ch�o ch�nh theo th? t? tang d?n\n");
    printf("7. T�m ki?m m?t ph?n t? v� in ra v? tr� c?a ph?n t? d� trong m?ng\n");
    printf("8. Tho�t\n");
}

void nhap_mang(int **mang, int n) {
    printf("Nh?p gi� tr? cho c�c ph?n t? c?a m?ng:\n");
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
    printf("C�c ph?n t? n?m tr�n du?ng bi�n: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("%d ", mang[i][j]);
                tich *= mang[i][j];
            }
        }
    }
    printf("\nT�ch c?a c�c ph?n t? n?m tr�n du?ng bi�n: %d\n", tich);
}

void duong_cheo_chinh(int **mang, int n) {
    printf("C�c ph?n t? n?m tr�n du?ng ch�o ch�nh: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void duong_cheo_phu(int **mang, int n) {
    printf("C�c ph?n t? n?m tr�n du?ng ch�o ph?: ");
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
    printf("�u?ng ch�o ch�nh sau khi s?p x?p: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void tim_kiem_phan_tu(int **mang, int n) {
    int x, found = 0;
    printf("Nh?p gi� tr? ph?n t? c?n t�m: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mang[i][j] == x) {
                printf("Ph?n t? %d n?m ? v? tr�: (%d, %d)\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found)
        printf("Kh�ng t�m th?y ph?n t? %d trong m?ng.\n", x);
}

int main() {
    int n, choice;
    printf("Nh?p k�ch c? c?a m?ng: ");
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
                printf("Tho�t chuong tr�nh.\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng ch?n l?i.\n");
                break;
        }
    } while (choice != 8);

    for (int i = 0; i < n; i++)
        free(mang[i]);
    free(mang);

    return 0;
}

