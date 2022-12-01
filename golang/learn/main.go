package main

import (
	"fmt"
	"math/rand"
	"os"
	"sort"
	"time"
)

// first call init function in learn/demo, then call main function
import _ "learn/demo"
import fc "learn/function"
import med "learn/med"

func main() {
	fmt.Println("This is main function.")

	// use _ in source code
	osTest()
	varTest()
	constTest()
	charTest()
	arrayTest()
	sliceTest()
	pointerTest()
	mapTest()
	typeTest()
	structTest()
	testInherit()
	testJson()
	testSwitch()
	testSelect()
	testLoop()
	fc.DefineTest()
	fc.ArgsTest()
	fc.AnonymousTest()
	fc.ClosureTest()
	fc.DeferTest()
	fc.ErrorTest()
	med.TestMethod()
	med.TestSelfError()
	med.ReturnError()
	med.DefineSelfError()
	med.TestInterface()
}

func osTest() {
	buf := make([]byte, 1024)
	// ignore err(throw the error to _ because we don't need it)
	f, _ := os.Open("./database/data.txt")
	defer func(f *os.File) {
		err := f.Close()
		if err != nil {

		}
	}(f)
	for {
		n, _ := f.Read(buf)
		if n == 0 {
			break
		}
		_, err := os.Stdout.Write(buf[:n])
		if err != nil {
			return
		}
	}
}

func varTest() {
	// we must use this variables
	var name string = "jack"
	var age byte = 20
	var isOk bool = false
	fmt.Printf("name: %s, age: %d, is ok: %t\n", name, age, isOk)

	// also we can use var ()
	var (
		firstName string = "jack"
		lastName  string = "chen"
	)
	// or
	//var firstName, lastName string = "jack", "chen"
	fmt.Printf("hello %s %s\n", firstName, lastName)

	// in function, we can use := to init var
	m, n := 10, 20
	fmt.Println(m, n)

	// multiple lines string
	s := `hello
every one`
	fmt.Println(s)
}

func constTest() {
	const pi float64 = 3.1415
	const e float64 = 2.7182
	// or
	//const (
	//	pi float64 = 3.1415
	//	e float64 = 2.7182
	//)

	// the same value as the up const value
	const (
		n1 int32 = 100
		n2
		n3
	)

	// const count iota
	const (
		m1 = iota // m1 = 0
		m2        // m2 = 1
		m3        // m3 = 2
	)
	// we can use _ to pass some value
	const (
		t1 = iota // t1 = 0
		t2        // t2 = 1
		_
		t4 // t4 = 3
	)

	// we can insert value
	const (
		f1 = iota // f1 = 0
		f2 = 100  // f2 = 100
		f3        // f3 = 2
		f4        // f4 = 3
	)
	const f5 = iota // f5 = 0

	// an example
	const (
		_  = iota
		KB = 1 << (10 * iota)
		MB = 1 << (10 * iota)
		GB = 1 << (10 * iota)
		TB = 1 << (10 * iota)
		PB = 1 << (10 * iota)
	)

	const (
		a, b = iota + 2, iota + 1 // 2, 1
		c, d                      // 3, 2
	)
	fmt.Printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d)
}

func charTest() {
	var c1 rune = '中'
	var c2 byte = 'z'
	fmt.Printf("rune char: %c(%#X), ascii char: %c(%#X)\n", c1, c1, c2, c2)

	// modify string
	s1 := "hello"
	bytes1 := []byte(s1)
	bytes1[0] = 'H'
	fmt.Println(string(bytes1))

	s2 := "博客"
	runes2 := []rune(s2)
	runes2[0] = '黑'
	fmt.Println(string(runes2))
}

var outArr [5]int64 = [5]int64{1, 2, 3}
var outArr1 = [...]int64{1, 2, 3, 4, 5}
var outStrArr = [5]string{3: "hello,world", 4: "tom"}

var _2dOutArr [5][3]int64
var _2dOutArr1 [2][3]int64 = [...][3]int64{{1, 2, 3}, {4, 5, 6}}

func arrayTest() {
	innerArr := [5]int64{1, 2}
	innerArr1 := [...]int64{1, 2, 3, 4}
	innerArr2 := [5]int64{2: 100, 4: 200}
	structArr := [...]struct {
		name string
		age  byte
	}{
		{"user1", 10},
		{"user2", 20},
	}
	fmt.Println(outArr, outArr1)
	fmt.Println(outStrArr)
	fmt.Println(innerArr, innerArr1, innerArr2)
	fmt.Println(structArr)

	// multidimensional arrays
	_2dInnerArr := [2][3]int64{{1, 2, 3}, {4, 5, 6}}
	_2dInnerArr1 := [...][2]int64{{1, 2}, {3, 4}, {5, 6}}
	fmt.Println(_2dOutArr, _2dOutArr1)
	fmt.Println(_2dInnerArr, _2dInnerArr1)

	// traverse array
	var f [2][3]int = [...][3]int{{1, 2, 3}, {7, 8, 9}}
	for k1, v1 := range f {
		for k2, v2 := range v1 {
			fmt.Printf("(%d, %d) = %d ", k1, k2, v2)
		}
		fmt.Println()
	}

	// pass array to function
	rand.Seed(time.Now().Unix())
	var arr [10]int64
	for i := 0; i < len(arr); i++ {
		arr[i] = rand.Int63n(1000)
	}
	fmt.Println(arr)
	sum := changeFirstElem(&arr, 10)
	fmt.Println(arr)
	fmt.Printf("sum is: %d\n", sum)

	// find two nums in arr equals target
	var baseArr [10]int
	for i := 0; i < len(baseArr); i++ {
		baseArr[i] = rand.Intn(100)
	}
	for i := 0; i < 10; i++ {
		target := rand.Intn(200)
		if sumOfTwo(&baseArr, target) {
			fmt.Println("find it")
		}
	}
}

