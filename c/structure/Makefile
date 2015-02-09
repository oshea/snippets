CFLAGS= -Wall $(OPTFLAGS)

CC=gcc

MAIN=src/main.c
TARGET=build/main

SOURCES=$(filter-out $(MAIN), $(wildcard src/**/*.c src/*.c))
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all: build objects $(TARGET)

objects: $(OBJECTS)

$(TARGET):
	$(CC) $(CFLAGS) $(MAIN) $(OBJECTS) -o $(TARGET)

build:
	@mkdir -p build

clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
