/**
 * _isdigit - Checks whether input char is a digit.
 * @c: integer number representing ASCII value of character.
 * Description: takes given character and checks
 *   whether it is within digits character set
 * Return: boolean (1 = success)
 */
int _isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
