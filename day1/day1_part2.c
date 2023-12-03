#include <stdio.h>
#include <stdlib.h>

// one two three four five six seven eight nine ten
int calculate_sum_for_line(char* line) {
    int first = 0;
    int last = 0;

    size_t i = 0;
    while (1) {
        char current_char = line[i];
        
    }


}

int main()
{
    FILE *file = fopen("./day1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(file_size + 1);
    fread(content, sizeof(char), file_size, file);
    content[file_size] = '\0';

    fclose(file);

    int num = calculate_magic_number(content);
    printf("%d", num);

    free(content);
    return 0;
}
