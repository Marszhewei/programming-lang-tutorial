package function

import "fmt"

func swap(x, y *int) {
	var tmp int = *x
	*x = *y
	*y = tmp
}

func add(args ...int) int {
	res := 0
	for _, i := range args {
		res += i
	}
	return res
}

func calc(a, b int) (sum int, avg int) {
	sum = a + b
	avg = sum / 2
	//if we do this
	//{
	//	var sum int = a + b
	//	var avg int = a - b
	//	return sum, avg
	//}
	return
}

func deferAdd(x, y int) (z int) {
	defer func() {
		fmt.Println(z - 3)
	}()
	z = x + y
	return z + 200
}

func ArgsTest() {
	x, y := 1, 2
	swap(&x, &y)
	fmt.Println(x, y)
	res := add(100, 100, 100, 100)
	fmt.Println(res)
	// use slice as args
	slc := []int{1, 1, 1, 1}
	res = add(slc...)
	fmt.Println(res)
	sum, _ := calc(10, 20)
	fmt.Println(sum)
	fmt.Println(calc(10, 20))
	// defer add
	fmt.Println(deferAdd(1, 2))
}
