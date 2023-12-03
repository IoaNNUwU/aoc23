#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;
typedef int bool;

bool maybe_equals(char *part_of_string, char *string_with_null_term)
{
    size_t i = 0;
    while (string_with_null_term[i] != '\0')
    {
        if (part_of_string[i] == '\0')
        {
            return false;
        }
        if (part_of_string[i] != string_with_null_term[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int num_repr_of_char(char *ch)
{
    if (*ch == '1' || maybe_equals(ch, "one"))
        return 1;
    if (*ch == '2' || maybe_equals(ch, "two"))
        return 2;
    if (*ch == '3' || maybe_equals(ch, "three"))
        return 3;
    if (*ch == '4' || maybe_equals(ch, "four"))
        return 4;
    if (*ch == '5' || maybe_equals(ch, "five"))
        return 5;
    if (*ch == '6' || maybe_equals(ch, "six"))
        return 6;
    if (*ch == '7' || maybe_equals(ch, "seven"))
        return 7;
    if (*ch == '8' || maybe_equals(ch, "eight"))
        return 8;
    if (*ch == '9' || maybe_equals(ch, "nine"))
        return 9;

    return 0;
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

            int current_num = num_repr_of_char(&text[i]);

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
