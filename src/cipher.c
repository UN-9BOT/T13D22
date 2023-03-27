#include <stdio.h>
#include <stdlib.h>

void choice(int n, int *flag, char *path);
void quest1(char *path);
void quest2(char *path);

int main(void) {
    int n, trash;
    int flag = 1;
    char *path = malloc(sizeof(char) * 255);
    while (flag) {
        if (scanf("%d.%d", &n, &trash) != 1) {
            printf("n/a\n");
            rewind(stdin);
        } else {
            choice(n, &flag, path);
        }
    }
    free(path);
    return (0);
}

void choice(int n, int *flag, char *path) {
    switch (n) {
        case 1:
            scanf("%254s", path);
            quest1(path);
            break;
        case 2:
            quest2(path);
            break;
        case -1:
            *flag = 0;
            break;
        default:
            printf("n/a\n");
    }
}

void quest1(char *path) {
    FILE *fp;
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

void quest2(char *path) {
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL) {
        printf("n/a\n");
    } else {
        char ch;
        fclose(fp);
        fp = fopen(path, "a");
        rewind(stdin);
        while ((ch = getchar()) != '\n') {
            fputc(ch, fp);
        }
        fclose(fp);
        fp = fopen(path, "r");
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
    }
}
