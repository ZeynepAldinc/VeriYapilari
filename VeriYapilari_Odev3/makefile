hepsi: derle calistir

derle:
	g++ -I ./include/ -c ./src/Dugum1.cpp -o ./lib/Dugum1.o
	g++ -I ./include/ -c ./src/Dugum2.cpp -o ./lib/Dugum2.o
	g++ -I ./include/ -c ./src/Agac1.cpp -o ./lib/Agac1.o
	g++ -I ./include/ -c ./src/Agac2.cpp -o ./lib/Agac2.o
	g++ -I ./include/ -c ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -I ./include/ ./lib/Dugum1.o ./lib/Dugum2.o ./lib/Agac1.o ./lib/Agac2.o ./lib/Kontrol.o ./src/Test.cpp -o ./bin/Program

calistir:
	./bin/Program