#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char** argv) {
    // Validate and extract command line arguments
    if (argc != 6) {
        fprintf(stderr , "Invalid input. Please provide all the required arguments.\n");
        exit(1);
    }

    double starting_balance = atof(argv[1]);
    double monthly_contribution = atof(argv[2]);
    double annual_rate_of_return = atof(argv[3]);
    double annual_rate_of_inflation = atof(argv[4]);
    int years_until_retirement = atoi(argv[5]);

    // Calculate monthly rate of return and inflation
    double monthly_rate_of_return = pow(1 + annual_rate_of_return, 1.0 / 12) - 1;
    double monthly_rate_of_inflation = pow(1 + annual_rate_of_inflation, 1.0 / 12) - 1;

    // Generate amortization table
    printf("Month    Interest     Balance\n");
    double balance = starting_balance;
    for (int month = 1; month <= years_until_retirement * 12; month++) {
        double interest = balance * monthly_rate_of_return;
        double real_interest = interest - balance * monthly_rate_of_inflation;
        balance += interest + monthly_contribution;
        printf("%4d $ %10.2f $ %10.2f\n", month, real_interest, balance);
    }

    return 0;
}