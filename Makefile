# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 16:36:39 by eaptekar          #+#    #+#              #
#    Updated: 2018/08/26 18:18:14 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -lmlx -framework OpenGL -framework AppKit
LIBFT	= -L$(P_LFT) -lft

SRCS	=	main.c		image.c		zoom.c		hooks.c	\
			palettes.c 									\
			fractals/mandelbrot.c	fractals/julia.c	\
			fractals/burningship.c	fractals/tricorn.c	\
			fractals/cubic_mandelbrot.c					\
			fractals/cubic_julia.c	fractals/buffalo.c	\

SRC_DIR	= src/
OBJ_DIR	= obj/
I_INC	= includes
I_LFT	= libft/includes
P_LFT	= libft

INC = $(addprefix -I,$(I_INC) $(I_LFT))
SRC = $(addprefix $(SRC_DIR),$(SRCS))
OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
	@echo "\n$(NAME) is ready"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/fractals
	@$(CC) $(FLAGS) -o $@ -c $^ $(INC)
	@echo -n █

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(OBJ_DIR)
	@echo "removing ./obj/"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all
