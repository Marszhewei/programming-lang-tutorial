package med

import (
	"errors"
	"fmt"
	"os"
	"time"
)

type S struct {
	T
}

type T struct {
	int
}

func (t T) testT() {
	fmt.Println("S and *S contains T method")
}

func (t *T) testP() {
	fmt.Println("S and *S contains *T method")
}

type User struct {
	id   int
	name string
}

func (tu *User) testUser() {
	fmt.Printf("%p, %v\n", tu, tu)
}

func (tp *User) testPointer() {
	fmt.Printf("test pointer: %p, %v\n", tp, tp)
}

func (tv User) testValue() {
	fmt.Printf("test value: %p, %v\n", &tv, tv)
}

func TestMethod() {
	s1 := S{T{1}}
	s2 := &s1
	fmt.Printf("s1 is : %v\n", s1)
	s1.testT()
	s1.testP()
	fmt.Printf("s2 is : %v\n", s2)
	s2.testT()
	s2.testP()

	u := User{1, "Tom"}
	u.testUser()
	mv := u.testUser
	mv()
	me := (*User).testUser
	me(&u)

	fmt.Printf("user: %p, %v\n", &u, u)
	mv1 := User.testValue
	mv1(u)
	mp := (*User).testPointer
	mp(&u)
	mp1 := (*User).testValue
	mp1(&u)
}

// define error by self
func test01() {
	a := [5]int{0, 1, 2, 3, 4}
	a[1] = 123
	fmt.Println(a)
	//a[10] = 11
	index := 10
	a[index] = 10
	fmt.Println(a)
}

func getCircleArea(radius float32) (area float32) {
	if radius < 0 {
		panic("radius can't be negative")
	}
	return 3.14 * radius * radius
}

func test02() {
	area := getCircleArea(-6.0)
	fmt.Println(area)
}

func test03() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()
	getCircleArea(-5)
	fmt.Println("here is the end of test04?")
}

func test04() {
	test03()
	fmt.Println("test04")
}

func TestSelfError() {
	//test01()
	//test02()
	test04()
}

func getCR(radius float32) (area float32, err error) {
	if radius < 0 {
		err = errors.New("radius can't be negative")
		return
	}
	area = 3.14 * radius * radius
	return
}

func ReturnError() {
	area, err := getCR(5.0)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(area)
	}
}

type PathError struct {
	path       string
	op         string
	createTime string
	message    string
}

func (p *PathError) Error() string {
	return fmt.Sprintf("path=%s \nop=%s \ncreateTime=%s \nmessage=%s", p.path,
		p.op, p.createTime, p.message)
}

func Open(filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		return &PathError{
			path:       filename,
			op:         "read",
			message:    err.Error(),
			createTime: fmt.Sprintf("%v", time.Now()),
		}
	}

	defer file.Close()
	return nil
}

func DefineSelfError() {
	err := Open("../database/data.txt")
	switch v := err.(type) {
	case *PathError:
		fmt.Println("get path error,", v)
	default:
	}
}
