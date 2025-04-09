NAME = minirt
VALGRIND = memorytester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-O2
CFLAGS += -fno-omit-frame-pointer
SANITIZE_FLAGS = -fsanitize=address -fsanitize=undefined #-fno-sanitize-recover=all
DUNITY_FLAGS = -DUNITY_INCLUDE_DOUBLE -DUNITY_DOUBLE_PRECISION=1e-12

MLX_PATH = ./LIB/minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = ./LIB/LIBFT/
LIBFT_NAME = libft
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

MUK_LIB_PATH = ./LIB/muk_lib/
MUK_LIB_NAME = muk_lib
MUK_LIB = $(MUK_LIB_PATH)$(MUK_LIB_NAME)

INCLUDES =	-I/usr/include \
			-I$(MLX_PATH) \
			-I$(LIBFT_PATH) \
			-I$(MUK_LIB_PATH) \
			-I./INC

SRC_MAIN =	./SRC/mini_ray.c

SRC_PATH = ./
SRC = \
	SRC/BASE/MATHS/discriminant.c \
	SRC/BASE/MATHS/epsilon.c \
	SRC/BASE/MATHS/matrix_determinants.c \
	SRC/BASE/MATHS/matrix_inverse.c \
	SRC/BASE/MATHS/matrix_operations.c \
	SRC/BASE/MATHS/tuple_operations.c \
	SRC/BASE/COLOURS/colour.c \
	SRC/BASE/RAYS/rays.c \
	SRC/BASE/OBJECTS/object_manip.c \
	SRC/BASE/MATHS/normal_vectors.c \
	SRC/LIGHTING/lighting.c \
	SRC/BASE/RAYS/ray_world_intersect.c \
	SRC/BASE/RAYS/prepare_computations.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./OBJ/
OBJS = $(SRC:.c=.o)
OBJECTS = $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)
	@./$(NAME) MAP/minimalist.rt

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@make -sC $(MLX_PATH) -w

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(MUK_LIB):
	@make -C $(MUK_LIB_PATH) all

$(NAME): $(OBJECTS) $(MLX) $(LIBFT) $(MUK_LIB) $(SRC_MAIN)
	@$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(INCLUDES) -o $(NAME) $(SRC_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX_FLAGS) -lm

$(VALGRIND): $(SRC_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(VALGRIND) $(SRC_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX_FLAGS) -lm

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MUK_LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VALGRIND)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MUK_LIB_PATH)

re: fclean all

valgrind: $(VALGRIND)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(VALGRIND) MAP/data.rt

.PHONY: all clean fclean re test memory aaaa

