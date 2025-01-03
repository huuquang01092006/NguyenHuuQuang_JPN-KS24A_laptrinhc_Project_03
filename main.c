#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	struct Book books[50];
	int choice = 0;
	int n = 0;
	do{
		printMenu();
		printf("\n-Nhap lua chon cho quan ly sach: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				system("cls");
				inputBook(books, &n);
				saveFile(books, n);
				backMenu();
				break;
			case 2:
				system("cls");
//      			printBook(books, n);
                loadFile(books, &n);
				backMenu();
				break;
			case 3:
				system("cls");
			    addBook(books, &n);
			    saveFile(books, n);
			    backMenu();
				break;
			case 4:
				system("cls");
				printBook(books, n);
				deleteBook(books, &n);
				saveFile(books, n);
				backMenu();
				break;
			case 5:
				system("cls");
				printBook(books, n);
				updateBook(books, n);
				saveFile(books, n);
				backMenu();
				break;
			case 6:
				system("cls");
				printBook(books, n);
				sortBook(books, n);
				backMenu();
				break;
			case 7:
				system("cls");
				findBook(books, n);
				break;
			case 8:
				system("cls");
				printf("Thoat chuong trinh quan ly sach!");
				break;
			default:
				system("cls");
				printf("lua chon khong hop le!");
				return 1;
		}
	}while(choice!=8);
	return 0;
}
