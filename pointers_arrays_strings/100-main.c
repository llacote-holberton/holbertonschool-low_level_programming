#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int nb;

	/* Expected: 98 */
	nb = _atoi("98");
	printf("%d\n", nb);
	/* Expected: -402 */
	nb = _atoi("-402");
	printf("%d\n", nb);
	/* Expected: -98 */
	nb = _atoi("          ------++++++-----+++++--98");
	printf("%d\n", nb);
	/* Expected: 214748364 */
	nb = _atoi("214748364");
	printf("%d\n", nb);
	/* Expected: 0 */
	nb = _atoi("0");
	printf("%d\n", nb);
	/* Expected: 402 */
	nb = _atoi("Suite 402");
	printf("%d\n", nb);
	/* Expected: 98 */
	nb = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
	printf("%d\n", nb);
	/* Expected: 402 */
	nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
	printf("%d\n", nb);
	/* Expected: 777 */
	nb = _atoi("My test string --++ 777.666");
	printf("%d\n", nb);
	/* Expected: -666 */
	nb = _atoi("My test string -------------.666.999");
	printf("%d\n", nb);

	return (0);
}
