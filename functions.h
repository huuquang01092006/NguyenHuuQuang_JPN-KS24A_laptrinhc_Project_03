#include "datatypes.h"

void printMenu();
void inputBook(struct Book book[],  int *n);
void printBook(struct Book book[], int n);
void addBook(struct Book book[], int *n);
void updateBook(struct Book book[], int n);
int backMenu(void);
void deleteBook(struct Book book[], int *n);
void sortBook(struct Book book[], int n);
void sortAscending(struct Book book[], int n);
void sortDescending(struct Book book[], int n);
void findBook(struct Book book[], int n);
void saveFile(struct Book book[], int n);
void loadFile(struct Book book[], int *n); 
