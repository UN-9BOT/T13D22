#include <stdio.h>

void choice(int n, int *flag);
void openFile();
int main(void) {
    int n, trash;
    int flag = 0;
    while (flag == 0) {
        if (scanf("%d.%d", &n, &trash) != 1) {
            printf("n/a\n");
            rewind(stdin);
        } else {
            choice(n, &flag);
        }
    }
    return (0);
}

void choice(int n, int *flag) {
    switch (n) {
        case 1:
            openFile();
            break;
        case -1:
            *flag = 1;
            break;
        default:
            printf("n/a\n");
    }
}

void openFile() {
    char path[255];
    FILE *fp;
    scanf("%254s", path);
    if ((fp = fopen(path, "r")) == NULL) {
        printf("n/a\n");
    } else {
        char ch;
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
