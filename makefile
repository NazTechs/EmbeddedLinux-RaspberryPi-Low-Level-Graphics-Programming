CC = g++
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

TARGET = graphic
SRC = main.cpp RawGraphicClass.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)