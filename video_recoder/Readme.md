Assume opencv environment is already established. 
The code has be tested under ubuntu14.04 and opencv3.3.0
The packages needed to compile the code is included in makefile.

first clean the previous compilations by:
```
$ make clean
```
then compile it again by:
```
$ make record_video
```
and it should generate something can be executed by:
```
$ ./recorde_video
```
The first camera device will be called to capture video stream and display it at the same time.
You can terminate it by pressing ESC.
The original video and downsampled video is saved in full_Record.avi and Record.avi automatically.

