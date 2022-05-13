#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, cmd, l;
    char c;
    scanf("%d", &n);
    char ** arr = (char**)malloc(100001 * sizeof(char*));
    for (int i = 0; i < 100001; i++){
        arr[i] = NULL;
    }
    int ptr = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &cmd);
        switch (cmd) {
            case 0: // create new str
                scanf("%d", &l);
                char * buf = (char *)malloc((l+1) * sizeof(char));
                scanf("%s", buf);
                arr[ptr] = buf;
                ptr++;
                break;
            case 1: // remove
                scanf("%d", &l);
                if (arr[l]!=NULL) {
                    free(arr[l]);
                    arr[l] = NULL;
                }
                break;
            case 2: // printf
                scanf("%d", &l);
                printf("%s\n", arr[l]);
                break;
            case 3: // count
                scanf("%d %c", &l, &c);
//                scanf("%c", &c);
                int cnt = 0;
//                printf("Str: %c\n", c);
                for (int j = 0; j < strlen(arr[l]); ++j) {
                    if (arr[l][j] == c) cnt++;
                }
                printf("%d\n", cnt);
                break;
            default:
                printf("FUCK");
                return 1;
        }
    }
    for (l = 0; l < 100001; ++l) {
        if (arr[l]!=NULL) {
            free(arr[l]);
            arr[l] = NULL;
        }
    }
    return 0;
}