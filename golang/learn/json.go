package main

import (
	"encoding/json"
	"fmt"
)

type Student struct {
	id     int
	Gender string
	Name   string
}

type Class struct {
	title    string
	Students []*Student
}

func testJson() {
	c := &Class{
		title:    "101",
		Students: make([]*Student, 0, 200),
	}
	for i := 0; i < 10; i++ {
		stu := &Student{
			Name:   fmt.Sprintf("stu%02d", i),
			Gender: "male",
			id:     i,
		}
		c.Students = append(c.Students, stu)
	}

	data, err := json.Marshal(c)
	if err != nil {
		fmt.Println("json marshal failed.")
		return
	}
	fmt.Printf("json:%s\n", data)
	str := `{"Title":"101","Students":[
			{"ID":0,"Gender":"male","Name":"stu00"},
			{"ID":1,"Gender":"male","Name":"stu01"},
			{"ID":2,"Gender":"male","Name":"stu02"},
			{"ID":3,"Gender":"male","Name":"stu03"},
			{"ID":4,"Gender":"male","Name":"stu04"},
			{"ID":5,"Gender":"male","Name":"stu05"},
			{"ID":6,"Gender":"male","Name":"stu06"},
			{"ID":7,"Gender":"male","Name":"stu07"},
			{"ID":8,"Gender":"male","Name":"stu08"},
			{"ID":9,"Gender":"male","Name":"stu09"}]}`
	c1 := &Class{}
	err = json.Unmarshal([]byte(str), c1)
	if err != nil {
		fmt.Println("json unmarshal failed!")
		return
	}
	fmt.Printf("%#v\n", c1)

	// json tag
	type Person struct {
		ID   byte   `json:"id"`
		name string // private, can't be visited by json
	}
	p1 := Person{
		ID:   1,
		name: "jack",
	}
	data, err = json.Marshal(p1)
	if err != nil {
		fmt.Println("json marshal failed.")
		return
	}
	fmt.Printf("json str:%s\n", data)
}
