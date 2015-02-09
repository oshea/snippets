#include <stdlib.h>
#include <stdio.h>

typedef struct Foo {
  int bar;
} Foo;

Foo *Foo_create(int bar) {
  Foo *foo = malloc(sizeof(Foo));
  printf("Created foo at %p\n", foo);
  return foo;
}

void Foo_destroy(Foo *foo) {
  printf("Destroying foo at %p\n", foo);
  free(foo);
}

int main(int argc, char **argv) {
  Foo *foo = Foo_create(5);
  Foo_destroy(foo);
  return 0;
}
