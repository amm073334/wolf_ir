CC = cl
ARGS = /EHsc

gen: main commonevent commonfile
	$(CC) $(ARGS) main.obj commonevent.obj commonfile.obj

main: main.cpp
	$(CC) $(ARGS) /c main.cpp

commonevent: commonevent.cpp
	$(CC) $(ARGS) /c commonevent.cpp

commonfile: commonfile.cpp
	$(CC) $(ARGS) /c commonfile.cpp

clean:
	del *.obj
	del *.common
	del *.exe