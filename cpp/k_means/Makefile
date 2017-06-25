include ../OptMake

.PHONY: clean k_means

k_means: k_medoid

k_medoid: K_Medoid.cpp
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(FPIC_OBJ) -o k_medoid.o -c K_Medoid.cpp

clean:
	rm -f *.o *.so *.a
