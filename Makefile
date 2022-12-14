#--PROJECT_NAME--#
PROJECT_NAME	= cub3d

#--C FILES--# >
C_FILES_MAIN	= cub3d.c error.c free_data.c						\

C_FILES_CHECK	= check_arguments.c get_map.c check_path.c			\
				  check_arguments_1.c check_map.c check_map_utils.c	\
				  set_map_struct.c									\

C_FILES_FF		= flood_fill.c flood_fill_utils.c					\

#--C FILES TO O FILES--# >
O_FILES			= $(C_FILES_MAIN:.c=.o) $(C_FILES_CHECK:.c=.o) $(C_FILES_FF:.c=.o)

#--NAME--# >
NAME			= $(PROJECT_NAME)

#--FLAGS--# >
ERROR_FLAGS		= -Werror -Wall -Wextra -g
LIB_FLAG		= -L./lib/libft -lft

#--DIR PATH--# >
SRC_DIR			= src/
OBJ_DIR			= obj/
INC_DIR			= include/
LIB_DIR			= lib/libft/
CHECK_MAP_DIR	= $(SRC_DIR)check_map/
FF_DIR			= $(SRC_DIR)flood_fill/

#--PREFIX--#
PRE_OBJ			= $(addprefix $(OBJ_DIR), $(O_FILES))

#--VPATH--#
VPATH			= $(SRC_DIR) $(CHECK_MAP_DIR) $(FF_DIR)

#--ACTIONS--# >
$(OBJ_DIR)%.o:		%.c
				@mkdir -p obj/
				@gcc $(ERROR_FLAGS) -Iinclude/ -o $@ -c $<

$(NAME):			$(PRE_OBJ)
				@make -C $(LIB_DIR)
				@echo "Compiling $(PROJECT_NAME)..."
				@gcc $(ERROR_FLAGS) $(PRE_OBJ) -Iinclude/ -o $(NAME) $(LIB_FLAG)
				@echo "Compiling $(PROJECT_NAME) done."

all:				$(NAME)

clean:
				@make -C $(LIB_DIR) clean
				@echo "Removing $(PROJECT_NAME) object files..."
				@rm -f $(O_FILES)
				@rm -rf $(OBJ_DIR)
				@echo "Removing $(PROJECT_NAME) object files done."

fclean:				clean
				@make -C $(LIB_DIR) fclean
				@echo "Removing $(PROJECT_NAME) program..."
				@rm -f $(NAME)
				@echo "Removing $(PROJECT_NAME) program done."

re:					fclean all

.PHONY: all fclean clean re
