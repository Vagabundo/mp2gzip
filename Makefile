# Fichero makefile para la construccion del ejecutable compresor de la practica mp2gzip

all: bin/mp2gzip

# ************ Compilación de módulos ************

obj/vdchar.o: src/vdchar.cpp include/vdchar.h
	@echo creando objeto vdchar.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/vdchar.cpp -o obj/vdchar.o

obj/vduint.o: src/vduint.cpp include/vduint.h
	@echo creando objeto vduint.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/vduint.cpp -o obj/vduint.o

obj/vbits.o: src/vdchar.cpp src/vbits.cpp include/vbits.h
	@echo creando objeto vbits.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/vbits.cpp -o obj/vbits.o

obj/LZ77.o: src/LZ77.cpp include/LZ77.h lib/libvd.a
	@echo creando objeto LZ77.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/LZ77.cpp -o obj/LZ77.o -Llib -lvd

obj/tabla.o: src/tabla.cpp include/tabla.h lib/libvd.a
	@echo creando el objeto tabla.o
	@g++ -c -g -Wall -O3 -Iinclude src/tabla.cpp -o obj/tabla.o -Llib -lvd

obj/crc32.o : src/crc32.cpp include/crc32.h lib/libvd.a
	@echo creando objeto crc32.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/crc32.cpp -o obj/crc32.o -Llib -lvd

obj/deflate.o: src/deflate.cpp include/deflate.h obj/LZ77.o obj/tabla.o
	@echo creando objeto deflate.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/deflate.cpp -o obj/deflate.o

obj/compresor.o: src/compresor.cpp obj/crc32.o obj/deflate.o
	@echo creando objeto compresor.o ......
	@g++ -c -g -Wall -O3 -Iinclude src/compresor.cpp -o obj/compresor.o

# ************ Creación de librerias ************

lib/libvd.a: obj/vbits.o obj/vdchar.o obj/vduint.o
	@echo creando libreria libvd.a ......
	@ar rsv lib/libvd.a obj/vbits.o obj/vdchar.o obj/vduint.o

# ************ Enlazado y creación de ejecutables ************

bin/mp2gzip: obj/compresor.o
	@echo creando ejecutable mp2gzip ......
	@g++ obj/compresor.o obj/deflate.o obj/LZ77.o obj/tabla.o obj/crc32.o -o bin/mp2gzip  -Llib -lvd

# ************* Limpieza de objetos ***************

clean:
	@echo borrando objetos, librerias y backups
	@\rm -rf obj/*.o lib/*.a src/*~ include/*~

mrproper: clean
	@echo borrando ejecutables y backup de Makefile
	@\rm -rf bin/* *~
