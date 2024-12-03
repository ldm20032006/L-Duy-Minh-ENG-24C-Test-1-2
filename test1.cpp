#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void displayMenu() {
    printf("MENU\n");
    printf("1. Nhap so phan tu can nhap và giá tri các phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. In ra gia tri lon nhat cua mang\n");
    printf("4. In ra cac phan tu la so nguyên to trong mang\n");
    printf("5. Them mot phan tu vao trong mang\n");
    printf("6. Xoa mot phan tu trong mang\n");
    printf("7. Sap xep mang theo thu tu tang dan\n");
    printf("8. Tim kiem phan tu và in ra vi tri index cua phan tu do\n");
    printf("9. Thoat\n");
}

void inputArray() {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray() {
    printf("Các phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax() {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void displayPrimes() {
    printf("Các so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement() {
    if (n >= MAX) {
        printf("Khong the them phan tu vi mang da day.\n");
        return;
    }
    int newElem;
    printf("Nhap phan tu can them: ");
    scanf("%d", &newElem);
    arr[n++] = newElem;
    printf("Da them phan tu thanh cong.\n");
}

void deleteElement() {
    int pos;
    printf("Nhap vi tri cua phan tu can xoa (0-%d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri không hop le.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Da xoa phan tu thanh cong.\n");
}

void sortArray() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang dã duoc sap xep tang dan.\n");
}

void searchElement() {
    int target, found = 0;
    printf("Nhap phan tu can tìm: ");
    scanf("%d", &target);
    printf("Phan tu %d xuat hien tai vi tri: ", target);
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay.");
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                if (n > 0) {
                    printf("Gia tri lon nhat trong mang: %d\n", findMax());
                } else {
                    printf("Mang rong.\n");
                }
                break;
            case 4:
                displayPrimes();
                break;
            case 5:
                addElement();
                break;
            case 6:
                deleteElement();
                break;
            case 7:
                sortArray();
                break;
            case 8:
                searchElement();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon không hop le. Vui long thu lai.\n");
        }
    } while (choice != 9);

    return 0;
}

