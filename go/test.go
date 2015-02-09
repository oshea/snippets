package main

import (
  "fmt"
  "time"
  "math/rand"
  "math"
)

func main() {
    fmt.Println("Hello. It is now: ", time.Now());

    rand.Seed(100000);
    fmt.Println("A random number: ", rand.Intn(10000));

    fmt.Printf("You have %g problems\n", math.Nextafter(2, 3));

    fmt.Printf("Adding 2 + 3 = %d\n", add(2, 3));



}


func add(x int, y int) int {
  return x + y
}
