package demo

import "fmt"

// basic type in golang
/**
bool
int8 int16 int32 int64
uint8(byte) uint16 uint32 uint64
float32 float64
string
complex64 complex128
array
*/

// reference type
/**
slice
map
chan
*/

// builtin function
/**
append  (add elems to array, slice, return array, slice)
close 	(close chan)
delete 	(delete key-val in map)
panic	(stop goroutine)
recover	(define goroutine panic)
real 	(return real part of complex)
imag 	(return image part of complex)
make 	(malloc memory, for slice, map, channel, return type self)
new 	(malloc memory, for int, struct, return pointer of type)
cap		(return capacity of slice and map)
copy 	(copy slice, return the number of copy)
len		(get length of string, array, slice, map, channel)
print,println	(low level print function)
*/

func init() {
	fmt.Println("imp-init() come here.")
}

func Print() {
	fmt.Println("Hello!")
}
