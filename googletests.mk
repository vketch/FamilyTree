# clone googletest and build googletest library  
GTEST_DIR = ./googletest/googletest
GTEST_LIB_NAME = gtest_main.a
GTEST_LIB = $(GTEST_DIR)/make/$(GTEST_LIB_NAME) 

.PHONY: gtests 

gtests: $(GTEST_DIR) $(GTEST_LIB)  

$(GTEST_DIR):
	@echo --------------Clone Google Tests---------------  
	git clone https://github.com/google/googletest.git

$(GTEST_LIB):
	@echo -------------Build Google Tests Library-----------------
	cd $(GTEST_DIR)/make && make gtest_main.a

		
	