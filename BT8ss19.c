#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int age;
    char phoneNumber[20];
};

void hienThiDanhSach(struct Student *std, int n);
void sapXepSinhVien(struct Student *std, int n);

int main() {
    struct Student std[50] = {
        {5, "Nguyen Van E", 22, "0918382393"},
        {3, "Nguyen Van C", 17, "0918638844"},
        {1, "Nguyen Van A", 18, "0918377546"},
        {4, "Nguyen Van D", 20, "0918329910"},
        {2, "Nguyen Van B", 19, "0918323773"}
    };

    int currentLength = 5;
    int delId;
	printf("Danh sach sinh vien ban dau:\n");
    hienThiDanhSach(std, currentLength);

    sapXepSinhVien(std, currentLength);
  	
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
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

void sapXepSinhVien(struct Student *std, int n) {
    struct Student temp;
    int i, j;
    for(i=0; i<n-1; i++){
    	for(j=0; j<n-1; j++){
    		if(strcmp(std[j].name, std[j+1].name)>0){
    			temp=std[j];
    			std[j]=std[j+1];
    			std[j+1]=temp;
			}
		}
	}
}

