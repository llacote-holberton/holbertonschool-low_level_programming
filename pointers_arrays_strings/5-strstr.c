#include "main.h"
#define NULL ((void *)0)

/**
 * *_strstr - gets position of the start of substring.
 * @haystack: pointer to string (array of characters) we want to search.
 * @needle:  pointer to substring (array of characters) we want to find.
 *
 * Description: finds the first occurrence of asubstring needle
 *   in the string haystack. The terminating null bytes (\0) are not compared.
 *
 * Return: pointer to char OR NULL if not found.
 *
 */
char *_strstr(char *haystack, char *needle)
{
	/* This time we want to get a full string so, while parsing haystack...  */
	/* We must FIRST find the occurence of the first character of needle.    */
	/* IF/WHEN we find it...                                                 */
	/*  1/ we "save" that "start position" in case we actually found needle  */
	/*     (easiest way mechanically is using offset target so FOR loop)     */
	/*  2/ we try to have an exact match by comparing from current pos       */
	/*        each character with matching pos in needle...                  */
	/*     Case a) We find different character in next position              */
	/*          -> we break inner loop and resume.                           */
	/*     Case b) AS SOON AS WE FOUND the WHOLE sequence                    */
	/*          -> We set state "needle_found" and stop inner loop.          */
	/*  3/ Primary loop must stop when whichever comes first between         */
	/*     End of haystack traversal OR "needle_found" (== 1);               */
	/*  4/ We return either start position or NULL if needle never found.    */
	int needle_found = 0;
	char *needle_start;
	char *searcher = haystack;
	/* Iterator: inner loop index (comparing substring with needle). */
	int i;

	while (!needle_found && *searcher)
	{
		if (*searcher == *needle)
		{
			needle_start = searcher;
			/* Try and parse substring matching needle */
			for (i = 0; searcher[i] && searcher[i] == needle[i]; i++)
			;
			/* If success we should have needle[i] being EOL char. */
			needle_found = (needle[i] == '\0');
		}
		/* Using the automatic conversion int -> truthy value -> int) */
		searcher += (!needle_found);
	}

	return ((needle_found) ? needle_start : NULL);
}
