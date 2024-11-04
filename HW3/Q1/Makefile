for:
	gcc forloop.c -o forloop -g -Wall -pedantic
while:
	gcc whileloop.c -o whileloop -g -Wall -pedantic
for.txt: for
 	./forloop > for.txt
while.txt: while
	./whileloop > while.txt
test: for.txt while.txt
	diff for.txt while.txt > diff.txt
	[ -s diff.txt ] && false || true