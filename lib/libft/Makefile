# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 18:38:48 by pprivalo          #+#    #+#              #
#    Updated: 2018/02/12 12:26:54 by pprivalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

CFLAGS = -I.

O = ft_strrev.o \
	ft_lstsize.o \
	ft_swap.o \
	ft_power.o \
	ft_freearr.o \
	ft_strlen.o \
	ft_strdup.o \
	ft_strcpy.o \
	ft_strncpy.o \
	ft_strcat.o \
	ft_strncat.o \
	ft_strlcat.o \
	ft_strstr.o \
	ft_strnstr.o \
	ft_strcmp.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memccpy.o \
	ft_memmove.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memalloc.o \
	ft_memdel.o \
	ft_strnew.o \
	ft_strdel.o \
	ft_strclr.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strequ.o \
	ft_strnequ.o \
	ft_strsub.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_strsplit.o \
	ft_itoa.o \
	ft_putchar.o \
	ft_putstr.o \
	ft_putendl.o \
	ft_putnbr.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_lstnew.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstiter.o \
	ft_lstmap.o \
	get_next_line.o \

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< $(CFLAGS)

all:	$(NAME)

$(NAME):	$(O)
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

clean :
	@echo -ne "\r\033[0;31mClean objects libft...\033[0m\r"
	@/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all