# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 11:02:58 by alopez-t          #+#    #+#              #
#    Updated: 2026/10/31 14:29:07 by alopez-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I libft -I .
NAME		= libftprintf.a

SRCS_M		= ft_printf.c helpers.c ft_print_universal.c ft_print_char.c \
			  ft_print_string.c ft_print_percent.c ft_print_int.c \
			  ft_print_unsigned.c ft_print_hex.c ft_print_pointer.c

SRCS_B		= ft_printf.c helpers.c ft_print_universal.c \
			  bonus/ft_print_char_bonus.c bonus/ft_print_string_bonus.c \
			  bonus/ft_print_percent_bonus.c bonus/ft_print_int_bonus.c \
			  bonus/ft_print_unsigned_bonus.c bonus/ft_print_hex_bonus.c \
			  bonus/ft_print_pointer_bonus.c

OBJS_M		= $(SRCS_M:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_M)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_M)
	@rm -f .bonus

bonus: .bonus

.bonus: $(LIBFT) $(OBJS_B)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_B)
	@touch .bonus

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_M) $(OBJS_B) .bonus
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) .bonus
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norminette:
	@norminette $(SRCS_M) $(SRCS_B) ft_printf.h

.PHONY: all bonus clean fclean re norminette
