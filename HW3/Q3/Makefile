collatz:
	gcc collatz.c -o collatz
collatz.txt: collatz
	./collatz 7 > collatz.txt
test: collatz.txt
	diff collatz.txt collatz_expected.txt > diff.txt
	[ -s diff.txt ] && false || true