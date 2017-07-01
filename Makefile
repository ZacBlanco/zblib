
TEST_DIR=test
SRC_DIR=src
TEST_BIN=test.out

.PHONY: test
test:
	python3 ./test/test.py

clean:
	rm ./test/a.out