NAME = minirt
TESTER = luxtester
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
			-I./TESTS/INC \
			-I./INC

SRC_MAIN =	./SRC/mini_ray.c
TEST_MAIN =	\
	TESTS/LIB/Unity/src/unity.c \
	TESTS/SRC/BASE/COLOURS/colour.c  \
	TESTS/SRC/BASE/MATRICES/matrix_feature.c  \
	TESTS/SRC/BASE/MATRICES/matrix_transformations.c  \
	TESTS/SRC/BASE/RAYS/create_ray.c \
	TESTS/SRC/CORE/RENDER/canvas.c \
	TESTS/SRC/FEATURES/PPM/create_ppm.c \
	TESTS/SRC/FEATURES/PPM/tick_ppm.c \
	TESTS/SRC/OBJECTS/SPHERE/ray_sphere_intersections.c \
	TESTS/SRC/OBJECTS/SPHERE/ray_world_intersect.c \
	TESTS/SRC/OBJECTS/SPHERE/render_sphere.c \
	TESTS/SRC/OBJECTS/TRANSFORM/chaining_transformations.c \
	TESTS/SRC/PHYSICS/LIGHTS/light_shading.c \
	TESTS/SRC/test_main.c 


SRC_PATH = ./SRC/
SRC = \
	BASE/COLOURS/colour_to_int.c \
	BASE/COLOURS/colour_utils.c \
	BASE/COLOURS/colour.c \
	BASE/HELPERS/discriminant.c \
	BASE/HELPERS/epsilon.c \
	BASE/HELPERS/intersections_feature.c \
	BASE/HELPERS/prepare_computations.c \
	BASE/MATRICES/matrix_clone.c  \
	BASE/MATRICES/matrix_compare.c  \
	BASE/MATRICES/matrix_create.c  \
	BASE/MATRICES/matrix_determinants.c  \
	BASE/MATRICES/matrix_dot.c  \
	BASE/MATRICES/matrix_free.c  \
	BASE/MATRICES/matrix_identity.c  \
	BASE/MATRICES/matrix_inverse.c  \
	BASE/MATRICES/matrix_length.c  \
	BASE/MATRICES/matrix_multiple.c  \
	BASE/MATRICES/matrix_normalize.c  \
	BASE/MATRICES/matrix_point.c \
	BASE/MATRICES/matrix_scalar_mult.c \
	BASE/MATRICES/matrix_sum.c  \
	BASE/MATRICES/matrix_to_tuple.c \
	BASE/MATRICES/matrix_transpose.c \
	BASE/MATRICES/matrix_vector.c \
	BASE/RAYS/ray_clone.c  \
	BASE/RAYS/ray_create.c  \
	BASE/RAYS/ray_free.c  \
	BASE/RAYS/ray_intersect.c  \
	BASE/RAYS/ray_position.c  \
	BASE/RAYS/ray_transform.c \
	BASE/RAYS/ray_world_intersect.c \
	BASE/TUPLES/tuple_compare.c \
	BASE/TUPLES/tuple_create.c \
	BASE/TUPLES/tuple_cross.c \
	BASE/TUPLES/tuple_divide.c \
	BASE/TUPLES/tuple_dot.c \
	BASE/TUPLES/tuple_length.c \
	BASE/TUPLES/tuple_negating.c \
	BASE/TUPLES/tuple_normalize.c \
	BASE/TUPLES/tuple_scalarmult.c \
	BASE/TUPLES/tuple_sum.c \
	BASE/TUPLES/tuple_to_matrix.c \
	BASE/TUPLES/tuple_type.c \
	CORE/CLEANUP/cleanup.c \
	CORE/INIT/init_lux.c \
	CORE/INIT/init_mlx.c \
	CORE/INIT/init_parse.c \
	CORE/INIT/input_validate.c \
	CORE/PARSE/parse_assign_coord_utils.c \
	CORE/PARSE/parse_assign_vec_utils.c \
	CORE/PARSE/parse_camera_light.c \
	CORE/PARSE/parse_main.c \
	CORE/PARSE/parse_objects.c \
	CORE/PARSE/parse_utils.c \
	CORE/PARSE/parse_validate_assign_rgb_utils.c \
	CORE/PARSE/parse_validate_obj_utils.c \
	CORE/RENDER/create_image.c \
	CORE/RENDER/render.c \
	FEATURES/PPM/create_ppm.c \
	OBJECTS/CAMERA/camera_create.c \
	OBJECTS/CAMERA/camera_free.c \
	OBJECTS/CAMERA/camera_utils.c \
	OBJECTS/CYLINDER/normal_cylinder.c  \
	OBJECTS/PLANE/normal_plane.c  \
	OBJECTS/SPHERE/sphere_free.c \
	OBJECTS/SPHERE/sphere_normal.c  \
	OBJECTS/TRANSFORM/rotate.c  \
	OBJECTS/TRANSFORM/scale.c  \
	OBJECTS/TRANSFORM/shearing.c  \
	OBJECTS/TRANSFORM/translate.c \
	OBJECTS/UTILS/obj_free.c \
	OBJECTS/UTILS/obj_render.c \
	PHYSICS/ATMOSPHERE/atmosphere.c  \
	PHYSICS/LIGHT/lighting.c  \
	PHYSICS/LIGHT/reflect.c  \
	PHYSICS/LIGHT/shadow.c	\
	PHYSICS/MATERIAL/material.c 

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

$(TESTER): $(OBJECTS) $(MLX) $(LIBFT) $(MUK_LIB) $(TEST_MAIN)
	@$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(DUNITY_FLAGS) $(INCLUDES) -o $(TESTER) $(TEST_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX_FLAGS) -lm

$(VALGRIND): $(SRC_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(VALGRIND) $(SRC_MAIN) $(OBJECTS) $(LIBFT) $(MUK_LIB) $(MLX_FLAGS) -lm

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MUK_LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TESTER)
	@rm -f $(VALGRIND)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MUK_LIB_PATH)

re: fclean all

unity: $(TESTER)
	@ASAN_OPTIONS=fast_unwind_on_malloc=0:verbosity=1 ./$(TESTER) MAP/data.rt

valgrind: $(VALGRIND)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(VALGRIND) MAP/data.rt

.PHONY: all clean fclean re test memory aaaa

