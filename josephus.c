#include <stdio.h>
/* Problem Statement
* Josephus problem:
* 41 soldiers are seated in a circle.
* Starting from the first soldier, each will kill the next alive soldier in the circle
* In which position would you need to sit in order to survive?
* 
* There is the simple general solution (the formula for circle size n),
* and the general formula (size n and step k; where in the above the step is 2, every 2nd soldier dies).
* (the original josephus is for k=3, but I find the solution to k=2 particularly enjoyable.
*/
int josephus(int x); 
int g(int n, int k);

int main() {
  int x = 42;
  printf("i; k=2, k=3\n");
  for (int i=0; i < x; i++) {
      printf("%d; %d, %d\n", i, josephus(i), g(i, 3));
  }
  return 0;
}

int josephus(int n) {
  // for the case "k = 2" there exists an elegant binary solution
  // the last member (x) for circle size (n) can be found with
  // x = 2L + 1; 
  // where L is; n = 2^m + L
  // On paper, this is simply *moving* the highest bit to the end of the string.
  // 11011 -> 10111
  // In practice it's more involved:
  // 01011 (removed highest power of 2)
  // 10110 (x2, or, left shift 1)
  // 10111 (+1)
  if (n == 0) {
      return 0;
  }
  int i = 0;
  while (n >> i != 1) {
      i++; // finding highest hit
  }
  int m = 1 << i; // making mask
  int out = ((n ^ m) << 1) + 1;
  return out;
}

int g(int n, int k) {
  // The general formula involves a simple form of recursion.
  // After a single round, the circle size has decreased, and the round is repeated.
  // Every game therefore consists one additional step over a smaller game.
  // The game of size n can then be constructed from games size 1 -> n
  if (n == 0) {
      return 0;
  }
  int x = 0;
  for (int i=1; i <= n; i++) {
      x += k;
      x %= i;
  }
  return x+1; // calculation assumes 0-index for n length circle (0->n-1); this reverts to 1-index.
}
