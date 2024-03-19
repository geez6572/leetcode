
CC := g++
CFLAGS := -Wall -Wextra -std=c11

SRCS := $(wildcard *.cpp)
BINS := $(patsubst %.cpp,%,$(SRCS))




.PHONY: all clean

all: $(BINS)

%:%.cpp
	@$(CC)  -o $@ -g $<
	@./$@


# 清理生成的可执行文件
clean:
	rm -f $(BINS)
