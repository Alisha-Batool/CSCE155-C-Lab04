/**
 * Author: Alisha
 * Date: 19-10-23
 *
 * This program generates a multiplication table
 * of the size given as a command line argument.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if(argc != 2) {
    printf("Error: provide an integer\n");
    exit(1);
  }

  int n = atoi(argv[1]);
  if(n <= 0) {
    printf("empty table!\n");
    exit(0);
  }

  //TODO: place your code here
  // Generate and print the multiplication table
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%4d", i * j); // Use %4d to format the output
    }
    printf("\n");
  }

  return 0;
}
  