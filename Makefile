## GCC
CC = gcc -fdiagnostics-color=always $(INCLUDES)
CFLAGS = -Wall -Wextra

## LIB

NAME = list
LIBNAME = lib$(NAME).a
SRC = list_remove.c \
	list_clone.c \
	list_get.c \
	list_contain.c \
	list_index_of.c \
	list_set.c \
	list_count.c \
	list_sub_list.c \
	list_add.c \
	list_remove_range.c \
	list.c \
	list_stat.c \
	list_destructor.c \
	list_reverse.c \
	list_to_array.c
$(eval SRC = $(addprefix src/, $(SRC)))
OBS = $(SRC:.c=.o)

HNAME = list.h
$(eval HNAME = $(addprefix include/, $(notdir $(HNAME))))

INCLUDES = -I./include -I./include/private

## TEST
TEST_NAME = unit_tests
SRC_TEST = tests_list_set.c \
	tests_list_contain.c \
	tests_list_sub_list.c \
	tests_list_to_array.c \
	tests_list_remove.c \
	tests_list_stat.c \
	tests_list_clone.c \
	tests_list_remove_data.c \
	tests_list_index_of.c \
	tests_list_add.c \
	tests_list_reverse.c \
	tests_list_remove_range.c \
	tests_list_count.c \
	tests_list_get.c \
	tests_list.c \
	tests_list_destructor.c
$(eval SRC_TEST = $(addprefix tests/, $(SRC_TEST)))

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