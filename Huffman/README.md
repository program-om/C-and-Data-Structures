## How to run the program

	user@deviceUser:~/huffman$ make
	user@deviceUser:~/huffman$ ./coder samplecodefile.txt

## Example

	user@deviceUser:~/huffman$ more samplemessage.plaintext sunnyinus
	user@deviceUser:~/huffman$ ./coder samplecodefile.dat
	Please choose one of:

		E ­ Encode a message 
		D ­ Decode a message 
		Q ­ Quit the program

	Enter your choice: e 
	Enter the name of a plaintext message file: samplemessage.plaintext 
	Enter name of output file: samplemessage.encoded

	Please choose one of:

		E ­ Encode a message 
		D ­ Decode a message 
		Q ­ Quit the program

	Enter your choice: d 
	Enter the name of a compressed message file: samplemessage.encoded 
	Enter name of output file: samplemessage.recovered

	Please choose one of:

		E ­ Encode a message 
		D ­ Decode a message 
		Q ­ Quit the program

	Enter your choice: q 
	user@deviceUser:~/huffman$ more samplemessage.encoded 
	000101010011111001000 
	user@deviceUser:~/huffman$ more samplemessage.recovered 
	sunnyinus 
	user@deviceUser:~/huffman$
