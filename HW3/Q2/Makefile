fizzbuzz:
	gcc fizzbuzz.c -E fizzbuzz - g -Wall -pedantic
fizzbuzz.txt: fizzbuzz
	./fizzbuzz > fizzbuzz.txt
test: fizzbuzz.txt
	diff fizzbuzz.txt fuzzbuzz_expected.txt > diff.txt
	[ -s diff.txt ] && false || true