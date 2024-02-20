package main

import (
	"crypto/aes"
	"encoding/base64"
	"fmt"
	"os"
)

func main() {
	data, err := os.ReadFile("./base64.txt")
	checkErr("opening file", err)

	_, err = base64.StdEncoding.Decode(data, data)
	checkErr("base64 decode", err)

	block, err := aes.NewCipher([]byte("YELLOW SUBMARINE"))
	checkErr("create new cipher", err)

	SizeData := len(data)
	dst := make([]byte, SizeData)
	for i := 0; i < SizeData; i += block.BlockSize() {
		block.Decrypt(dst, data)
	}

	fmt.Printf("%s", dst)
}

func checkErr(s string, e error) {
	if e != nil {
		fmt.Printf("Error %s: %v\n", s, e.Error())
	}
}
