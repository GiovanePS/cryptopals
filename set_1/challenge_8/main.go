package main

import (
	"bytes"
	"fmt"
	"os"
)

func main() {
	data, err := os.ReadFile("./input.txt")
	checkErr("reading file", err)
	fmt.Printf("%v\n\n\n", data)

	splitData := bytes.Split(data, []byte("\n"))

	fmt.Println(splitData)

}

func checkErr(s string, e error) {
	if e != nil {
		fmt.Printf("Error %s, %s\n", s, e.Error())
	}
}
