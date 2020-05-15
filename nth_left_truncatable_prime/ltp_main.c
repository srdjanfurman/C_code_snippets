#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LTP 999962683	/* 1000000000 */
#define MAX_N_TH_LTP 2166

/* Definition and variables for "elapsed time" testing purpose. */
#define NANOS 1000000000LL
struct timespec ts_start;
struct timespec ts_end;
long long start = 0;
long long end = 0;
double time_val = 0.0;

uint32_t cnt = 2;
uint32_t ltp_array[MAX_N_TH_LTP] = {0};

uint32_t check_prime(uint32_t n)
{
	uint32_t p;
	if (n % 3 == 0)
	{
		return 0;
	}

	for (p = 6; p * p <= n; p += 6)
	{
		if (!(n % (p + 1) && n % (p + 5)))
		{
			return 0;
		}
	}
	return 1;
}

void left_truncatable(uint32_t n, uint32_t tens)
{
	uint32_t k, lt_prime;
	static uint32_t l = 0;
	if (n < MAX_LTP / 10)
	{
		for (tens *= 10, k = 1; k < 10; k++)
		{
			if (check_prime(lt_prime = k * tens + n))
			{
				if (lt_prime)
				{
					ltp_array[l++] = lt_prime;
				}
				left_truncatable(lt_prime, tens);
			}
		}
	}
	cnt++;
}

void sort_in_asc()
{
	uint32_t i, j, tmp;
	for (i = 0; i < cnt; ++i)
	{
		for (j = i+1; j < cnt; ++j)
		{
			if (ltp_array[i] > ltp_array[j])
			{
				tmp = ltp_array[i];
				ltp_array[i] = ltp_array[j];
				ltp_array[j] = tmp;
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf ("Usage: Nth_left_truncatable_prime <nth_ltp>\n");
		return 0;
	}

	uint16_t ref = 0;
	ref = atoi(argv[1]);
	if (ref > 2166)
	{
		return 0;
	}

	// -------> Start measuring time ------->
	clock_gettime (CLOCK_MONOTONIC, &ts_start);
	left_truncatable(3, 1);
	left_truncatable(7, 1);
	sort_in_asc();
	// <------- End measuring time <-------
	clock_gettime (CLOCK_MONOTONIC, &ts_end);

	// Display time results.
	start = (ts_start.tv_sec * NANOS) + ts_start.tv_nsec;
	end = (ts_end.tv_sec * NANOS) + ts_end.tv_nsec;
	time_val = (end - start) / 1000000000.0;		/* duration in sec. */
	printf("Time duration: %lf sec.\n", time_val);
	printf("Number = %d\n", ltp_array[ref-1]);

	return 0;
}

