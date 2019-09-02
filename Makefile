# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 09:17:30 by nolakim           #+#    #+#              #
#    Updated: 2019/08/27 02:01:11 by nolakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



libx_flags = -L minilibx -lmlx -framework OpenGL -framework AppKit -g

cflags = -Wall -Wextra -Werror

make_lib = @make -C ./libft/

header = fdf.h

includes = ./libft/libft.a ./minilibx/libmlx.a

SRC = *.c

OBJ = *.o

cc = @gcc

name = fdf

$(name) :
		@make -C libft/
		$(cc) $(cflags) $(libx_flags) $(SRC) $(includes) -o $(name)
clean:
		@make -C libft/ clean
		@/bin/rm -rf $(name)
fclean: clean
		@make -C libft/ fclean
re: fclean all
