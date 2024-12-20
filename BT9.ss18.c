#include<stdio.h>
#include<string.h>


int main(){
	struct Dish{
		int id;
		char name[100];
		double price;
	};
	struct Dish menu[100]= {
		{1, "Pho", 35}, 
		{2, "Banh mi", 20},
		{3, "Com rang", 30},
		{4, "Bun dau", 40},
		{5, "Ban cuon", 25},
	};
	int n=5;	
	int choice;
	int i, j;
	int pos;
	do{
		printf("\nMENU\n");
		printf("1. In ra gia tri cac phan tu co trong menu mon an theo dang 1. member: value\n");
		printf("2. Them mot phan tu vao vi tri chi dinh\n");
		printf("3. Sua mot phan tu o vi tri chi dinh\n");
		printf("4. Xoa mot phan tu o vi tri chi dinh\n");
		printf("5. Sap xep cac phan tu theo price\n");
		printf("6. Tim kiem phan tu theo name nhap vao\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Cac phan tu co trong menu mon an: \n");
				for(i=0; i<n; i++){
					printf("%d. %s: %.2lf\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
				
			case 2:				
				printf("Nhap vi tri muon them phan tu: ",n);
				scanf("%d", &pos);
				fflush(stdin);
				if(pos<0 || pos>n){
					printf("Vi tri khong hop le\n");
					break;
				}
				struct Dish newFood;
				printf("Nhap mon an moi: ");
				fgets(newFood.name, sizeof(newFood.name), stdin);
				newFood.name[strcspn(newFood.name, "\n")]=0;
				printf("Nhap gia mon an moi: ");
				scanf("%lf", &newFood.price);
				for(i=n; i>pos; i--){
					menu[i]=menu[i-1];
					menu[i].id=i+1;
				}
				menu[pos]=newFood;
				menu[pos].id=pos+1;
				n++;
				break;
		
			
			case 3:
				printf("Nhap vi tri muon sua phan tu: ");
				scanf("%d", &pos);
				fflush(stdin);
				if(pos<0 || pos>n){
					printf("Vi tri khong hop le\n");
					break;	
				}
				printf("Nhap mon an moi: ");
				fgets(menu[pos].name, sizeof(menu[pos].name), stdin);
				menu[pos].name[strcspn(menu[pos].name, "\n")]=0;
				printf("Nhap gia mon an vua sua: ");
				scanf("%lf", &menu[pos].price);
				break;
				
			case 4:
				printf("Nhap vi tri muon xoa phan tu: ");
				scanf("%d", &pos);
				if(pos<0 || pos>n){
					printf("Vi tri khong hop le");
				} else {
					for(i=pos; i<n-1; i++){
						menu[i]=menu[i+1];
						menu[i].id=i+1;
					}
					n--;
				}
				break;
				
			struct Dish temp;
			case 5:

				for(i=0; i<n; i++){
					for(j=i+1; j<n; j++){
						if(menu[i].price>menu[j].price){
							temp=menu[i];
							menu[i]=menu[j];
							menu[j]=temp;
						}
						
					}
				}
				for(i=0; i<n; i++){
					printf("%d. %s: %.2lf\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
				
			char searchFood[100];
			int find=0;	
			case 6:
				find=0;
				printf("Nhap mon an can tim: ");
                fflush(stdin);
                fgets(searchFood, sizeof(searchFood), stdin);
                searchFood[strcspn(searchFood, "\n")]=0;
				for(i=0; i<n; i++){
					if(strcmp(searchFood, menu[i].name)== 0){
						printf("%d. %s: %.2lf\n", menu[i].id, menu[i].name, menu[i].price);
						find=1;
						break;
					}
				
				}
				if(find==0){
					printf("Khong tim thay mon an vua nhap\n");
				}
				break;			
				
			case 7:
				printf("Thoat chuong trinh!!!");
				break;
				default:
				printf("Lua chon khong hop le. Thu lai!!");	
				
				break;	
		}
		
		
	} while (choice!=7);
	

	
	return 0;
}
