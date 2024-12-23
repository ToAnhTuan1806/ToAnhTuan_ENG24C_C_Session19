#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int age;
    char phoneNumber[20];
};

void hienThiDanhSach(struct Student *std, int n);
void xoaSinhVien(struct Student *std, int *currentLength, int delId);

int main() {
    struct Student std[50] = {
        {1, "Nguyen Van A", 18, "0918377546"},
        {2, "Nguyen Van B", 19, "0918323773"},
        {3, "Nguyen Van C", 17, "0918638844"},
        {4, "Nguyen Van D", 20, "0918329910"},
        {5, "Nguyen Van E", 22, "0918382393"}
    };

    int currentLength = 5;
    int delId;

    hienThiDanhSach(std, currentLength);

    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &delId);
    xoaSinhVien(std, &currentLength, delId);
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    hienThiDanhSach(std, currentLength);

    return 0;
}

void hienThiDanhSach(struct Student *std, int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", std[i].id);
        printf("Ten: %s\n", std[i].name);
        printf("Tuoi: %d\n", std[i].age);
        printf("So dien thoai: %s\n", std[i].phoneNumber);
    }
}

void xoaSinhVien(struct Student *std, int *currentLength, int delId) {
    int check=0;
    int i, j;
    for (i =0; i<*currentLength; i++) {
        if(std[i].id==delId) {
            check=1;
            for(j=i; j<*currentLength-1; j++) {
                std[j]=std[j+1];
            }
            (*currentLength)--;
            printf("Da xoa sinh vien ID: %d\n", delId);
            break;
        }
    }
    if (check == 0) {
        printf("Khong tim thay sinh vien ID: %d\n", delId);
    }
}

