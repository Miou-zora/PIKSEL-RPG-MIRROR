/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_get_files_from_directory
*/

#include "struct_var.h"
#include <criterion/criterion.h>

Test(get_files_from_directory, no_directory)
{
    char **files = get_files_from_directory("temp_test_sheesh");

    cr_assert_null(files);
}

Test(get_files_from_directory, no_file)
{
    char **files = get_files_from_directory("scripts");

    cr_assert_null(files);
}

Test(get_files_from_directory, casual_case)
{
    char **files = get_files_from_directory("tests/directory_tests");
    char *expected_files[] = {"file_3", "file_1", "file_2", NULL};

    for (int i = 0; expected_files[i] != NULL; i++) {
        cr_assert_str_eq(files[i], expected_files[i]);
    }
}