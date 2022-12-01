package main

import (
	"fmt"
	"time"
)

func testSwitch() {
	var grad string = "B"
	var marks byte = 90

	switch marks {
	case 90:
		grad = "A"
	case 80:
		grad = "B"
	case 50, 60, 70:
		grad = "C"
	default:
		grad = "D"
	}

	switch {
	case grad == "A":
		fmt.Println("very good.")
	case grad == "B", grad == "C":
		fmt.Println("not bad.")
	case grad == "D":
		fmt.Println("bad.")
	default:
		fmt.Println("fight.")
	}

	// type switch
	var x interface{}
	// one
	switch i := x.(type) {
	case nil:
		fmt.Printf("type of x :%T\n", i)
	case int:
		fmt.Println("int type")
	case float64:
		fmt.Println("float64 type")
	case func(int) float64:
		fmt.Println("func(int) type")
	case bool, string:
		fmt.Println("bool or string type")
	default:
		fmt.Println("unknown type")
	}
	// two
	var j = 0
	switch j {
	case 0:
	case 1:
		fmt.Println("1")
	case 2:
		fmt.Println("2")
	default:
		fmt.Println("def")
	}
	// three
	var k = 0
	switch k {
	case 0:
		println("fallthrough")
		fallthrough // will print next case
	case 1:
		fmt.Println("11")
	case 2:
		fmt.Println("22")
	default:
		fmt.Println("def")
	}
	// three
	var m = 0
	switch m {
	case 0, 1:
		fmt.Println("1")
	case 2:
		fmt.Println("2")
	default:
		fmt.Println("def")
	}
	// four
	var n = 0
	switch { // if...else if...else
	case n > 0 && n < 10:
		fmt.Println("i > 0 and i < 10")
	case n > 10 && n < 20:
		fmt.Println("i > 10 and i < 20")
	default:
		fmt.Println("def")
	}
}

func testSelect() {
	var c1, c2, c3 chan int
	var i1, i2 int
	select {
	case i1 = <-c1:
		fmt.Println("received ", i1, " from c1")
	case c2 <- i2:
		fmt.Println("sent ", i2, " to c2")
	case i3, ok := <-c3:
		if ok {
			fmt.Println("received ", i3, " from c3")
		} else {
			fmt.Println("c3 is closed")
		}
	default:
		fmt.Println("no communication")
	}
	isTimeout()
}

var resChan = make(chan int)

func isTimeout() {
	select {
	case data := <-resChan:
		doData(data)
	case <-time.After(time.Second * 1):
		fmt.Println("request time out")
	}
}

func doData(data int) {
	//...
}

func testLoop() {
	// for init; condition; post { }
	// for condition { }
	// for { }
	s := "abc"
	for i, n := 0, len(s); i < n; i++ {
		fmt.Println(s[i])
	}
	n := len(s)
	for n > 0 { // while (n > 0)
		n--
		fmt.Println(s[n])
	}
	//for { // while (true)
	//	fmt.Println(s)
	//}
	// or for true { }

	// break continue goto
	for i := 0; i < 10; i++ {
		if i == 5 {
			goto gotoHere
		}
	}
gotoHere:
	fmt.Println("goto here")
}
