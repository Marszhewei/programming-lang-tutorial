package main

import (
	"fmt"
)

type Animal struct {
	name string
}

func (anim *Animal) move() {
	fmt.Printf("%s can move.\n", anim.name)
}

type Dog struct {
	feet    byte
	*Animal // inherit
}

func (dog *Dog) buck() {
	fmt.Printf("%s can wangwangwang.\n", dog.name)
}

func testInherit() {
	dog := &Dog{
		feet: 4,
		Animal: &Animal{
			name: "lele",
		},
	}
	dog.buck()
	dog.move()
}
