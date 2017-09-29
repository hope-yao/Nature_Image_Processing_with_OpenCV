Assume opencv environment is already established. 
The code has be tested under ubuntu14.04 and opencv3.3.0
The packages needed to compile the code is included in makefile.

first clean the previous compilations by:
```
$ make clean
```
then compile both DFT and DCT again by:
```
$ make 
```
and it should generate something can be executed by:
or:
```
$ ./laplacian
```
```
$ ./sobel
```
or:
```
$ ./canny 
```
