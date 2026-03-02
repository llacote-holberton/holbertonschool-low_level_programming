/**
 * swap_int - swaps the values of two given integers.
 * @a: integer.
 * @b: integer
 * Description: swaps the values of provided integers.
 * Return: void.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
