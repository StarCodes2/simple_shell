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
