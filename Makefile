# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 14:52:17 by tpierre           #+#    #+#              #
#    Updated: 2020/03/13 04:40:57 by tpierre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

OBJS			= $(SRC:.c=.o)

OBJS_BONUS		= $(SRC_BONUS:.c=.o)

CC				= gcc

AR				= ar rc

MAKE			= make

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

LIBFT			= libft

INDLIBFT		= -I$(LIBFT)

SRC_DIR			= srcs

SRC_NAME		= ft_printf.c ft_flag_adr.c ft_flag_char.c ft_flag_hexa.c ft_flag_int.c\
					ft_flag_per.c ft_flag_str.c ft_flag_uhexa.c ft_flag_uint.c ft_parser.c\
					ft_initialyze.c ft_get_indicator.c ft_utils.c

SRC_BONUS		=

INC_DIR			= includes

INC_NAME		= printf.h

SRC				= $(addprefix $(SRC_DIR)/,$(SRC_NAME))

HEADER			= $(addprefix $(INC_DIR)/,$(INC_NAME))

all:			libft_all $(NAME)

$(NAME):		$(OBJS)
				cp $(LIBFT)/libft.a $(NAME)
				$(AR) $(NAME) $(OBJS)

bonus:			$(NAME) $(OBJS_BONUS)
				$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c		$(HEADER)
				$(CC) $(CFLAGS) $(INDLIBFT) -c $< -o $(<:.c=.o) -I$(INC_DIR)

libft_all:
				$(MAKE) -C $(LIBFT) all

libft_bonus:
				$(MAKE) -C $(LIBFT) bonus

libft_clean:
				$(MAKE) -C $(LIBFT) clean

libft_fclean:
				$(MAKE) -C $(LIBFT) fclean

clean:			libft_clean
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			libft_fclean clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
