objects= ./lib/main.o ./lib/split.o ./lib/unicode2utf8.o
unicode2utf8: $(objects)	
	g++ $(objects) -o unicode2utf8;mv unicode2utf8 ./bin
$(objects): ./src/main.cpp ./src/split.cpp ./src/unicode2utf8.cpp ./include/split.h ./include/unicode2utf8.h ./include/varray.h 
	g++ -c ./src/main.cpp ./src/split.cpp ./src/unicode2utf8.cpp;mv ./*.o ./lib

clean:
	rm ./lib/*.o ./bin/*
