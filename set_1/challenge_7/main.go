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
	SizeData := len(data)

	base64DecodedData := make([]byte, SizeData)
	_, err = base64.StdEncoding.Decode(base64DecodedData, data)
	checkErr("base64 decode", err)

	Key := []byte("YELLOW SUBMARINE")
	block, err := aes.NewCipher(Key)
	checkErr("create new cipher", err)

	outputData := make([]byte, SizeData)
	for i := 0; i < SizeData-1024; i += 16 {
		block.Decrypt(outputData[i:], base64DecodedData[i:])
	}

	fmt.Println(string(outputData))
}

func checkErr(s string, e error) {
	if e != nil {
		fmt.Printf("Error %s: %s\n", s, e.Error())
	}
}
