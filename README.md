mp2gzip
=======

This is a program to compress files using the Deflate algorithm according to the standard Lempel-Ziv (LZ77). 


To create the file must be placed in this folder using the command prompt and 
then type: 

$ make 



Once done, the executable is created in the bin folder. 


To run the program you must type: 

$ ./bin/mp2gzip <file_to_compress> [Output_file] 



If the output file is not written, by default it creates a file with the same name of the file to be compressed, 
with gz extension. 


To create a documentation file (although I already attached one), 
I typed the following: 

$ Cd doc 
$ doxygen 
$ Cd latex 
$ make 



With these commands one refman.pdf file, which contains detailed information of the project will be created. 



NOTE: I made an improved coding, but it only work with prueba1.txt, 
what I have not included, but I leave the function in the. cpp
