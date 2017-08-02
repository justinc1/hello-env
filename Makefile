
GCC=gcc -ggdb
GCCSO=gcc -fPIC -shared -ggdb
MPICC=mpicc -ggdb
MPICCSO=mpicc -fPIC -shared -ggdb

EXEC=hello_env hello_env.so

all: $(EXEC)

clean:
	/bin/rm -f $(EXEC)

hello_env: hello_env.c
	$(GCC) -o $@ $<

hello_env.so: hello_env.c
	$(GCCSO) -o $@ $<

