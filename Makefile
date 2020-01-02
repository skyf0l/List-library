## GCC
CC = gcc -fdiagnostics-color=always $(INCLUDES)
CFLAGS = -Wall -Wextra

## LIB

NAME = list
LIBNAME = lib$(NAME).a
SRC = $(shell find src/ -name *.c)
#$(eval SRC = $(addprefix src/, $(SRC)))
OBS = $(SRC:.c=.o)

HNAME = list.h
HNAME_PRIVATE = private_list.h
$(eval HNAME = $(addprefix include/, $(notdir $(HNAME))))
$(eval HNAME_PRIVATE = $(addprefix include/, $(notdir $(HNAME_PRIVATE))))

INCLUDES = -I./include -I./include/private

## TEST
TEST_NAME = unit_tests
SRC_TEST = $(shell find tests/ -name *.c)
#$(eval SRC_TEST = $(addprefix tests/, $(SRC_TEST)))

all: $(LIBNAME)

$(LIBNAME): $(OBS)
	@ar rc $(LIBNAME) $(OBS)

clean:
	@rm -f $(OBS) *.o
	@rm -f *.gcno *.gcda

fclean:
	@$(MAKE) -s clean
	@rm -f $(LIBNAME)
	@rm -f $(TEST_NAME)

re: fclean all

tests_run: fclean
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(TEST_NAME) $(SRC) $(SRC_TEST) --coverage -lcriterion
	@./$(TEST_NAME)

coverage: tests_run
	gcovr --exclude tests/

.PHONY: all clean fclean re tests_run coverage