# compiler and linker variable
INCLUDES = -I/usr/local/include

LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

all: canny  laplacian sobel


canny: canny.o 
	g++ -O3 -o canny canny.o ${LIBS}

canny.o: canny.cpp
	g++ -O3 -c canny.cpp


laplacian: laplacian.o 
	g++ -O3 -o canny canny.o ${LIBS}

laplacian.o: laplacian.cpp
	g++ -O3 -c laplacian.cpp


sobel: sobel.o 
	g++ -O3 -o sobel sobel.o ${LIBS}

sobel.o: sobel.cpp
	g++ -O3 -c sobel.cpp




clean:
	rm canny canny.o laplacian.o laplacian sobel.o sobel

