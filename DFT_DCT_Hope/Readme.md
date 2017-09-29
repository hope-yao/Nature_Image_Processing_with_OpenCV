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
```
$ ./DFT 
```
or:
```
$ ./DFT 
```
Considering the trade off between compressing ratio and image quality, the best truncation is around L=50.
