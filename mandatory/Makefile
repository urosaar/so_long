NAME = so_long
B_NAME = ../bonus/so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c \
      so_long_utils.c \
      libft/get_next_line/get_next_line.c \
      libft/get_next_line/get_next_line_utils.c \
      libft/ft_printf/ft_printf.c \
      libft/ft_printf/ft_printf_utils.c \
      pmoves.c \
      rmap.c \
      moves/if_won.c \
      moves/moves.c \
      parssing/map_parsing.c \
      parssing/map_validation.c \

OBJ = $(SRC:.c=.o)

B_SRC = ../bonus/so_long_bonus.c \
        ../bonus/so_long_utils_bonus.c \
        ../bonus/libft/get_next_line/get_next_line.c \
        ../bonus/libft/get_next_line/get_next_line_utils.c \
        ../bonus/libft/ft_printf/ft_printf.c \
        ../bonus/libft/ft_printf/ft_printf_utils.c \
        ../bonus/pmoves_bonus.c \
        ../bonus/rmap_bonus.c \
        ../bonus/moves/if_wl_bonus.c \
        ../bonus/moves/moves_bonus.c \
        ../bonus/parssing/map_parsing_bonus.c \
        ../bonus/parssing/map_validation_bonus.c \
        ../bonus/utils_bonus.c

B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) so_long.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ) ../bonus/so_long_bonus.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(B_NAME) $(B_OBJ)

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@rm -f $(NAME) $(B_NAME)

re: fclean all

