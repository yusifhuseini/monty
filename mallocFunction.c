#include "monty.h"

/**
 *_strcmp - Compares two strings.
 *@s1: The first string to compare.
 *@s2: The second string to compare.
 *Return: 0 if s1 and s2 are equal, another value if they are different.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}

	if (s1[i] > s2[i])
	{
		return (1);
	}
	else if (s1[i] < s2[i])
	{
		return (-1);
	}

	return (0);
}

/**
 *_char_in_string - Checks if a character is inside a string.
 *@s: The string to search.
 *@c: The character to find.
 *Return: 1 if found, 0 if not found.
 */
int _char_in_string(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}

		i++;
	}

	return (0);
}

/**
 *_strtoky - Tokenizes a string based on delimiters.
 *@s: The string to tokenize.
 *@delimiters: The delimiters to use for tokenization.
 *Return: A pointer to the first partition.
 */
char *_strtoky(char *s, char *delimiters)
{
	static char *lastToken;
	int i = 0, j = 0;

	if (!s)
	{
		s = lastToken;
	}

	while (s[i] != '\0')
	{
		if (!_char_in_string(delimiters, s[i]) && s[i + 1] == '\0')
		{
			lastToken = s + i + 1;
			*lastToken = '\0';
			s = s + j;
			return (s);
		}
		else if (!_char_in_string(delimiters, s[i]) &&
								_char_in_string(delimiters, s[i + 1]) == 0)
		{
			i++;
		}
		else if (!_char_in_string(delimiters, s[i]) &&
								_char_in_string(delimiters, s[i + 1]) == 1)
		{
			lastToken = s + i + 1;
			*lastToken = '\0';
			lastToken++;
			s = s + j;
			return (s);
		}
		else if (_char_in_string(delimiters, s[i]))
		{
			j++;
			i++;
		}
	}

	return (NULL);
}
