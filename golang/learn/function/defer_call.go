package function

import (
	"errors"
	"fmt"
	"io"
	"net/http"
)

func testDefer() {
	var whatever [5]int
	for i := range whatever {
		defer fmt.Println(i)
	}
}

func pt(i *int) {
	fmt.Println(*i)
}

type Test struct {
	name string
}

func (t *Test) close() {
	fmt.Println(t.name, " closed.")
}

func foo(a, b int) (i int, err error) {
	defer fmt.Printf("first defer err %v\n", err)
	defer func(err error) { fmt.Printf("second defer err %v\n", err) }(err)
	defer func() { fmt.Printf("third defer err %v\n", err) }()
	if b == 0 {
		err = errors.New("divided by zero")
		return
	}

	i = a / b
	return
}

func bar() (i int) {
	i = 0
	defer func() {
		fmt.Println(i)
	}()
	return 11
}

func returnNil() {
	var run func() = nil
	defer run()
	fmt.Println("runs")
}

func do() error {
	res, err := http.Get("https://www.google.com")
	if res != nil {
		defer func(Body io.ReadCloser) {
			bErr := Body.Close()
			if bErr != nil {
				err = bErr
				// some log here
			}
		}(res.Body)
	}
	if err != nil {
		return err
	}
	return nil
}

func DeferTest() {
	testDefer()

	// defer + closure
	var whatever [5]struct{}
	for i := range whatever {
		//i := i
		defer func() { fmt.Println(i) }()
		//defer pt(&i)
	}

	ts := []Test{{"a"}, {"b"}, {"c"}}
	for _, t := range ts {
		tt := t
		defer tt.close()
	}

	// defer + closure
	ii, err := foo(2, 0)
	if err != nil {
		fmt.Printf("ii value: %v\n", ii)
	}

	// defer + return
	bar()

	// defer + nil
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()
	returnNil()

	do()
}
