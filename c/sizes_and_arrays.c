#include <stdio.h>

int main(int argc, char *argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name1[] = "Zed";
  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
  };

  // WARNING: On some systems you may have to change the
  // %ld in this code to a %u since it will use unsigned ints
  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n",
  sizeof(areas));
  printf("The number of ints in areas: %ld\n",
  sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d.\n",
  areas[0], areas[1]);

  printf("The size of a char: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n",
  sizeof(name1));
  printf("The number of chars: %ld\n",
  sizeof(name1) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n",
  sizeof(full_name));
  printf("The number of chars: %ld\n",
  sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name=\"%s\"\n",
  name1, full_name);


  int numbers[4] = {0};
  char name[4] = {'a'};

  // first, print them out raw
  printf("numbers: %d %d %d %d\n",
  numbers[0], numbers[1],
  numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
  name[0], name[1],
  name[2], name[3]);

  printf("name: %s\n", name);

  // setup the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // setup the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  // then print them out initialized
  printf("numbers: %d %d %d %d\n",
  numbers[0], numbers[1],
  numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
  name[0], name[1],
  name[2], name[3]);

  // print the name like a string
  printf("name: %s\n", name);

  // another way to use name
  char *another = "Zed";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c\n",
  another[0], another[1],
  another[2], another[3]);

  int i = 0;
  // go through each string in argv
  // why am I skipping argv[0]?
  for(i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  // let's make our own array of strings
  char *states[] = {
    "California", "Oregon",
    "Washington", "Texas"
  };
  int num_states = 4;

  for(i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  i = 0;  // watch for this
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return 0;
}
