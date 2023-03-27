#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void choice(int n, int *flag, char *path);
void quest1(char *path);
void quest2(char *path);
void quest3();
void shift(char *data, int n, char *nData, int sh);


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
        case 3:
            quest3();
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

void quest3() {
    DIR *dir;
    struct dirent *entry;
    char pathDir[] = "ai_modules";


    dir = opendir(pathDir);
    if (!dir) {
        printf("n/a");
    } else {
        while ((entry = readdir(dir)) != NULL) {
            if ((entry->d_type == DT_REG) && (strstr(entry->d_name, ".h"))) {
                char fifle[1200];
                sprintf(fifle, "%s/%s", pathDir, entry->d_name);
                FILE *fp = fopen(fifle, "w");
                fclose(fp);
            }
            if ((entry->d_type == DT_REG) && (strstr(entry->d_name, ".txt"))) {
                char fifle[1200];
                sprintf(fifle, "%s/%s", pathDir, entry->d_name);
                char *data = malloc(sizeof(char) * 3000);
                char *nData = malloc(sizeof(char) * 3000);
                int i = 0;
                FILE *fp = fopen(fifle, "r");
                while ((data[i++] = fgetc(fp)) != EOF) {};
                shift(data, i, nData, -2);
                fclose(fp);
                FILE *fpw = fopen(fifle, "w");
                while (i != 0) {
                    fputc(data[i--], fpw);
                }
                fclose(fpw);
            }
        }
        closedir(dir);
    }
}

void shift(char *data, int n, char *nData, int sh) {
    if (sh > 0) {
        for (int i = 0, k = n - sh; i < n; i++, k++) {
            if (k >= n) {
                k = 0;
            }
            *(nData + k) = *(data + i);
        }
    } else {
        sh = -sh;
        for (int i = 0, k = sh; i < n; i++, k++) {
            if (k >= n) {
                k -= n;
            }
            *(nData + k) = *(data + i);
        }
    }
}

