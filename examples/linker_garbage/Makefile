.PHONY := clean

CFLAGS := 
LDFLAGS :=

CFLAGS_DATA := -fdata-sections -ffunction-sections
LDFLAGS_DATA := -Wl,-gc-sections

CFLAGS_LTO := -flto
LDFLAGS_LTO := -flto

all: main main_data main_lto

main: main.o function.o

main_data: main_data.o function_data.o
	$(CC) $(LDFLAGS_DATA) -o $@ $^

main_lto: main_lto.o function_lto.o
	$(CC) $(LDFLAGS_DATA) -o $@ $^

main_data.o: main.c
	$(CC) $(CFLAGS_DATA) -c -o $@ $^

function_data.o: function.c
	$(CC) $(CFLAGS_DATA) -c -o $@ $^

main_lto.o: main.c
	$(CC) $(CFLAGS_LTO) -c -o $@ $^

function_lto.o: function.c
	$(CC) $(CFLAGS_LTO) -c -o $@ $^

clean:
	@rm main main_data *.o > /dev/null 2>&1
