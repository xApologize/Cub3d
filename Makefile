#--PROJECT_NAME--#
PROJECT_NAME	= cub3d

#--C FILES--# >
C_FILES_MAIN	= cub3d.c error.c free_data.c raycaster.c data.c	\
				  draw_minimap.c moves_1.c moves_2.c utils.c 		\
				  raycasting_utils.c								\

C_FILES_CHECK	= check_arguments.c get_map.c check_path.c			\
				  check_arguments_1.c check_map.c check_map_utils.c	\
				  set_map_struct.c									\

C_FILES_FF		= flood_fill.c flood_fill_utils.c					\

C_FILES_MAIN_B	= cub3d_bonus.c error_bonus.c free_data_bonus.c		\
				  raycaster_bonus.c data_bonus.c					\
				  draw_minimap_bonus.c moves_1_bonus.c				\
				  moves_2_bonus.c utils_bonus.c						\
				  raycasting_utils_bonus.c animation_spell_bonus.c	\
				  draw_minimap_utils_bonus.c mouse_movement_bonus.c	\

C_FILES_CHECK_B	= check_arguments_bonus.c get_map_bonus.c			\
				  check_path_bonus.c check_arguments_1_bonus.c		\
				  check_map_bonus.c check_map_utils_bonus.c			\
				  set_map_struct_bonus.c							\

C_FILES_FF_B	= flood_fill_bonus.c flood_fill_utils_bonus.c		\

#--C FILES TO O FILES--# >
O_FILES			= $(C_FILES_MAIN:.c=.o) $(C_FILES_CHECK:.c=.o) $(C_FILES_FF:.c=.o)

O_FILES_B		= $(C_FILES_MAIN_B:.c=.o) $(C_FILES_CHECK_B:.c=.o) $(C_FILES_FF_B:.c=.o)

#--NAME--# >
NAME			= $(PROJECT_NAME)
NAME_B			= $(PROJECT_NAME)_bonus

#--FLAGS--# >
ERROR_FLAGS		= -Werror -Wall -Wextra -g
LIB_FLAG		= -L./lib/libft -lft
MLX				= MLX42/libmlx42.a 
MLX_FLAG_JB		= -lglfw -L /Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/
MLX_FLAG_BEN	= -lglfw -L /Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib/

#--DIR PATH--# >
SRC_DIR			= src/
SRC_DIR_B		= $(BONUS_DIR)src/
OBJ_DIR			= obj/
BONUS_DIR		= bonus/
MLX_DIR			= MLX42/
INC_DIR			= include/
INC_DIR_B		= $(BONUS_DIR)include/
LIB_DIR			= lib/libft/
CHECK_MAP_DIR	= $(SRC_DIR)check_map/
CHECK_MAP_DIR_B	= $(BONUS_DIR)$(SRC_DIR)check_map/
FF_DIR			= $(SRC_DIR)flood_fill/
FF_DIR_B		= $(BONUS_DIR)$(SRC_DIR)flood_fill/

#--PREFIX--#
PRE_OBJ			= $(addprefix $(OBJ_DIR), $(O_FILES))
PRE_OBJ_B		= $(addprefix $(OBJ_DIR), $(O_FILES_B))

#--VPATH--#
VPATH			= $(SRC_DIR) $(CHECK_MAP_DIR) $(FF_DIR)			\
				  $(SRC_DIR_B) $(CHECK_MAP_DIR_B) $(FF_DIR_B)	\

#--ACTIONS--# >
$(OBJ_DIR)%.o:		%.c
				@mkdir -p obj/
				@gcc $(ERROR_FLAGS) -Iinclude/ -o $@ -c $<

$(NAME):			$(PRE_OBJ)
				@make -C $(LIB_DIR)
				@make -C $(MLX_DIR)
				@echo "Compiling $(PROJECT_NAME)..."
ifeq ($(USER), jrossign)
				@gcc $(ERROR_FLAGS) $(PRE_OBJ) -Iinclude/ -o $(NAME) $(LIB_FLAG) $(MLX) $(MLX_FLAG_JB)
else
				@gcc $(ERROR_FLAGS) $(PRE_OBJ) -Iinclude/ -o $(NAME) $(LIB_FLAG) $(MLX) $(MLX_FLAG_BEN)
endif
				@echo "Compiling $(PROJECT_NAME) done."

$(NAME_B):				$(PRE_OBJ_B)
				@make -C $(LIB_DIR)
				@make -C $(MLX_DIR)
				@echo "Compiling $(PROJECT_NAME) bonus..."
ifeq ($(USER), jrossign)
				@gcc $(ERROR_FLAGS) $(PRE_OBJ_B) -Iinclude/ -o $(NAME_B) $(LIB_FLAG) $(MLX) $(MLX_FLAG_JB)
else
				@gcc $(ERROR_FLAGS) $(PRE_OBJ_B) -Iinclude/ -o $(NAME_B) $(LIB_FLAG) $(MLX) $(MLX_FLAG_BEN)
endif
				@echo "Compiling $(PROJECT_NAME) bonus done."

all:				$(NAME)

bonus:				$(NAME_B)

clean:
				@make -C $(LIB_DIR) clean
				@make -C $(MLX_DIR) clean
				@echo "Removing $(PROJECT_NAME) object files..."
				@rm -f $(O_FILES)
				@rm -rf $(OBJ_DIR)
				@echo "Removing $(PROJECT_NAME) object files done."

fclean:				clean
				@make -C $(LIB_DIR) fclean
				@make -C $(MLX_DIR) fclean
				@echo "Removing $(PROJECT_NAME) program..."
				@rm -f $(NAME)
				@echo "Removing $(PROJECT_NAME) program done."

clean_bonus:
				@make -C $(LIB_DIR) clean
				@make -C $(MLX_DIR) clean
				@echo "Removing $(PROJECT_NAME)_bonus object files..."
				@rm -f $(O_FILES_B)
				@rm -rf $(OBJ_DIR)
				@echo "Removing $(PROJECT_NAME)_bonus object files done."

fclean_bonus:		clean_bonus
				@make -C $(LIB_DIR) fclean
				@make -C $(MLX_DIR) fclean
				@echo "Removing $(PROJECT_NAME)_bonus program..."
				@rm -f $(NAME_B)
				@echo "Removing $(PROJECT_NAME)_bonus program done."

re:					fclean all

re_bonus:			fclean_bonus bonus 

.PHONY: all fclean clean re
