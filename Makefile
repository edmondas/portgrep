SRC=portgrep.c
TRG=portgrep

CFLAGS=-Wall -pedantic -O2

all:
	${CC} ${CFLAGS} -o ${TRG} ${SRC}

install: all
	cp ${TRG} /usr/local/bin	
	
clean:
	rm -f ${TRG} ${TRG}.core 
