// https://www.youtube.com/watch?v=CvH9fC2eYO8&list=PLCKpcjBB_VlBsxJ9IseNxFllf-UFEXOdg&index=3

package main

import (
	"fmt"
)

var global = "Global Var" // A nível de pacote

func main() {
	const a = "null"
	x := 0    // Operador curto de atribuição (apenas a nível de bloco)
	xx := 0.6 // Operador curto de atribuição
	y := "Casa"
	z := true

	fmt.Printf("x: %v, %T\n", x, x)
	fmt.Printf("y: %v, %T\n", y, y)
	fmt.Printf("xx: %v, %T\n", xx, xx)

	numeroBytes, erros := fmt.Println("Hello!", "oi fmt", 100)
	fmt.Println("Bytes", numeroBytes, erros, global)
	fmt.Println(x, y, z)
	fmt.Print()

}
