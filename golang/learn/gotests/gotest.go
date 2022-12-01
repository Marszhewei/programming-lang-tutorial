package gotests

import (
	"errors"
)

func Division(a, b float64) (float64, error) {
	if b == 0 {
		return 0, errors.New("division can't be 0")
	}

	return a / b, nil
}
