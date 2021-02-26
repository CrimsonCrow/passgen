##
# passgen
# password generator
#
# @file
# @version 0.1

passgen: src/main.c
	mkdir -p bin
	gcc -O2 -o bin/passgen src/main.c

debug: src/main.c
	mkdir -p bin
	gcc -g -o bin/passgen src/main.c

clean:
	rm -rf bin/

# end
