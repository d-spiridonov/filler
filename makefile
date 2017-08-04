# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 17:57:29 by dspyrydo          #+#    #+#              #
#    Updated: 2017/07/22 17:57:33 by dspyrydo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
CC = gcc
CFLAGS =
LIBFT =     ./libft/libft.a 
OBJECTS =   ./filler.o          \
            ./findplace.o       \
			./findplace2.o		\
            ./place_t.o         \
            ./tools.o 			\

.PHONY: libft

all: $(NAME)
$(NAME) : $(OBJECTS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
libft:
	make -C ./libft
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf $(OBJECTS)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all
