include $(SRC_DIR)/OptMake

.PHONY: unit_tests clean

TST_INCLUDES=-I $(SRC_DIR)/unit_tests

simple_tests.o: simple_tests.cpp ../Common_Funcs.cpp ../Common_Funcs.h
	$(CC) $(OPTIONS)  $(WARN) $(DEBUG) $(FPIC_OBJ) $(INCLUDES) $(TST_INCLUDES) -o simple_tests.o -c simple_tests.cpp

unit_tests: simple_tests.o ../cf.o
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) -L $(SRC_DIR)/libs -o $(SRC_DIR)/libs/simple_tests simple_tests.o ../cf.o

clean:
	rm -rf *.o; rm -rf $(SRC_DIR)/libs/simple_tests

