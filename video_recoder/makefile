# compiler and linker variable
INCLUDES = -I/usr/local/include

LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs


record_video: record_video.o 
	g++ -O3 -o record_video record_video.o ${LIBS}

record_video.o: record_video.cpp
	g++ -O3 -c record_video.cpp

clean:
	rm record_video.o record_video

