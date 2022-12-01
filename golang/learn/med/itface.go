package med

import "fmt"

type Sayer interface {
	say()
}

type Mover interface {
	move()
}

type cat struct {
}

type dog struct {
}

func (c cat) say() {
	fmt.Println("miao...")
}

func (d dog) say() {
	fmt.Println("wang...")
}

func (d dog) move() {
	fmt.Println("dog can move")
}

type People interface {
	Speak(string) string
	DoNothing()
}

type Student struct{}

func (stu *Student) Speak(think string) (talk string) {
	if think == "sb" {
		talk = "hello sb"
	} else {
		talk = "hello"
	}
	return
}

func (stu Student) DoNothing() {
	fmt.Println("Do nothing.")
}

type WashingMachine interface {
	wash()
	dry()
}

type dryer struct{}

func (d dryer) dry() {
	fmt.Println("dry")
}

type haier struct {
	dryer
}

func (h haier) wash() {
	fmt.Println("wash")
}

func TestInterface() {
	var x Sayer
	c := cat{}
	d := dog{}
	x = c
	x.say()
	x = d
	d.say()
	var m Mover
	m = d
	m.move()
	pd := &dog{}
	m = pd
	m.move()

	var peo People = &Student{}
	think := "bitch"
	fmt.Println(peo.Speak(think))
	peo.DoNothing()

	h := haier{}
	var w WashingMachine
	w = h
	w.wash()
	w.dry()
}
