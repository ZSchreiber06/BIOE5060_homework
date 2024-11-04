collatz:
	gcc collatz.c -o collatz
collatz.txt: collatz
	./collatz > collatz.txt
test: collatz.c
	diff collatz.c collatz_expected.txt > diff.txt
	[ -s diff.txt ] && false || true
