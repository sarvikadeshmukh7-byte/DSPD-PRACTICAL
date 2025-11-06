#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char ch, input[20], output[20];

    printf("Enter source file name: ");
    scanf("%s", input);
    printf("Enter destination file name: ");
    scanf("%s", output);

    src = fopen(input, "r");
    if (src == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    dest = fopen(output, "w");
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("File copied successfully!\n");

    fclose(src);
    fclose(dest);
    return 0;
}