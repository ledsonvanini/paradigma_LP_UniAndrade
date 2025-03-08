package main

import "fmt"

var x int = 10 // Global Int

var y = 22
func main() {
	x := 0    // Operador curto de atribuição (apenas a nível de bloco)
	xx := 0.6 // Operador curto de atribuição
	y := "Casa"
	z := true

	fmt.Printf("x: %v, %T\n", x, x)
	fmt.Printf("y: %v, %T\n", y, y)
	fmt.Printf("xx: %v, %T\n", xx, xx)
	fmt.Printf("z: %v, %T\n", z, z)

}
