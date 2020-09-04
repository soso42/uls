NAME = libmx.a
LIBMX = libmx

SRCD = src
INCD = inc
OBJD = obj
INC = libmx.h

SRC =         src/mx_printchar.c \
              src/mx_print_unicode.c \
              src/mx_printstr.c \
              src/mx_isspace.c \
              src/mx_isdigit.c \
              src/mx_isalpha.c \
              src/mx_print_strarr.c \
              src/mx_printint.c \
              src/mx_pow.c \
              src/mx_sqrt.c \
              src/mx_nbr_to_hex.c \
              src/mx_hex_to_nbr.c \
              src/mx_itoa.c \
              src/mx_foreach.c \
              src/mx_binary_search.c \
              src/mx_bubble_sort.c \
              src/mx_swap_arr_elements.c \
              src/mx_strtrim.c \
              src/mx_atoi.c \
              src/mx_quicksort.c \
              src/mx_printerror.c \
              src/mx_strlen.c \
              src/mx_swap_char.c \
              src/mx_str_reverse.c \
              src/mx_strdel.c \
              src/mx_get_char_index.c \
              src/mx_strcpy.c \
              src/mx_strncpy.c \
              src/mx_strcmp.c \
              src/mx_strncmp.c \
              src/mx_strnew.c \
              src/mx_strdup.c \
              src/mx_strndup.c \
              src/mx_strcat.c \
              src/mx_strstr.c \
              src/mx_strchr.c \
              src/mx_get_substr_index.c \
              src/mx_count_substr.c \
              src/mx_count_words.c \
              src/mx_del_strarr.c \
              src/mx_strsplit.c \
              src/mx_strjoin.c \
              src/mx_del_extra_spaces.c \
              src/mx_file_to_str.c \
              src/mx_read_line.c \
              src/mx_replace_substr.c \
              src/mx_strsub.c \
              src/mx_memset.c \
              src/mx_memcpy.c \
              src/mx_memccpy.c \
              src/mx_memcmp.c \
              src/mx_memchr.c \
              src/mx_memrchr.c \
              src/mx_memmem.c \
              src/mx_memmove.c \
              src/mx_realloc.c \
              src/mx_create_node.c \
              src/mx_push_front.c \
              src/mx_push_back.c \
              src/mx_pop_front.c \
              src/mx_pop_back.c \
              src/mx_list_size.c \


INCLUDE = -I $(INCD) \

INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
AR = ar rcs
CC = clang

all: $(NAME)

install: $(NAME) clean

$(LIBMX): $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@printf "\x1b[32;1m$@ created\x1b[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@printf "\x1b[32mcompiled[libmx]: \x1b[0m[$(<:$(SRCD)/%.c=%.c)]\n"

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@
	@printf "\x1b[34;1mdeleted libmx/$(NAME)\x1b[0m\n"

uninstall: clean
	@rm -rf $(NAME)
	@printf "\x1b[34;1mdeleted libmx/$(OBJD)\x1b[0m\n"

clean:
	@rm -rf $(OBJD)


reinstall: uninstall install
