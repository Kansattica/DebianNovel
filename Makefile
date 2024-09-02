.PHONY: all clean

all: novel.txt

clean:
	rm -f mknovel novel.txt

novel.txt: mknovel
	./mknovel > novel.txt

mknovel: debnovel.cpp Makefile
	g++ debnovel.cpp -O3 -o mknovel
