package test

import (
	"fmt"
	"os"
	"reflect"
	"testing"
	"time"
)

//func TestSplit(t *testing.T) {
//	got := Split("a:b:c", ":")
//	want := []string{"a", "b", "c"}
//	if !reflect.DeepEqual(want, got) {
//		t.Errorf("excepted:%v, got:%v", want, got)
//	}
//}

func TestMoreSplit(t *testing.T) {
	got := Split("abcd", "bc")
	want := []string{"a", "d"}
	if !reflect.DeepEqual(want, got) {
		t.Errorf("excepted:%v, got:%v", want, got)
	}
}

func TestSplit(t *testing.T) {
	type test struct {
		input string
		sep   string
		want  []string
	}

	tests := map[string]test{
		"simple":      {input: "a:b:c", sep: ":", want: []string{"a", "b", "c"}},
		"wrong sep":   {input: "a:b:c", sep: ",", want: []string{"a:b:c"}},
		"more sep":    {input: "abcd", sep: "bc", want: []string{"a", "d"}},
		"leading sep": {input: "枯藤老树昏鸦", sep: "老", want: []string{"枯藤", "树昏鸦"}},
	}

	//for _, tc := range tests {
	//	got := Split(tc.input, tc.sep)
	//	if !reflect.DeepEqual(got, tc.want) {
	//		t.Errorf("excepted:%v, got:%v", tc.want, got)
	//	}
	//}

	// test setup and teardown
	teardownTestCase := setupTestCase(t)
	defer teardownTestCase(t)

	for name, tc := range tests {
		// using t.Run() to use subtest
		t.Run(name, func(t *testing.T) {
			// subtest setup and teardown
			teardownSubTest := setupSubTest(t)
			teardownSubTest(t)
			got := Split(tc.input, tc.sep)
			if !reflect.DeepEqual(got, tc.want) {
				t.Errorf("excepted:%#v, got:%#v", tc.want, got)
			}
		})
	}
}

/**
* benchmark test
 */
func BenchmarkSplit(b *testing.B) {
	time.Sleep(3 * time.Second)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		Split("枯藤老树昏鸦", "老")
	}
}

func benchmarkFib(b *testing.B, n int) {
	//for i := 0; i < b.N; i++ {
	//	Fib(n)
	//}
	b.SetParallelism(1)
	b.RunParallel(func(pb *testing.PB) {
		for pb.Next() {
			Fib(n)
		}
	})
}

func BenchmarkFib1(b *testing.B)  { benchmarkFib(b, 1) }
func BenchmarkFib2(b *testing.B)  { benchmarkFib(b, 2) }
func BenchmarkFib3(b *testing.B)  { benchmarkFib(b, 3) }
func BenchmarkFib10(b *testing.B) { benchmarkFib(b, 10) }
func BenchmarkFib20(b *testing.B) { benchmarkFib(b, 20) }
func BenchmarkFib40(b *testing.B) { benchmarkFib(b, 40) }

/**
* setup and teardown (TestMain)
 */
func setupTestCase(t *testing.T) func(t *testing.T) {
	t.Log("test setup")
	return func(t *testing.T) {
		t.Log("test teardown")
	}
}

func setupSubTest(t *testing.T) func(t *testing.T) {
	t.Log("subtest setup")
	return func(t *testing.T) {
		t.Log("subtest teardown")
	}
}

func TestMain(m *testing.M) {
	// setup
	fmt.Println("write setup code here...")
	retCode := m.Run()
	// teardown
	fmt.Println("write teardown code here...")
	os.Exit(retCode)
}

/**
* example test
 */
func ExampleSplit() {
	fmt.Println(Split("a:b:c", ":"))
	fmt.Println(Split("枯藤老树昏鸦", "老"))
	// Output:
	// [a b c]
	// [ 枯藤 树昏鸦]
}
