#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
//    char b[100];
//    scanf("%[^\n]s",b);
//    for (int i = 0; i < 7; i++)
//    {
//        if (strcmp(a[i], b) == 0){
//            printf("%d", i+1);
//            break;
//        }
//    }
    char * letters = "abcdefghijklmnopqrstuvwxyz";
    freopen("input.txt", "r", stdin);
    char word[25];
    char pl1_wins = 0, is_break = 0;
    int i = 0;
    while (scanf("%s", &word) == 1 && i < 26){
//        printf("Player 1 wins?: %d\n", pl1_wins);
//        printf("letter %c in %s is at %d\n",letters[i], word, (strchr(word,letters[i])-word));
        if ((strchr(word,letters[i])-word) >= strlen(word)) {
            is_break = 1;
            break;
        }
        pl1_wins = pl1_wins ? 0:1;
        i++;
    }
    if (is_break == 0) {
        printf("NO WINNER");
        return 0;
    }
    if (pl1_wins == 1)
        printf("PLAYER 1");
    else
        printf("PLAYER 2");
    return 0;
}