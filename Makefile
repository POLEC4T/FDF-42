SRCDIR=src
INCDIR=include
OBJDIR=.obj

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR) -I/usr/include -Imlx_linux -O3

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/hooks.c

OBJS = ${SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o}

NAME=fdf

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)