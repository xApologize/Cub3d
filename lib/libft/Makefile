# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 10:53:07 by jrossign          #+#    #+#              #
#    Updated: 2022/12/21 17:17:22 by jrossign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--files--#
C_FILES_M = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c	\
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c	\
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c		\
			ft_strjoin.c ft_strtrim_str.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c				\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c	\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_gnl.c				\
			ft_strjoinfree.c ft_freepp.c ft_strtrim_char.c ft_strcmp.c ft_get_pp_length.c\

#--C FILES TO O--#
O_FILES_M = $(C_FILES_M:.c=.o)

#--names--#
LIB_NAME	= libft.a

#--flags--#
ERROR_FLAGS	= -Wall -Werror -Wextra

#--path--#
OBJ_DIR		= obj/
SRC_DIR		= src/
INCLUDE_DIR	= include/

#--VPATH--#
VPATH		= $(SRC_DIR)

#--prefix--#
PRE_SRC_M	= $(addprefix $(SRC_DIR), $(C_FILES_M))
PRE_OBJ_M	= $(addprefix $(OBJ_DIR), $(O_FILES_M))

#--action--#
$(OBJ_DIR)%.o:	%.c
					@mkdir -p obj
					@gcc $(ERROR_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

$(LIB_NAME):	$(PRE_OBJ_M)
					@echo "Compiling libft..."
					@ar rcs $(LIB_NAME) $(PRE_OBJ_M)
					@echo "Compiling libft done."

all:			$(LIB_NAME)

clean: 
					@echo "Removing libft object files..."
					@rm -f $(PRE_OBJ_M)
					@rm -rf $(OBJ_DIR)
					@echo "Removing libft object files done."

fclean:
					@echo "Removing libft library..."
					@rm -f $(LIB_NAME)
					@echo "Removing libft library done."

re: 			fclean all

.PHONY: all clean fclean re bonus
