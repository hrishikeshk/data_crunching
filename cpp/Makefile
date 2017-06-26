include OptMake

.PHONY: clean current k_means unit_tests

DIRS=current unit_tests

all: $(DIRS)

current: Common_Funcs.cpp Common_Funcs.h Consts.h TypeDefs.h
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(FPIC_OBJ) -o cf.o -c Common_Funcs.cpp

unit_tests: 
	cd unit_tests; $(MAKE) unit_tests

clean:
	rm -f *.o; \
	cd libs; \
	rm -f *.so; \
	cd $(SRC_DIR)/k_means; \
	$(MAKE) clean
	cd $(SRC_DIR)/unit_tests; \
	$(MAKE) clean

