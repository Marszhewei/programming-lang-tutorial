package function

import "fmt"

func a() func() int {
	i := 0
	b := func() int {
		i++
		fmt.Println(i)
		return i
	}
	return b
}

func baseAdd(base *int) func(int) int {
	return func(i int) int {
		*base += i
		return *base
	}
}

func ClosureTest() {
	c := a()
	fmt.Println(c())
	c()
	c()
	a()

	base := 10
	tmp1 := baseAdd(&base)
	fmt.Printf("base address: %p\n", tmp1)
	fmt.Println(tmp1(1), tmp1(2))
	fmt.Println(base)
	tmp1 = baseAdd(&base)
	fmt.Printf("base address: %p\n", tmp1)
}
