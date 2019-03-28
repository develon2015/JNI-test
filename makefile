#makefile

.PHONY: target
target: bin/libdev.so
	# -d 指定类生成路径 -h 指定头文件生成路径
	javac -sourcepath src/java src/java/dev/Main.java -classpath bin -d bin -h src/c/inc

bin/libdev.so: src/c/jni/*.c
	gcc -shared -fPIC src/c/jni/*.c -I src/c/inc -I /jdk/include -I /jdk/include/linux -o bin/libdev.so

.PHONY: run
run:
	LD_LIBRARY_PATH=./bin java -classpath bin dev.Main

.PHONY: clean
clean:
	rm -rf bin/*

