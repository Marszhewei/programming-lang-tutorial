module learn

go 1.19

require (
	learn/demo v0.0.1
	learn/function v0.0.1
	learn/med v0.0.1
)

require (
	github.com/cweill/gotests v1.6.0 // indirect
	golang.org/x/mod v0.7.0 // indirect
	golang.org/x/sys v0.2.0 // indirect
	golang.org/x/tools v0.3.0 // indirect
)

replace (
	learn/demo => ./demo
	learn/function => ./function
	learn/med => ./med
)
