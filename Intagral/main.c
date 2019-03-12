#include <stdio.h>
#include <math.h>








long double func(long double x) {

	return x * x;

}








long double dd_func(long double x) {

	return 2;

}








int main() {

	printf("This programm calculates integral through trapezoid method.\n\n");

	for (int cont = 1; cont;) {
		printf("Input the limits and the number of splitting in the following format\n\"lower_limit upper_limit number_of_splitting\"\n\n");

		long double lower_limit = 0;
		long double upper_limit = 0;
		long long int num_of_split = 0;

		scanf_s("%Lf %Lf %lli", &lower_limit, &upper_limit, &num_of_split);
		printf("\n");

		if (num_of_split <= 0) {
			printf("You input invalid number of spliting, it should be more than 0. Please, try again...\n\n");
		}
		else {

			long double step = (upper_limit - lower_limit) / (long double)num_of_split;
			long double integral = 0;
			long double max_abs_dd_func = fabs(dd_func(lower_limit));

			for (long long int i = 0; i < num_of_split; i++) {
				integral += (func(lower_limit + i * step) + func(lower_limit + (i + 1) \
					* step)) / 2;

				if (fabs(dd_func(lower_limit + (i + 1) * step)) > max_abs_dd_func) {
					max_abs_dd_func = fabs(dd_func(lower_limit + (i + 1) * step));
				}
			}

			integral *= step;
			printf("The result is %.10Lf\nwith accuracy %.10Lf\n\n", \
				integral, step * step * fabs(upper_limit - lower_limit) * max_abs_dd_func / 12);
					   			
			printf("If you want to calculate integral with another parameters input 1, else input 0\n");
			scanf_s("%d", &cont);
			printf("\n");
		}

	}

	return 0;
}