package function

import (
	"fmt"
	"math"
)

func testSqrt() {
	getSqrt := func(x float64) float64 {
		return math.Sqrt(x)
	}
	fmt.Println(getSqrt(3))
}

func AnonymousTest() {
	testSqrt()

	// --- function variable ---
	fn := func() { println("Hello, World!") }
	fn()

	// --- function collection ---
	fns := []func(x int) int{
		func(x int) int { return x + 1 },
		func(x int) int { return x + 2 },
	}
	println(fns[0](100))

	// --- function as field ---
	d := struct {
		fn func() string
	}{
		fn: func() string { return "Hello, World!" },
	}
	println(d.fn())

	// --- channel of function ---
	fc := make(chan func() string, 2)
	fc <- func() string { return "Hello, World!" }
	println((<-fc)())
}
