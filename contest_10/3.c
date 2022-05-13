//
// Created by Gav on 08/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char field_name[4096] = {0};

int main() {
    setlocale(LC_ALL, "");
    FILE *fd = fopen("input.bin", "rb");
    FILE *fo = fopen("output.txt", "w");
//    freopen("output.txt", "w", stdout);
    int file_sz, str_sz, int_val;
    long long_val;
    double val;
    char field_type, bool_val, first_field=1;

    fread(&file_sz, 4, 1, fd);
//    printf("pos: %d\n", ftell(fd));

    fprintf(fo, "{\n\t");

    while (1) {
        size_t read_sz = fread(&field_type, 1, 1, fd);
        if (field_type != 0 && first_field != 1) fprintf(fo, ",\n\t");
        else if (field_type == 0) break;
//        fscanf(fd, "%s", field_name);
        int i = 0;
        while (i < 4096) {
            fread(&field_name[i], 1, 1, fd);
            if (field_name[i] == '\0') break;
            i++;
        }
//        printf("pos after read of field_name: %d\n", ftell(fd));
//        printf("Type: %d\n", field_type);
        fprintf(fo, "\"%s\": ", field_name);
        switch (field_type) {
            case 1: // double
                fread(&val, 8, 1, fd);
                fprintf(fo, "%0.15g", val);
                break;
            case 2: // string
                fread(&str_sz, 4, 1, fd);
//                printf("pos: %d\n", ftell(fd));
//                printf("Str size: %d\n", str_sz);
                char *str = (char *) malloc(str_sz * sizeof(char));
                str[str_sz - 1] = '\0';
                fread(str, 1, str_sz, fd);
//                printf("pos: %d\n", ftell(fd));
                fprintf(fo, "\"%s\"", str);
                break;
            case 16:
                fread(&int_val, 4, 1, fd);
                fprintf(fo, "%d", int_val);
                break;
            case 18:
                fread(&long_val, 8, 1, fd);
                fprintf(fo, "%ld", long_val);
                break;
            case 10:
                fprintf(fo, "null");
                break;
            case 8:
                fread(&bool_val, 1, 1, fd);
                if (bool_val)
                    fprintf(fo, "true");
                else
                    fprintf(fo, "false");
                break;
        }
        memset(field_name, 0, 4096);
        //printf(",\n\t");// ??
        if (first_field) first_field = 0;
    }

    fprintf(fo, "\n}");

    return 0;
}
