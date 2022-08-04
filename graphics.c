#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char basic1[3] = {'*', '*', '*'};
char *basic2[3] = {"#","#","#"};
char *basic3[3] = {":",":",":"};
char *basic4[3] = {"~","~","~"};
char *mosaic1[3] = {"]", "[]", "["};
char *mosaic2[3] = {"\\","|","/"};
char *mosaic3[3] = {")","|","("};
char *mosaic4[3] = {">","|","<"};

// 1: true, 2: false
int size = 2;
int contact = 1;
int revert = 0;
int gap = 1;

int border = 1;
char *border_char = "|";
char *border_title = "graphics.c";

int debug = 1;

void repeat(char c , int count, bool title) {
    int counter = 0;
    char *out = "";

    for (int i = 0; i < count ;i++) {
        out += c;
        for (int j; border_title[j]; j++) {
            counter++;
            out[counter] = j;
        }
    }
    printf("%c", c);
}

char *times(char *init, char *extra, int count) {
    size_t len_init = strlen(init);
    size_t len_extra = strlen(extra);
    char *result = malloc(len_init + len_extra * count + 1);
    if (!result) { return 0; }
    char *p = result;
    strcpy(p, init);
    p += len_init;
    for (int i = 0; i < count; i++) {
        strcpy(p, extra);
        p += len_extra;
    }
    return result;
}

int main(void) {
    int original_size = size;
    int alt_size = 0;
    gap+=1;

    if (debug == 1) {
        printf("SIZE=%s\n", debug==1 ? "true" : "false");
        printf("GAP=%d\n", gap);
        printf("BORDER=%s\n", border==1 ? "true" : "false");
        if (border == 1) {
            printf("BORDER_CHAR='%s'\n", border_char);
            printf("BORDER_TITLE='%s'\n", border_title);
        }
    }

    if (border == 1) {
        printf("%s", "+");
        printf("%s", times("","-", (size+(gap*2)+size)));
        printf("%s", "+");
        printf("\n");
    } else if (border == 0) {
        border_char = "\0";
    }
    
    for (int i = 0; i < size; i++) {
        original_size -= 1;
        alt_size += 1;
        printf("%s%s%s%s%s\n", border_char, times("","*", alt_size),times(""," ", (original_size+gap)*2), times("","*", alt_size), border_char);
    }
    
    for (int i = 0; i < alt_size; i++) {
        size -= 1;
        if (size == 0) { break; }
        original_size += 1;
        printf("%s%s%s%s%s\n", border_char, times("","*", size),times(""," ", (original_size+gap)*2), times("","*", size), border_char);
    }

    if (border == 1) {
        printf("%s", "+");
        printf("%s", times("","-", (alt_size+(gap*2)+alt_size)));
        printf("%s", "+");
        printf("\n");
    }

    return 0;
}
