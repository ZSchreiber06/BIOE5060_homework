fizzbuzz:
	gcc fizzbuzz.c -o fizzbuzz
fizzbuzz.txt: fizzbuzz
	./fizzbuzz > fizzbuzz.txt
test: fizzbuzz.txt
	- diff fizzbuzz.txt fizzbuzz_expected.txt > diff.txt
	[ -s diff.txt ] && false || true
clean:
	rm -rf fizzbuzz.txt fizzbuzz fizzbuzz.o
