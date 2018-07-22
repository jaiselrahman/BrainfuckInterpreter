/*
    Copyright (c) 2018 Jaisel Rahman

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1536

char* readFromFile(char*);
int main(int argc, char* argv[]) {
    FILE* fp;
    char *s, *p = calloc(SIZE, sizeof(char));
    if (argc == 2) {
        s = readFromFile(argv[1]);
        if (s == NULL) {
            fprintf(stderr, "Cannot open file : %s", argv[1]);
            return 1;
        }
    } else {
        s = calloc(SIZE, sizeof(char));
        fgets(s, SIZE, stdin);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '>':
                ++p;
                break;
            case '<':
                --p;
                break;
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '.':
                putchar(*p);
                break;
            case ',':
                *p = getchar();
                break;
            case '[':
                break;
            case ']':
                if (*p != 0) {
                    for (int j = 1; j > 0;) {
                        --i;
                        if (s[i] == '[') j--;
                        if (s[i] == ']') j++;
                    }
                }
                break;
        }
    }
    return 0;
}

char* readFromFile(char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) return (char*)NULL;
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp) + 1;
    char* s;
    s = calloc(size, sizeof(char));
    fseek(fp, 0, SEEK_SET);
    fgets(s, size + 1, fp);
    return s;
}
