#include<stdio.h>
#include<conio.h>
void main() {
    char c;
    int cnt = 0;
    FILE *fptr;

    fptr = fopen("text.txt", "w");
    if (fptr == NULL) {
        printf("File can't be created\a");
        getch();
        exit(0);
    }
    printf("Enter some text and press enter key:\n");
    while ((c = getche()) != '\r') {
        fputc(c, fptr);
    }
    fclose(fptr);
    fptr = fopen("text.txt", "r");
    printf("\nContents of the File is:");
    while ((c = fgetc(fptr)) != EOF) {
        cnt++;
        printf("%c", c);
    }
    fclose(fptr);
    printf("\nThe number of characters present in file is: %d", cnt);
    getch();
}
