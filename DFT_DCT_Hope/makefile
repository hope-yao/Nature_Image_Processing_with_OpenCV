# compiler and linker variable
INCLUDES = -I/usr/local/include

LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

all: DFT DCT 


DFT: DFT.o 
	g++ -O3 -o DFT DFT.o ${LIBS}

DFT.o: DFT.cpp
	g++ -O3 -c DFT.cpp

DCT: DCT.o 
	g++ -O3 -o DCT DCT.o ${LIBS}

DCT.o: DCT.cpp
	g++ -O3 -c DCT.cpp




clean:
	rm DFT.o DFT DCT.o DCT

