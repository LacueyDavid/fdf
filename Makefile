# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2023/08/01 06:55:45 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS =												\
													\
			$(addprefix srcs/,						\
				main.o								\
				create_map.o						\
				generate_img.o						\
				keyhook.o							\
				print_map.o							\
				rasterization.o						\
				opti_over_size.o	)				\
													\
			$(addprefix get_next_line/,				\
			get_next_line.o							\
			get_next_line_utils.o	)				\
													\

NAME = fdf

MINILIBX = ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx-linux
	make -C ./libft
	$(CC) -o $(NAME) $(OBJS) $(MINILIBX) $(LIBFT) -lXext -lX11 -lm

clean:
	make clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re bonus
