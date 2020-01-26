# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:30:48 by ikhrypko          #+#    #+#              #
#    Updated: 2018/11/06 21:58:20 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/
LIBNAME = $(LIB)libft.a
HEADERS = ft_ls.h
FILES = help.c prin.c sort.c main.c process_fold.c tch.c utils.c
OBJS = $(FILES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@make -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME)

re: fclean all
