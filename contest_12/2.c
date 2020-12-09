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

char is_delim(char c, const char *delims) {
//    for (int i = 0; i < strlen(delims); ++i) {
//        if (c == delims[i]) return 1;
//    }
    return !((c>='A' && c<='Z') || (c >= 'a' && c <= "z"));
}

//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
void tokens_split(Tokens *tokens, const char *str, const char *delims) {
    int len = 0, wcount = 0;
    char in_word = 0;
    char buf[512] = {0};
    int str_len = strlen(str);
    for (int i = 0; i < str_len; ++i) {
        if (!in_word && !is_delim(str[i], delims)) { // start of word
            buf[len] = str[i];
            len++;
            in_word = 1;
        } else if (in_word && !is_delim(str[i], delims)) { // in word
            buf[len] = str[i];
            len++;
        }
        if (in_word && (is_delim(str[i], delims) || i == str_len - 1)) { // end of word
            len++;
            tokens->num++;
            char **new_tokens_arr = (char **) realloc(tokens->arr, tokens->num * sizeof(char *));
            if (new_tokens_arr != tokens->arr && tokens->arr != NULL) {
                memcpy(new_tokens_arr, tokens->arr, (tokens->num - 1) * sizeof(char *));
//                free(tokens->arr);
            }
            tokens->arr = new_tokens_arr;
            tokens->arr[wcount] = (char *) malloc(len * sizeof(char));
            memcpy(tokens->arr[wcount], buf, (len + 1) * sizeof(char));
            in_word = 0;
            len = 0;
            memset(buf, 0, 512);
            wcount++;
        }
    }
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
    char buf[1024] = { 0 };
    scanf("%s", buf);
    tokens_split(&t, buf, ".,:; ");
    printf("%d\n", t.num);
    for (int i = 0; i < t.num; ++i) {
        printf("%s\n", t.arr[i]);
    }
    tokens_free(&t);
    return 0;
}
