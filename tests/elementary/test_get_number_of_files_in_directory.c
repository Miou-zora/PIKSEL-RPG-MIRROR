/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_get_number_of_files_in_directory
*/

#include "struct_var.h"
#include <criterion/criterion.h>

Test(get_number_of_files_in_directory, no_file)
{
    int nb_of_files = get_number_of_files_in_directory("tests");

    cr_assert_eq(nb_of_files, 0);
}

Test(get_number_of_files_in_directory, four_files)
{
    int nb_of_files = get_number_of_files_in_directory("src");

    cr_assert_eq(nb_of_files, 4);
}

Test(get_number_of_files_in_directory, no_directory)
{
    int nb_of_files = get_number_of_files_in_directory("temp_test_sheesh");

    cr_assert_eq(nb_of_files, 0);
}