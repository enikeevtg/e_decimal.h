#include <stdio.h>

void func1(int n) {
  n--;
  if (n) func1(n);
  printf("%d\n", n);
}

int func2(int n) {
  n--;
  if (!n) return 0;
  printf("%d\n", n);
  func2(n);
}

int main(int argc, char** argv) {
  int n = 3;
  func1(n);
  func2(n);
  return 0;
}
