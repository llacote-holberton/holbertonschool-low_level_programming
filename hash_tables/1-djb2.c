/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 *
 * NOTE: shamelessly copypasted (with authorization) from
 * https://gist.github.com/papamuziko/7bb52dfbb859fdffc4bd0f95b76f71e8
 * Explaining comments are all me though. :)
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	/* Base "offset value", decided arbitrarily (I think). */
	hash = 5381;
	/* Loop made to "condense" characters of a string by   */
	/*   "multiplying current value by 33" through         */
	/*   bit-wise operations and adding the numeric value  */
	/*   of current character. Then "consuming" the next.  */
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
