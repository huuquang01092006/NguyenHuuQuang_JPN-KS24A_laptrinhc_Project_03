#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
//logic ham
void printMenu(){
	system("cls");
	printf("\n            *Menu quan ly sach*\n");
	printf("===========================================\n");
	printf("[1].Nhap so luong va thong tin sach.\n");
	printf("[2].Hien thi thong tin sach.\n");
	printf("[3].Them sach vao danh sach.\n");
	printf("[4].Xoa sach theo ma sach.\n");
	printf("[5].Cap nhat thong tin sach theo ma sach.\n");
	printf("[6].Sap xep theo gia.\n");
	printf("[7].Tim kiem sach theo ten.\n");
	printf("[8].Thoat\n");
}
void inputBook(struct Book book[], int *n){
	
	printf("\n---Nhap so luong sach---\n");
	printf("Nhap so luong sach muon them: ");
	scanf("%d", n);
	getchar();
	for(int i=0; i<*n;i++){
		printf("\nNhap thong tin cho sach thu %d:\n", i + 1);
		book[i].id=i+1;
		printf("Moi ban nhap vao ten sach: "); 
		fgets(book[i].bookName, sizeof(book[i].bookName), stdin); 
		if (book[i].bookName[strlen(book[i].bookName) - 1] == '\n') { 
		    book[i].bookName[strlen(book[i].bookName) - 1] = '\0'; 
		}
		printf("Moi ban nhap vao ten tac gia: "); 
		fgets(book[i].author, sizeof(book[i].author), stdin); 
		if (book[i].author[strlen(book[i].author) - 1] == '\n') { 
		    book[i].author[strlen(book[i].author) - 1] = '\0'; 
		}
		printf("Moi ban nhap vao gia tien: "); 
		scanf("%d", &book[i].price);
		getchar();
	}
}
void printBook(struct Book book[], int n){
    printf("\n---- Hien Thi Sach ----\n");
    printf("| %-4s | %-20s | %-20s | %-8s |\n", "ID", "Ten Sach", "Ten tac gia", "Gia tien");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-4d | %-20s | %-20s | %-8d |\n",
               book[i].id, book[i].bookName, book[i].author, book[i].price);
    }
}
void addBook(struct Book book[], int *n){
	int max=book[0].id;
	printf("\n---Them sach---\n");
	for(int i = 0; i < *n; i++){
		if(book[i].id > max){
			max = book[i].id;
		}
	}
	book[*n].id = max + 1;
	printf("Moi ban nhap vao ten sach: ");
	getchar(); 
	fgets(book[*n].bookName, sizeof(book[*n].bookName), stdin); 
	if (book[*n].bookName[strlen(book[*n].bookName) - 1] == '\n') { 
	    book[*n].bookName[strlen(book[*n].bookName) - 1] = '\0'; 
	}
	printf("Moi ban nhap vao ten tac gia: "); 
	fgets(book[*n].author, sizeof(book[*n].author), stdin); 
	if (book[*n].author[strlen(book[*n].author) - 1] == '\n') { 
	    book[*n].author[strlen(book[*n].author) - 1] = '\0'; 
	}
	printf("Moi ban nhap vao gia tien: ");
	scanf("%d", &book[*n].price);
	printf("\nThem sach thanh cong!\n");
	getchar();
	(*n)++;
}
void updateBook(struct Book book[], int n){
	printf("\n---Sua thong tin sach---\n");
	int idBook;
	printf("Nhap id sach muon sua: ");
	scanf("%d", &idBook);
	int found = 0;
	for (int i=0;i<n;i++){
		if (book[i].id == idBook) { 
		    found = 1; 
		    printf("Sua thong tin cho sach co ID: %d\n", idBook);
		    getchar();
		    printf("Moi ban nhap vao ten sach moi: "); 
		    fgets(book[i].bookName, sizeof(book[i].bookName), stdin); 
		    if (book[i].bookName[strlen(book[i].bookName) - 1] == '\n') { 
		        book[i].bookName[strlen(book[i].bookName) - 1] = '\0'; 
		    } 
		    printf("Moi ban nhap vao ten tac gia moi: "); 
		    fgets(book[i].author, sizeof(book[i].author), stdin); 
		    if (book[i].author[strlen(book[i].author) - 1] == '\n') { 
			    book[i].author[strlen(book[i].author) - 1] = '\0'; 
		    } 
		    printf("Moi ban nhap vao gia tien moi: "); 
		    scanf("%d", &book[i].price); 
		    getchar();
		    printf("Thong tin sach da duoc cap nhat thanh cong.\n"); 
		    break;
	    }
	}
	if (!found) {
	printf("ID khong ton tai!\n");
    }
}
void deleteBook(struct Book book[], int *n){
	printf("\n---Xoa thong tin sach---\n");
	int idBook;
	printf("Nhap id sach muon Xoa: ");
	scanf("%d", &idBook);
	int found = 0;
	for (int i = 0; i < *n; i++) { 
	    if (book[i].id == idBook) { 
	        found = 1; 
		    for (int j = i; j < *n - 1; j++) { 
		        book[j] = book[j + 1]; 
		    }     
		    (*n)--; 
		    break; 
	    } 
	} 
	if (found == 1) { 
	    printf("Da xoa sach co id: %d\n", idBook); 
	} else { 
	    printf("Khong tim thay sach voi id: %d\n", idBook); 
	}
}
int backMenu(){
	int select;
	printf("\nNhap phim [1] de quay lai Menu\n");
	printf("Nhap phim bat ki de thoat chuong trinh\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &select);
    if(select == 1){
		return 1;
	}else{
		system("cls");
		printf("Thoat chuong trinh thanh cong");
		exit(0);
    }
}
void sortBook(struct Book book[], int n){
	int choose;
	printf("\n---Sap xep sach teo gia tien---\n");
	printf("\n[1].Sap xep tang dan\n");
	printf("[2].Sap xep giam dan\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choose);
	if(choose == 1){
		system("cls");
		sortAscending(book, n);
		printf("                             ---Danh sach sau khi da sap xep---\n\n\n");
		printBook(book, n);
	}
	else if(choose ==2){
		system("cls");
		sortDescending(book, n);
		printf("                             ---Danh sach sau khi da sap xep---\n\n\n");
		printBook(book, n);
	}else{
		printf("lua chon khong hop le");
		return;
	}
}
void sortAscending(struct Book book[], int n){
	struct Book temp;
	for(int i = 0; i < n - 1;i++){
		for(int j = i +1; j < n; j++){
			if(book[i].price>book[j].price){
				temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
		}
	}
}
void sortDescending(struct Book book[], int n){
	struct Book temp;
	for(int i = 0; i < n - 1;i++){
		for(int j = i +1; j < n; j++){
			if(book[i].price<book[j].price){
				temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
		}
	}
}
void findBook(struct Book book[], int n){
	int found = 0;
	char nameBook[100];
	printf("\n---Tim sach theo ten sach---\n");
	getchar();
	printf("Moi ban nhap ten sach muon tim: ");
	fgets(nameBook, sizeof(nameBook), stdin);
	nameBook[strcspn(nameBook, "\n")] = '\0';
	printf("| %-4s | %-20s | %-25s | %-8s |\n", "ID", "Ten Sach", "Ten tac gia", "Gia tien");
    printf("------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < n; i++){
		if(strstr(book[i].bookName, nameBook) != NULL){
            printf("| %-4d | %-25s | %-20s | %-8d |\n",book[i].id, book[i].bookName, book[i].author, book[i].price);
            found = 1;
		}
	}
	if (found == 0){
		printf("Khong tim thay ten sach!");
	}
	backMenu();
}
void saveFile(struct Book book[], int n) {
    FILE *ptr = fopen("bookData.dat", "wb");
    if (ptr != NULL) {
        fwrite(book, sizeof(struct Book), n, ptr);
        printf("Luu thong tin thanh cong\n");
        fclose(ptr);
    } else {
        printf("Khong mo duoc file\n");
    }
}

void loadFile(struct Book book[], int *n) {
    FILE *ptr = fopen("bookData.dat", "rb");
    if (ptr == NULL) {
        printf("Khong mo duoc file\n");
        return;
    }

    *n = fread(book, sizeof(struct Book), 50, ptr);
    printf("\n---- Hien Thi Sach ----\n");
    printf("| %-4s | %-20s | %-20s | %-8s |\n", "ID", "Ten Sach", "Ten tac gia", "Gia tien");
    printf("------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < *n; i++) {
        printf("| %-4d | %-20s | %-20s | %-8d |\n", book[i].id, book[i].bookName, book[i].author, book[i].price);
    }
    printf("Lay Du Lieu Thanh Cong\n");
    
    fclose(ptr);
}

