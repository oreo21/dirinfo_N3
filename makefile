compile: dirInfo.c
	gcc dirInfo.c -o dirInfo

clean:
	rm *~ *# dirInfo

run: dirInfo
	./dirInfo

