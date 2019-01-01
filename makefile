
all:
	gcc serverTopMusic.c -o svTopMusic -lssl -lcrypto `mysql_config --cflags --libs`
	gcc clientTopMusic.c -o clTopMusic
clean:
	rm -f *~clTopMusic svTopMusic
