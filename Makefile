NAME = push_swap
CC = cc
CCFLAGS = -Wextra -Wall -Werror
RM = rm -f
DEBUG = -g

HEADDIR = .
HEADERS = push_swap.h

SRCS =	main.c \
		dlst.c \
		stack.c \
		stack2.c \
		tab_utils.c \
		tab.c \
		utils.c \
		sort.c \
		params.c \
		push_swap.c \
		cmd_swap.c \
		cmd_put.c \
		cmd_rotate.c \
		cmd_rev_rotate.c \
		test.c \

OBJSDIR = ./objs/
OBJSLIST = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSLIST))

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

LIBS = -L${LIBFTDIR} -lft
INCS = -I${HEADDIR} -I${LIBFTDIR}

all: $(NAME)

bonus: $(LIBFT) $(OBJSDIR) $(OBJS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $(NAME) $(LIBS) $(INCS)

$(NAME): $(LIBFT) $(OBJSDIR) $(OBJS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $@ $(LIBS) $(INCS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean bonus re

