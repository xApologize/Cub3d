#--PROJECT_NAME--#
PROJECT_NAME	= cub3d

#--C FILES--# > all .c files
C_FILES			= cub3d.c check_map/check_map.c 

#--C FILES TO O FILES--# > where you make the .o files dependencies
O_FILES			= $(C_FILES:.c=.o)

#--NAME--# > name of the project
NAME			= $(PROJECT_NAME)

#--FLAGS--# > flags used by the command above
ERROR_FLAGS		= -Werror -Wall -Wextra -g
LIB_FLAG		= -L./lib/libft -lft

#--DIR PATH--# > path to the file
SRC_DIR			= src/
OBJ_DIR			= obj/
INC_DIR			= include/
LIB_DIR			= lib/libft/
PROJECT_PATH	= ~/Documents/Cursus/cursus-projet/Cub3d/

#--PREFIX--#
PRE_OBJ			= $(addprefix $(OBJ_DIR), $(notdir $(O_FILES)))

#--VPATH--#
VPATH			= $(SRC_DIR)

#--ACTIONS--# > all the thing you want your Makefile to do
%.o:		%.c
				@echo "Compiling $(notdir $@)..."
				@mkdir -p obj/
				@gcc $(ERROR_FLAGS) -Iinclude/ -o $(notdir $@) -c $<
				@mv $(notdir $@) $(PROJECT_PATH)$(OBJ_DIR)

$(NAME):			$(O_FILES)
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
