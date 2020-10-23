visu: stat.pdf
	open -a Preview stat.pdf &

run: tri_bulle tri_fusion
	time ./tri_bulle 10000
	time ./tri_fusion 10000
	time ./tri_bulle 100000
	time ./tri_fusion  100000
	time ./tri_bulle   200000	
	time ./tri_fusion  200000

stat.pdf: tri_bulle stat.gplt test_tri_bulle
	gnuplot stat.gplt

debug: tri_bulle
	valgrind ./tri_bulle

test_tri_bulle: tri_bulle
	./tri_bulle

# Le tri à bulles
tri_bulle: tri_bulle.o tabint.o 
	gcc -g -Wall -o tri_bulle tri_bulle.o tabint.o 

tri_fusion: tri_fusion.o tabint.o 
	gcc -g -Wall -o tri_fusion tri_fusion.o tabint.o 


tri_bulle.o: tri_bulle.c tabint.h stat.h
	gcc -g -Wall -c tri_bulle.c

tri_fusion.o: tri_fusion.c tabint.h stat.h
	gcc -g -Wall -c tri_fusion.c



# La bibliothèque de manipulation de tableaux
tabint.o: tabint.c tabint.h
	gcc -g -Wall -c tabint.c

clean:
	rm -f tabint.o
	rm -f tri_bulle.o tri_bulle
	rm -f stat.pdf
	rm -f test_tri_bulle.data
	ls -l


ZIPNAME=IN301-303_TD_TRI_INT
zip:
	rm -rf ${ZIPNAME}
	mkdir ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp Makefile ${ZIPNAME}
	cp *.gplt ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
##	rm -rf ${ZIPNAME}
	ls -l ${ZIPNAME}*














