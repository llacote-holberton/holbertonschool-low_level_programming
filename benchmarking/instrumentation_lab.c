#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return sum;
}

int main(void)
{
	unsigned long checksum;

	/* Students must add clock-based timing and print required lines. */
	/* @note "cheating" a bit by using "next step start" as "previous one end" */
	/*   because each function starts immediately after the previous. */
	clock_t build_start;
	clock_t process_start;
	clock_t checksum_start;
	/* @note not strictly necessary but easier to have it */
	clock_t end;

	build_start = clock();
	build_dataset();

	process_start = clock();
	process_dataset();

	checksum_start = clock();
	checksum = reduce_checksum();
	end = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	/* @note precision requires converting to float */
	/* @note CLOCKS_PER_SEC is constant provided from time.h */
	printf("TOTAL seconds: %f\n", (double)(end - build_start) / (double)CLOCKS_PER_SEC );
	printf("BUILD_DATA seconds: %f\n", (double)(process_start - build_start) / (double)CLOCKS_PER_SEC );
	printf("PROCESS seconds: %f\n", (double)(checksum_start - process_start) / (double)CLOCKS_PER_SEC );
	printf("REDUCE seconds: %f\n", (double)(end - checksum_start) / (double)CLOCKS_PER_SEC );


	/* Required output (exact format, no extra lines):
	 * TOTAL seconds: <float>
	 * BUILD_DATA seconds: <float>
	 * PROCESS seconds: <float>
	 * REDUCE seconds: <float>
	 */

	return 0;
}
