GCC = gcc
MODULE_LIBRARY = testCode128
MODULE_OBJS = $(patsubst %.c,%.o,$(wildcard src/*.c))
LIBS_DIR = ./

MODULE_INCLUDE = -I./include
######################################################
# Module flags

LDFLAGS += -lgd
LIB_FLAGS += 
######################################################
# Common dependency process

.PHONY:all clean

%.o: %.c
	$(GCC) $(LDFLAGS) $(PUBLIC_FLAGS) $(MODULE_INCLUDE) -c $< -o $@

all : $(MODULE_OBJS)
	$(GCC) $(MODULE_OBJS) $(PUBLIC_FLAGS) $(LDFLAGS) $(LIB_FLAGS) -o $(LIBS_DIR)/$(MODULE_LIBRARY)

clean:
	rm -f $(LIBS_DIR)/$(MODULE_LIBRARY)
	rm -f $(MODULE_OBJS)
