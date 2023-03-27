#include <stdio.h>

void choice(int n, int *flag, char path[255], int* flagP);
void openFile(char path[255], int* flagP);
void appendFile(char path[255]);
int main(void) {
    int n, trash;
    int flag = 0;
    int flagP = 0;
    char path[255];
    while (flag == 0) {
        if (scanf("%d.%d", &n, &trash) != 1) {
            printf("n/a\n");
            rewind(stdin);
        } else {
            choice(n, &flag, path, &flagP);
        }
    }
    return (0);
}

void choice(int n, int *flag, char path[255], int *flagP) {
    switch (n) {
        case 1:
            openFile(path, flagP);
            break;
        case -1:
            *flag = 1;
            break;
        case 2:
            if (*flagP == 1) {
                appendFile(path);
            } else {
                printf("n/a\n");
            }
            break;
        default:
            printf("n/a\n");
    }
}

void openFile(char path[255], int* flagP) {
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL) {
        printf("n/a\n");
    } else {
        char ch;
        *flagP = 1;
        if ((ch = fgetc(fp)) == EOF) {
            printf("n/a\n");
        } else {
            putchar(ch);
            while ((ch = fgetc(fp)) != EOF) {
                putchar(ch);
            }
        }
        fclose(fp);
    }
}
