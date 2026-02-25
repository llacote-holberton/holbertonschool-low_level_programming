/**
 * _isupper - Checks whether input char is uppercase.
 * @c: integer number representing ASCII value of character.
 * Description: takes given character and checks
 *   whether it is within uppercase character set
 * Return: boolean (1 = success)
 */
int _isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