func changeFirstElem(arr *[10]int64, val int64) int64 {
	arr[0] = val
	var sum int64 = 0
	for i := 0; i < len(arr); i++ {
		sum += arr[i]
	}
	return sum
}

func sumOfTwo(arr *[10]int, target int) bool {
	for i := 0; i < len(arr)-1; i++ {
		another := target - arr[i]
		for j := i + 1; j < len(arr); j++ {
			if arr[j] == another {
				return true
			}
		}
	}
	return false
}

/**
 * slice is not array or array pointer
 * slice is reference
 */
func sliceTest() {
	// define slice
	var s []int // use this to define an empty slice
	if s == nil {
		fmt.Println("this slice is empty.")
	} else {
		fmt.Println("not empty.")
	}
	// use :=
	s1 := []int{1, 2}
	// use make (make ([]type len, cap))
	var s2 []int = make([]int, 0)
	fmt.Println(s, s1, s2)

	// init slice
	var s3 []int = make([]int, 10, 10)
	fmt.Println(s3)

	// slice from array
	arr := [5]int{1, 2, 3, 4, 5}
	var s4 []int
	s4 = arr[1:4]           // 2 3 4
	s4[0], s4[1] = 100, 200 // the array has changed
	fmt.Println(arr)

	s5 := []int{0, 1, 2, 3, 8: 100}
	fmt.Println(s5, len(s5), cap(s5))
	s6 := make([]int, 6, 8)
	fmt.Println(s6, len(s6), cap(s6))

	ss := []int{0, 1, 2, 3}
	p := &ss[2]
	*p += 100
	fmt.Println(ss)

	data := [][]int{
		[]int{1, 2, 3},
		[]int{100, 200},
		[]int{11, 22, 33, 44},
	}
	fmt.Println(data)

	// modify slice
	d := [5]struct {
		x int
	}{}
	sd := d[:]
	d[1].x, sd[2].x = 10, 20
	fmt.Println(d)
	fmt.Printf("%p, %p\n", &d, &d[0])

	// use append
	var a []int = []int{1, 2, 3}
	fmt.Printf("slice a : %v\n", a)
	var b []int = []int{4, 5, 6}
	fmt.Printf("slice b : %v\n", b)
	c := append(a, b...)
	fmt.Printf("slice c : %v\n", c)
	e := append(c, 7, 8, 9)
	fmt.Printf("slice d : %v\n", e)

	// over slice cap, reallocation
	tmp := [...]int{0, 1, 2, 3, 4, 10: 0}
	st := tmp[:2:3]           // max cap = 3
	st = append(st, 100, 200) // add 2 elems, reallocation
	fmt.Println(st, tmp)
	fmt.Println(&st[0], &tmp[0])

	// copy
	t1 := []int{1, 2, 3}
	t2 := make([]int, 10, 16)
	copy(t1, t2)
	fmt.Println(t1)

	// traverse slice
	ar := [...]int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	slice := ar[:]
	for index, value := range slice {
		fmt.Printf("index : %v, value : %v\n", index, value)
	}

	// string and slice
	str := "hello golang."
	sStr1 := str[0:5]
	sStr2 := str[6:]
	fmt.Println(sStr1, sStr2)
	// we can't change the string
	sss := []rune(str)
	sss[6] = 'G'
	str = string(sss)
	fmt.Println(str)
}

func pointerTest() {
	a := 10
	pa := &a
	fmt.Printf("a:%d, &a:%p\n", a, &a)
	fmt.Printf("pa:%p, type:%T\n", pa, pa)
	b := *pa
	fmt.Printf("type of b: %T\n", b)
	fmt.Printf("value of b: %v\n", b)

	var p *string
	fmt.Printf("the value of p is: %v\n", p)
	if p != nil {
		fmt.Println("not empty.")
	} else {
		fmt.Println("is empty.")
	}

	// ues new and make
	pIntVal := new(int)
	var pBoolVal *bool = new(bool)
	fmt.Printf("pIntVal: %T\n", pIntVal)
	fmt.Printf("pBoolVal: %T\n", pBoolVal)
	var m map[string]int = make(map[string]int, 10)
	m["test"] = 10
	fmt.Println(m)
}

/**
* map[keyType]valueType
 */
