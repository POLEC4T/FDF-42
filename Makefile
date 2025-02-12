SRCDIR=src
INCDIR=include
OBJDIR=.obj

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR) -I/usr/include -Imlx_linux -O3

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/hooks.c \
		$(SRCDIR)/map_parsing.c \
		$(SRCDIR)/frees.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/inits.c


OBJS = ${SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o}

NAME=fdf

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(MAKE) -C libft
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ./libft/libft.a -o $(NAME) -g

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJDIR)

fclean: 
	$(MAKE) -C libft fclean
	rm -rf $(OBJDIR) $(NAME)

re : fclean all

.PHONY : all clean fclean re