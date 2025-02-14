SRC = ${DIRSRC}ft_atoi.c \
	  ${DIRSRC}ft_atoui_base.c \
	  ${DIRSRC}ft_bzero.c \
	  ${DIRSRC}ft_calloc.c \
	  ${DIRSRC}ft_isalnum.c \
	  ${DIRSRC}ft_isalpha.c \
	  ${DIRSRC}ft_isascii.c \
	  ${DIRSRC}ft_isdigit.c \
	  ${DIRSRC}ft_is_digitbase.c \
	  ${DIRSRC}ft_isprint.c \
	  ${DIRSRC}ft_memchr.c \
	  ${DIRSRC}ft_memcmp.c \
	  ${DIRSRC}ft_memcpy.c \
	  ${DIRSRC}ft_memmove.c \
	  ${DIRSRC}ft_memset.c \
	  ${DIRSRC}ft_strchr.c \
	  ${DIRSRC}ft_strrchr.c \
	  ${DIRSRC}ft_strdup.c \
	  ${DIRSRC}ft_strlcat.c \
	  ${DIRSRC}ft_strlcpy.c \
	  ${DIRSRC}ft_strlen.c \
	  ${DIRSRC}ft_strncmp.c \
	  ${DIRSRC}ft_strnstr.c \
	  ${DIRSRC}ft_substr.c \
	  ${DIRSRC}ft_tolower.c \
	  ${DIRSRC}ft_toupper.c \
	  ${DIRSRC}ft_str_toupper.c \
	  ${DIRSRC}ft_substr.c \
	  ${DIRSRC}ft_strjoin.c \
	  ${DIRSRC}ft_strtrim.c \
	  ${DIRSRC}ft_split.c \
	  ${DIRSRC}ft_itoa.c \
	  ${DIRSRC}ft_strmapi.c \
	  ${DIRSRC}ft_putchar_fd.c \
	  ${DIRSRC}ft_putstr_fd.c \
	  ${DIRSRC}ft_putendl_fd.c \
	  ${DIRSRC}ft_putnbr_fd.c \
	  ${DIRSRC}ft_striteri.c \
	  ${DIRSRC}get_next_line.c \
	  ${DIRSRC}get_next_line_utils.c \
	  ${DIRSRC}pos_in_str.c

B_SRC = ${DIRSRC}ft_lstnew_bonus.c \
		${DIRSRC}ft_lstaddfront_bonus.c \
		${DIRSRC}ft_lstsize_bonus.c \
		${DIRSRC}ft_lstlast_bonus.c \
		${DIRSRC}ft_lstaddback_bonus.c \
		${DIRSRC}ft_lstdelone_bonus.c \
		${DIRSRC}ft_lstclear_bonus.c \
		${DIRSRC}ft_lstiter_bonus.c \
		${DIRSRC}ft_lstmap_bonus.c

HEADER_FILE = libft.h
OBJS = ${SRC:.c=.o}
B_OBJS = ${B_SRC:.c=.o}
DIRSRC = ./
DIRINC = ./

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)

DEPS = ${SRC:.c=.d} ${B_SRC:.c=.d}

all: ${NAME}

-include $(DEPS)
%.o: %.c
	${CC} ${CFLAGS} -MMD -MP -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:
	$(MAKE) ${NAME} SRC="${SRC} ${B_SRC}"

clean:
	rm -f ${OBJS} ${B_OBJS} ${DEPS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus 
