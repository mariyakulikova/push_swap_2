NAME = push_swap
NAME_BONUS = checker
CC = cc
CCFLAGS = -Wextra -Wall -Werror
RM = rm -f
DEBUG = -g

HEADDIR = .
HEADERS = push_swap.h
HEADERS_BONUS = push_swap_bonus.h

SRCS =			main.c \
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
				cmd_push.c \
				cmd_rotate.c \
				cmd_rev_rotate.c
SRCS_BONUS = 	main_bonus.c \
				dlst_bonus.c \
				stack_bonus.c \
				stack2_bonus.c \
				tab_utils_bonus.c \
				tab_bonus.c \
				utils_bonus.c \
				sort_bonus.c \
				params_bonus.c \
				push_swap_bonus.c \
				cmd_swap_bonus.c \
				cmd_push_bonus.c \
				cmd_rotate_bonus.c \
				cmd_rev_rotate_bonus.c
OBJSDIR = ./objs/
OBJSDIR_BONUS = ./objs_bns/
OBJSLIST = $(SRCS:.c=.o)
OBJSLIST_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSLIST))
OBJS_BONUS = $(addprefix $(OBJSDIR_BONUS), $(OBJSLIST_BONUS))

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

LIBS = -L${LIBFTDIR} -lft
INCS = -I${HEADDIR} -I${LIBFTDIR}

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJSDIR_BONUS) $(OBJS_BONUS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBS) $(INCS)

$(NAME): $(LIBFT) $(OBJSDIR) $(OBJS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $@ $(LIBS) $(INCS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR_BONUS):
	mkdir -p $(OBJSDIR_BONUS)

$(OBJSDIR)%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

$(OBJSDIR_BONUS)%.o: %.c $(HEADERS_BONUS)
	$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJSDIR)
	$(RM) -r $(OBJSDIR_BONUS)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean bonus re
