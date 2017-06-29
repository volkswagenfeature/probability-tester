CC := g++
header-files := $(addprefix ./lib/, prob-node.h fail-funcs.h)
extra-flags := 
outfile-name := PROBABILITY-TESTER
outfile-ext := out


$(outfile-name).$(outfile-ext) : main.cpp $(header-files)
	g++ $(extra-flags) -o $(outfile-name).$(outfile-ext) main.cpp $(header-files)	

debug : debug.cpp $(header-files)
	g++ -o $(outfile-name)_DEBUG.$(outfile-ext) debug.cpp $(header-files)

clean :
	rm $(outfile-name)*.$(outfile-ext)
	rm *.o
