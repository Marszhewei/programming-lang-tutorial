package function

import "fmt"

func test(x, y int, s string) (int, string) {
	n := x + y
	return n, fmt.Sprintf(s, n)
}

func testFunc(fn func() int) int {
	return fn()
}

type formatFunc func(s string, x, y int) string

func format(fn formatFunc, s string, x, y int) string {
	return fn(s, x, y)
}

func DefineTest() {
	s1 := testFunc(func() int { return 100 })
	s2 := format(func(s string, x, y int) string {
		return fmt.Sprintf(s, x, y)
	}, "%d, %d", 10, 20)

	fmt.Println(s1, s2)
}
