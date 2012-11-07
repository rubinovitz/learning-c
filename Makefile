objects = linkedlist.o whattime.o getlines.o timecalc.o 
executables = assign3 whattime getlines timecalc mygui
edit : $(objects)
		cc -o whattime whattime.o
			cc -o linkedlist linkedlist.o
				cc -o getlines getlines.o
					cc -o timecalc timecalc.o
						cc `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`-o mygui mygui.c

linkedlist.o : linkedlist.c 
whattime.o : whattime.c
getlines.o : getlines.c
timecalc.o : timecalc.c


.PHONY : clean
clean :
	-rm  $(objects)
	-rm $(executables)
	-rm  -f *.txt


