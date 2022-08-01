#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

const char *basic1[3] = {"*","*","*"};
const char *basic2[3] = {"#","#","#"};
const char *basic3[3] = {":",":",":"};
const char *basic4[3] = {"~","~","~"};
const char *mosaic1[3] = {"]", "[]", "["};
const char *mosaic2[3] = {"\\","|","/"};
const char *mosaic3[3] = {")","|","("};
const char *mosaic4[3] = {">","|","<"};

int size = 13;
bool contact = true;
bool revert = false;
int gap = 1;

bool border = true;
char *border_char = "|";
char *border_title = "graphics.c";

// if (1) {
//     printf("SIZE=%s\n", debug ? "true" : "false");
//     printf("GAP=%d\n", gap);
//     printf("BORDER=%s\n", border ? "true" : "false");
//     if (border) {
//         printf("BORDER_CHAR='%s'\n", border_char);
//         printf("BORDER_TITLE='%s'\n", border_title);
//     }
// }

void repeat(char c , int count, bool title) {
     for (int i = 0; i<count ;i++){
        printf("%c", c);
    }
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
    int final_size = size;
    int alt_size = 0;
    gap+=1;

    printf("%s", "+");
    repeat('-', (size+gap)*2, true);
    printf("%s", "+");
    printf("\n");
    
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

    int count2 = 0;
    printf("%s", "+");
    repeat('-', (final_size+gap)*2, false);
    printf("%s", "+\n");

    return 0;
}
