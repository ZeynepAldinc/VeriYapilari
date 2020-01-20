hepsi: derle calistir

derle: 
	g++ -I ./include/ -c ./src/Top.cpp -o ./lib/Top.o
	g++ -I ./include/ -c ./src/Kova.cpp -o ./lib/Kova.o
	g++ -I ./include/ -c ./src/KovaKontrol.cpp -o ./lib/KovaKontrol.o
	g++ -I ./include/ ./lib/Top.o ./lib/Kova.o ./lib/KovaKontrol.o ./src/Test.cpp -o ./bin/Program
calistir:
	./bin/Program