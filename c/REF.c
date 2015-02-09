// DATA TYPES, OPERATORS AND KEYWORDS:  http://c.learncodethehardway.org/book/ex21.html

// POINTERS

int* p; // pointer to an integer
int i; // integer value


// You turn a pointer into a value with *:

int i2 = *p; // integer value


// You turn a value into a pointer with &:

int* p2 = &i; // pointer to an integer


// Edit: In the case of arrays, they are treated very much like pointers. If you think of them as pointers, you'll be using * to get at the values inside of them as explained above, but there is also another, more common way using the [] operator:

int a[2];  // array of integers
int i = *a; // the value of the first element of a
int i2 = a[0]; // another way to get the first element


//To get the second element:

int a[2]; // array
int i = *(a + 1); // the value of the second element
int i2 = a[1]; // the value of the second element


//So the [] indexing operator is a special form of the * operator, and it works like this:

a[i] == *(a + i);  // these two statements are the same thing

// STRUCTS

struct some_struct p; // Declaring struct value
struct some_struct *ptr; // Declaring struct reference

ptr = &p; // Assiging memory reference of p to pointer ptr

p.member // For struct value member reference

(*ptr).member // For stuct reference member reference
ptr->member // Also works for struct reference member reference
