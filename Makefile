# Sanele Mpangalala
#28 Feb 2016

driver.run: driver.o database.o
	g++ -o driver.run driver.o database.o
driver.o: driver.cpp database.h
	g++ -c -o driver.o driver.cpp
database.o: database.cpp database.h
	g++ -c -o database.o database.cpp
clean:
	rm -f *.o
	rm -f driver.run
