##
# passgen
# password generator
#
# @file
# @version 0.1

passgen: src/main.c
	mkdir -p bin
	gcc -o bin/passgen src/main.c

clean:
	rm -rf bin/

# end
