/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_files_from_directory
*/

#include "struct_var.h"
#include <dirent.h>
#include "my.h"

int get_number_of_files_in_directory(char *directory)
{
    DIR *dir = opendir(directory);
    struct dirent *file;
    int nb_files = 0;

    if (dir == NULL)
        return (0);
    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.' && file->d_type == DT_REG)
            nb_files++;
    }
    closedir(dir);
    return (nb_files);
}

char **get_files_from_directory(char *directory)
{
    DIR *dir = opendir(directory);
    struct dirent *file;
    int nb_of_files = get_number_of_files_in_directory(directory);
    char **files = my_calloc(nb_of_files + 1, sizeof(*files));
    int i = 0;

    if (dir == NULL || nb_of_files == 0)
        return (NULL);
    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.' && file->d_type == DT_REG) {
            files[i] = my_calloc(my_strlen(directory) + 2 +
            my_strlen(file->d_name), sizeof(*files[i]));
            files[i] = my_strcat(files[i], directory);
            files[i] = my_strcat(files[i], "/");
            files[i] = my_strcat(files[i], file->d_name);
            i++;
        }
    }
    files[i] = NULL;
    closedir(dir);
    return (files);
}