package main

import (
	"bytes"
	"fmt"
	"os"
	"reflect"
)

func main() {
	data, err := os.ReadFile("./input.txt")
	checkErr("reading file", err)

	output := findECBEncryptedLine(data)
	if output != -1 {
		fmt.Printf("O texto da linha %d está encriptado por ECB.\n", output+1)
	} else {
		fmt.Println("Número não encontrado.")
	}
}

func findECBEncryptedLine(data []byte) int {
	splitData := bytes.Split(data, []byte("\n"))
	sizeEachLineData := len(splitData[0])
	contador := 0
	bytesTested := make([]byte, sizeEachLineData)
	for lineNumber, lineValue := range splitData {
		for i := 0; i < sizeEachLineData; i += 16 {
			copy(bytesTested[i:i+16], lineValue[i:i+16])
			contador = 0
			for n := 0; n < sizeEachLineData; n += 16 {
				fmt.Println(string(bytesTested[n:n+16]), string(lineValue[n:n+16]))
				if reflect.DeepEqual(bytesTested[n:n+16], lineValue[n:n+16]) {
					contador += 1
				}
			}
			if contador >= 20 {
				return lineNumber
			}
		}

		bytesTested = make([]byte, sizeEachLineData)
	}

	return -1
}

func checkErr(s string, e error) {
	if e != nil {
		fmt.Printf("Error %s, %s\n", s, e.Error())
	}
}
