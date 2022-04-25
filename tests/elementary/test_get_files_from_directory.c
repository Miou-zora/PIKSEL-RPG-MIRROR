/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_get_files_from_directory
*/

#include "struct_var.h"
#include <criterion/criterion.h>
#include "stdbool.h"
#include "my.h"

Test(get_files_from_directory, no_directory)
{
    char **files = get_files_from_directory("temp_test_sheesh", NULL);

    cr_assert_null(files);
}

Test(get_files_from_directory, no_file)
{
    char **files = get_files_from_directory("tests/directory_tests/sheesh", NULL);

    cr_assert_null(files);
}

bool get_str_in_array(char **array, char *to_find)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp(array[i], to_find) == 0)
            return (true);
    }
    return (false);
}


Test(get_files_from_directory, casual_case)
{
    char **files = get_files_from_directory("tests/directory_tests", NULL);
    char *expected_files[] = {"tests/directory_tests/file_3", "tests/directory_tests/file_1", "tests/directory_tests/file_2", NULL};

    cr_assert_not_null(files);
    cr_assert_eq(get_len_array(files), 3);
    for (int i = 0; expected_files[i]; i++) {
        cr_assert_not_null(files[i]);
        cr_assert_eq(get_str_in_array(expected_files, files[i]), true);
    }
}