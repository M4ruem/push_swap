
NAME = push_swap

CHECK = checker

CC = clang

LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

CFLAGS = -Wall -Werror -Wextra -g

SRC = ./src/algo.c \
	./src/functions.c \
	./src/get.c \
	./src/average.c \
	./src/main.c \
	./src/push.c \
	./src/push2.c \
	./src/functions2.c \
	./src/rotate.c \
	./src/sort.c \
	./src/swap.c \
	./src/utils.c

SRC_BONUS = ./bonus/checker_bonus.c \
	./bonus/algo_bonus.c \
	./bonus/functions_bonus.c \
	./bonus/get_bonus.c \
	./bonus/average_bonus.c \
	./bonus/push_swap_bonus.c \
	./bonus/push_bonus.c \
	./bonus/push2_bonus.c \
	./bonus/functions2_bonus.c \
	./bonus/rotate_bonus.c \
	./bonus/sort_bonus.c \
	./bonus/swap_bonus.c \
	./bonus/utils_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(LIBFT_NAME) $(NAME)

bonus: $(LIBFT_NAME) $(CHECK)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	${CC}  $(OBJ) $(LIBFT_NAME) -o ${NAME}

$(CHECK): $(OBJ_BONUS)
	${CC} $(OBJ_BONUS) $(LIBFT_NAME) -o ${CHECK}

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C ./libft
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME) $(CHECK)

re: fclean all

.PHONY:
	re all clean fclean bonus