func mapTest() {
	scoreMap := make(map[string]int)
	scoreMap["jack"] = 100
	scoreMap["fetch150zy"] = 99
	fmt.Printf("score map type: %T\n", scoreMap)
	fmt.Println(scoreMap)

	userInfo := map[string]string{
		"username": "example.com",
		"password": "admin123",
	}
	fmt.Println(userInfo)

	// key exist?
	value, ok := userInfo["username"]
	if ok {
		fmt.Println(value)
	} else {
		fmt.Println("not found.")
	}

	// traverse map
	for k, v := range scoreMap {
		fmt.Println(k, v)
	}

	// delete key-value pair
	delete(scoreMap, "jack")
	// only for key
	for key := range scoreMap {
		fmt.Println(key)
	}

	sortMap()

	// map slice
	var mapSlice = make([]map[string]string, 3)
	for index, value := range mapSlice {
		fmt.Printf("index:%d value:%v\n", index, value)
	}
	fmt.Println("after init")
	mapSlice[0] = make(map[string]string, 10)
	mapSlice[0]["name"] = "jack"
	mapSlice[0]["password"] = "123456"
	mapSlice[0]["address"] = "xdu"
	for index, value := range mapSlice {
		fmt.Printf("index:%d value:%v\n", index, value)
	}

	// slice map
	var sliceMap = make(map[string][]string, 3)
	fmt.Println(sliceMap)
	fmt.Println("after init")
	key := "china"
	v, right := sliceMap[key]
	if !right {
		v = make([]string, 0, 2)
	}
	v = append(v, "beijing", "shanghai")
	sliceMap[key] = v
	fmt.Println(sliceMap)
}

func sortMap() {
	rand.Seed(time.Now().UnixNano())
	var scoreMap = make(map[string]int, 200)

	for i := 0; i < 100; i++ {
		key := fmt.Sprintf("stu%02d", i)
		value := rand.Intn(100)
		scoreMap[key] = value
	}

	var keys = make([]string, 0, 200)
	for key := range scoreMap {
		keys = append(keys, key)
	}

	sort.Strings(keys)

	for _, key := range keys {
		fmt.Println(key, scoreMap[key])
	}
}

func typeTest() {
	type newInt int
	type myInt = int
	var a newInt
	var b myInt
	fmt.Printf("type of a:%T\n", a)
	fmt.Printf("type of b:%T\n", b)
}

type person struct {
	name, city string
	age        byte
}

func structTest() {
	var p1 person
	p1.name, p1.city, p1.age = "jack", "xi'an", 18
	fmt.Printf("type of p1: %T\n", p1)
	fmt.Printf("p1 = %#v\n", p1)

	var p2 = struct {
		name string
		age  byte
	}{
		"fetch150zy",
		18,
	}
	fmt.Printf("type of p2: %T\n", p2)
	fmt.Printf("p2 = %#v\n", p2)

	var p3 = new(person)
	p3.name, p3.city, p3.age = "fetch150zy", "xi'an", 21
	fmt.Printf("type of p3: %T\n", p3)
	fmt.Printf("p3 = %#v\n", p3)

	p4 := &person{
		name: "mars",
		city: "beijing",
		age:  20,
	}
	fmt.Printf("type of p4: %T\n", p4)
	fmt.Printf("p4 = %#v\n", p4)

	type test struct {
		a int8
		b int8
		c int8
		d int8
	}
	n := test{
		1, 2, 3, 4,
	}
	fmt.Printf("n.a %p\n", &n.a)
	fmt.Printf("n.b %p\n", &n.b)
	fmt.Printf("n.c %p\n", &n.c)
	fmt.Printf("n.d %p\n", &n.d)

	type student struct {
		name string
		age  int
	}
	m := make(map[string]*student)
	sts := []student{
		{name: "pprof.cn", age: 18},
		{name: "test", age: 23},
		{name: "blog", age: 28},
	}

	for _, stu := range sts {
		m[stu.name] = &stu
	}
	for k, v := range m {
		fmt.Println(k, "=>", v.name)
	}

	// constructor?
	p5 := newPerson("jack", "shanghai", 18)
	fmt.Printf("constructor: %v\n", p5)
	p5.dream()

	type demo struct {
		string
		byte
	}
	pp := demo{
		"example.com",
		18,
	}
	fmt.Printf("%#v\n", pp)
	fmt.Println(pp.string, pp.byte)

	type address struct {
		province string
		city     string
	}
	type user struct {
		name   string
		gender string
		address
	}
	user1 := user{
		name:   "fetch150zy",
		gender: "male",
		//address: address{
		//	province: "anhui",
		//	city:     "bengbu",
		//},
	}
	user1.address.province = "shannxi"
	user1.city = "xi'an"
	fmt.Printf("user1=%#v\n", user1)
}

func newPerson(name, city string, age byte) *person {
	return &person{
		name: name,
		city: city,
		age:  age,
	}
}

func (p *person) dream() {
	fmt.Printf("%s's dream is to learn golang.\n", p.name)
}

func (p *person) setAge(newAge byte) {
	p.age = newAge
}
