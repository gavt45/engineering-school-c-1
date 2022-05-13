//
// Created by Gav on 08/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tokens_s {
    int num; //количество слов в строке
    char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;

#define CHR(c) (!((c>='A' && c<='Z') || (c >= 'a' && c <= "z")))


//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
void tokens_split(Tokens *tokens, char *str, const char *delims) {
    int len = 0, wcount = 0;
    char in_word = 0;
    char * start = NULL;
//    int str_len = strlen(str);
    int i = 0;
    do {
        if (!in_word && !CHR(str[i])) { // start of word
            start = str + i;
            len++;
            in_word = 1;
        } else if (!CHR(str[i])) { // in word
//            buf[len] = str[i];
            len++;
        }
        if (in_word && (CHR(str[i]) || str[i+1] == '\0')) { // end of word
//            len++;
            tokens->num++;
//            char **new_tokens_arr = (char **) realloc(tokens->arr, tokens->num * sizeof(char *));
//            if (new_tokens_arr != tokens->arr && tokens->arr != NULL) {
//                memcpy(new_tokens_arr, tokens->arr, (tokens->num - 1) * sizeof(char *));
//                free(tokens->arr);
//            }
//            tokens->arr = new_tokens_arr;
            if (tokens->arr == NULL)
                tokens->arr = (char **)malloc(1000001 * sizeof(char *));
//            printf("Len: %d\n", len);
            tokens->arr[wcount] = (char *) malloc((len+1) * sizeof(char));
            memcpy(tokens->arr[wcount], start, len * sizeof(char));
            tokens->arr[wcount][len] = '\0';
            in_word = 0;
            len = 0;
            wcount++;
        }
        i++;
    }while (str[i] != '\0');
}

//удаляет все ресурсы внутри tokens
void tokens_free(Tokens *tokens) {
    for (int i = 0; i < tokens->num; ++i) {
        free(tokens->arr[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    Tokens t = {0, NULL};
    char buf[1000001];
    scanf("%s", buf);
    tokens_split(&t, buf, ".,:; ");
    printf("%d\n", t.num);
    for (int i = 0; i < t.num; ++i) {
        printf("%s\n", t.arr[i]);
    }
    tokens_free(&t);
    return 0;
}
