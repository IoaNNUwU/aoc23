#include <stdio.h>
#include <stdlib.h>

int num_repr_of_char(char ch)
{
    switch (ch)
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;

    default:
        return 0;
    }
}

int calculate_magic_number(char text[])
{

    size_t sum = 0;
    size_t i = 0;
    char current_char;
    // lines
    while (1)
    {
        size_t line_sum = 0;
        int first_num = 0;
        int last_num = 0;

        // chars on 1 line
        while (1)
        {
            current_char = text[i];

            if (current_char == '\n' || current_char == '\0')
            {
                if (last_num != 0) // if last != 0, first is always != 0
                {
                    line_sum = first_num * 10 + last_num;
                }
                else if (first_num != 0)
                {
                    line_sum = first_num * 10 + first_num;
                }
                // if both are 0, line_sum stays 0
                break;
            }

            int current_num = num_repr_of_char(current_char);

            if (current_num == 0)
            {
                i++;
                continue;
            }

            if (first_num == 0)
            {
                first_num = current_num;
            }
            else
            {
                last_num = current_num;
            }
            i++;
        }

        sum += line_sum;

        i++;

        if (current_char == '\0')
        {
            break;
        }
    }

    return sum;
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
