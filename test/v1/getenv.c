#include "main.h"

/**
 * _getenv - searches for an environment by name
 * @name: points to the name of the environment
 *
 * Return: a pointer to the value of the environ var on success and NULL
 * if it fails
 */

char *_getenv(const char *name)
{
	int i, m;
	char *value = NULL;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		for (m = 0; environ[i][m] != '='; m++)
		{
			if (name[m] == '\0')
				break;
			if (name[m] != environ[i][m])
				break;
		}

		if (name[m] == '\0' && environ[i][m] == '=')
		{
			value = &environ[i][++m];
			break;
		}
	}

	return (value);
}

/**
 * path_handler - checks if a command(file/directory) can be executed(exists)
 * @arr: points to an array of pointers to string arguments
 *
 * Return: an array of pointers to the command and its arguments
 *	NULL on fail or command not found
 */

char **path_handler(char **arr)
{
	char **path_list = NULL, *path_strings = NULL,
		*temp = NULL, *copy = NULL;
	int len;
	struct stat st;

	path_strings = _getenv("PATH");
	if (path_strings != NULL)
	{
		len = _strlen(path_strings);
		if (len > 0)
		{
			copy =  malloc(sizeof(char) * ++len);
			if (copy != NULL)
			{
				copy = _strcpy(copy, path_strings);
				path_list = line_to_av(copy, ":");
			}
		}
	}

	len = _strlen(arr[0]) + 1;
	temp = malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);

	temp = _strcpy(temp, arr[0]);
	if (stat(temp, &st) == 0)
	{
		arr[0] = temp;
		_free(copy), _free(path_list);
		return (arr);
	}
	_free(temp);

	if (path_strings != NULL && path_list != NULL)
		return (search_path(path_list, arr, copy));

	_free(copy), _free(path_list);
	return (NULL);
}

/**
 * search_path - searches for a command in all given directories
 * @paths: holds an array of pointers to directory paths
 * @argv: holds an array of pointers to a command and its arguments
 * @path_copy: points to a copy of the path variable
 *
 * Return: a pointer to the updated argv on success or NULL on fail
 */

char **search_path(char **paths, char **argv, char *path_copy)
{
	int index = 0, len, len2;
	char *temp;
	struct stat st;

	len = _strlen(argv[0]);

	while (paths[index])
	{
		len2 = _strlen(paths[index]) + 2;
		temp = malloc(sizeof(char) * (len + len2));
		if (temp == NULL)
		{
			_free(paths), _free(path_copy);
			return (NULL);
		}

		temp = path_cat(temp, paths[index++], argv[0]);
		if (stat(temp, &st) == 0)
		{
			argv[0] = temp;
			_free(paths), _free(path_copy);
			return (argv);
		}
		_free(temp);
	}
	_free(paths), _free(path_copy);

	return (NULL);
}

/**
 * path_cat - concat path and file name
 * @dest: points to the location where the new path will be saved
 * @path: points to the path name
 * @file: points to the file name
 *
 * Return: a pointer to the new path
 */

char *path_cat(char *dest, char *path, char *file)
{
	dest = _strcpy(dest, path);
	dest = _strcat(dest, "/");
	dest = _strcat(dest, file);

	return (dest);
}
