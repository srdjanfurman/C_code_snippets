/*
 * main.c
 *
 *  Created on: May 10, 2020
 *      Author: sfurman
 */

#include <stdio.h>
#include <string.h>
# include <assert.h>

#define DATA_LEN 20

unsigned int weighted_moving_average(unsigned int num_of_periods_to_average,
		unsigned int data_sample) {
	unsigned int i;
	unsigned int sum_of_weights = 0;
	unsigned int filtered_data = 0;
	static unsigned long sum_of_data, array_of_data[DATA_LEN];

	for (i = 0; i < num_of_periods_to_average; i++)
		sum_of_weights += (i + 1);

	sum_of_data = 0;

	memmove(&array_of_data[1], &array_of_data[0],
			sizeof(array_of_data) - sizeof(*array_of_data));
	array_of_data[0] = data_sample;

	for (i = 0; i < num_of_periods_to_average; i++) {
		unsigned int weight = num_of_periods_to_average - i;
		sum_of_data += (array_of_data[i] * weight);
	}

	filtered_data = (unsigned int) (sum_of_data / sum_of_weights);

	return filtered_data;
}

int main(int argc, char *argv[]) {
	unsigned int i;

	// Input data set.
	unsigned int data_sample[] = { 0, 1, 5, 50, 200, 500, 1000, 500, 200, 50, 5,
			1, 0 };

	// Expected output data set.
	unsigned int data_sample_filtered[] = { 0, 0, 1, 18, 81, 230, 513, 563, 480,
			336, 188, 71, 21 };

	unsigned int count = sizeof(data_sample) / sizeof(unsigned int);
	unsigned int periods_to_average = 5;

	for (i = 0; i < count; i++) {
		unsigned int result = weighted_moving_average(periods_to_average,
				data_sample[i]);

		assert(result == data_sample_filtered[i]);

		printf("%d\n", result);
	}

	return 0;
}
