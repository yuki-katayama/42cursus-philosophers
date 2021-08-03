# NAME	=	philo

# CC		=	gcc

# VALGRIND = valgrind

# CFLAGS	=	

# SANFLAGS1	=	-g -fsanitize=address
# SANFLAGS2	=	-g -fsanitize=thread
# SANFLAGS3	=	-g --tool=helgrind

# VALFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666

# SRCDIR  = srcs/
# BSRCDIR  = bonus/

# SRCNAME	=	main \
# 			init \
# 			utils \
# 			eat \
# 			forks \
# 			output \
# 			monitor \
# 			error \
# 			exit

# BSRCNAME =	main \
# 			init \
# 			utils \
# 			eat \
# 			permission \
# 			output \
# 			monitor \
# 			error \
# 			exit

# SRCS	=	$(addsuffix .c, $(addprefix $(SRCDIR), $(SRCNAME)))
# BSRCS	=	$(addsuffix .c, $(addprefix $(BSRCDIR), $(BSRCNAME)))

# OBJS	=	$(SRCS:.c=.o)
# BOBJS	=	$(BSRCS:.c=.o)

# ifeq ($(shell uname),Linux)
#         PTHREADFLG = -lpthread
# endif

# .PHONY: all
# all	:	$(NAME) ## Run compile

# $(NAME)	:	${OBJS}
# 			@$(MAKE) -C libft/.
# 			@echo "\n\033[0;32mPhilosopher Compiling..."
# 			@$(CC) -g ${OBJS} $(CFLAGS) libft/libft.a $(PTHREADFLG) -o ${NAME}
# 			@@echo "Philosopher Complete\033[0m"

# .PHONY: san
# san	:	${OBJS} ## Run sanitize
# 			$(MAKE) -C libft/.
# 			@echo "\n\033[0;32mPhilosopher Compiling..."
# 			$(CC) -g ${OBJS} $(SANFLAGS1) $(CFLAGS) libft/libft.a $(PTHREADFLG) -o ${NAME}
# 			@echo "Philosopher Complete\033[0m"

# .PHONY: val
# val	:	 ${OBJS} ## Run valgrind
# 			$(VALGRIND) $(VALFLAGS) ./philosopher

# .PHONY: clean
# clean	:	## Remove object
# 			@echo "\033[0;33mCleaning..."
# 			$(MAKE) clean -C ./libft
# 			$(RM) $(OBJS)
# 			$(RM) $(BOBJS)
# 			@echo "\033[0m"

# .PHONY: fclean
# fclean	:	clean ## Remove object and static
# 			@echo "\033[0;33mRemoving executable..."
# 			$(MAKE) fclean -C ./libft
# 			$(RM) $(NAME)
# 			@echo "\033[0m"

# .PHONY: bonus # Run compile bonus
# bonus	:	fclean ${BOBJS}
# 			$(MAKE) -C libft/.
# 			@echo "\n\033[0;32mPhilosopher Compiling..."
# 			$(CC) -g ${BOBJS} $(CFLAGS) libft/libft.a $(PTHREADFLG) -o ${NAME}
# 			@echo "Philosopher Complete\033[0m"

# .PHONY: re
# re	:	fclean all ## Retry cmpiles

# .PHONY: test
# test	:	## Retry test
# 			./philosopher 5 1000 100 100

# .PHONY: help
# help	: ## Display this help
# 	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2021/08/02 12:35:31 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------ESCAPE CODE------------#
ifeq ($(shell uname), Linux)
	ESC_CLEAR_SCREEN		?=	\033[0;2J
	ESC_CLEAR_CURRENT_LINE	?=	\033[0;2K\r

	ESC_DEFAULT ?=	\033[0;0m
	ESC_BOLD	?=	\033[0;1m
	ESC_UNDER	?=	\033[0;4m
	ESC_REV		?=	\033[0;7m

	ESC_BLACK		?=	\033[0;30m
	ESC_RED			?=	\033[0;31m
	ESC_GREEN		?=	\033[0;32m
	ESC_YELLOW		?=	\033[0;33m
	ESC_BLUE		?=	\033[0;34m
	ESC_PURPLE		?=	\033[0;35m
	ESC_CYAN		?=	\033[0;36m
	ESC_WHITE		?=	\033[0;37m

	ESC_BACK_BLACK		?=	\033[0;40m
	ESC_BACK_RED		?=	\033[0;41m
	ESC_BACK_GREEN		?=	\033[0;42m
	ESC_BACK_YELLOW		?=	\033[0;43m
	ESC_BACK_BLUE		?=	\033[0;44m
	ESC_BACK_PURPLE		?=	\033[0;45m
	ESC_BACK_CYAN		?=	\033[0;46m
	ESC_BACK_GRAY		?=	\033[0;47m
else
	ESC_CLEAR_SCREEN		?=	\x1b[2J
	ESC_CLEAR_CURRENT_LINE	?=	\x1b[2K\r

	ESC_DEFAULT ?=	\x1b[0m
	ESC_BOLD	?=	\x1b[1m
	ESC_UNDER	?=	\x1b[4m
	ESC_REV		?=	\x1b[7m

	ESC_BLACK		?=	\x1b[30m
	ESC_RED			?=	\x1b[31m
	ESC_GREEN		?=	\x1b[32m
	ESC_YELLOW		?=	\x1b[33m
	ESC_BLUE		?=	\x1b[34m
	ESC_PURPLE		?=	\x1b[35m
	ESC_CYAN		?=	\x1b[36m
	ESC_WHITE		?=	\x1b[37m

	ESC_BACK_BLACK		?=	\x1b[40m
	ESC_BACK_RED		?=	\x1b[41m
	ESC_BACK_GREEN		?=	\x1b[42m
	ESC_BACK_YELLOW		?=	\x1b[43m
	ESC_BACK_BLUE		?=	\x1b[44m
	ESC_BACK_PURPLE		?=	\x1b[45m
	ESC_BACK_CYAN		?=	\x1b[46m
	ESC_BACK_GRAY		?=	\x1b[47m
endif

#-----------SET DIRECTORY--------#
SRCDIR	?= ./srcs
INCDIR	?= -L./srcs philosopher.h
OBJDIR	?= ./objs
DPSDIR	?= ./dps

#-----------SET SRCS-------------#
SRCNAME	?=	main \
			init \
			utils \
			eat \
			forks \
			output \
			monitor \
			error \
			exit

BSRCNAME ?=	main \
			init \
			utils \
			eat \
			permission \
			output \
			monitor \
			error \
			exit

SRCS ?= $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCNAME)))

#-------------SET FLAGS--------------#
CFLAGS	?= -Wall -Wextra -Werror -g

VALFLAGS ?= --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666

SANFLAGS ?=	-g -fsanitize=address

#-------------SET VARIEBLE-----------#
NAME	?=	philo

CC		?= gcc

VALGRIND ?= valgrind

RM		:=	rm -rf

OBJS	?= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS		?= $(addprefix $(DPSDIR)/, $(notdir $(SRCS:.o=.d)))

ifeq ($(shell uname),Linux)
    PTHREADFLG ?= -lpthread
endif
#-------------------------------------#

.PHONY: all
all	:	$(NAME) # Run philo

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@-mkdir -p $(OBJDIR)
	@-mkdir -p $(DPSDIR)
	@$(CC) $(CFLAGS)  -MMD -MP -MF $(DPSDIR)/$(notdir $(<:.c=.d)) -c $< -o $@
	@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_YELLOW)$< ⌛"

-include $(DPS)

$(NAME):	$(OBJS)
			@$(MAKE) -C libft/.
			@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_GREEN)philosopher: All files compiled into '$(OBJDIR)' and '$(DPSDIR)'. $(ESC_DEFAULT)✅\n"
			@$(CC) $(OBJS) $(CFLAGS) libft/libft.a $(PTHREADFLG) -o $(NAME)
			@echo "$(ESC_GREEN)philosopher: '$(NAME)' was created. $(ESC_DEFAULT)✅"


.PHONY: val
val	:	${OBJS} ## Run valgrind
		@$(MAKE) -C libft/.
		@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_GREEN)philosopher: All files compiled into '$(OBJDIR)' and '$(DPSDIR)'. $(ESC_DEFAULT)✅\n"
		@$(CC) $(OBJS) $(CFLAGS) libft/libft.a $(PTHREADFLG) -o $(NAME)
		@echo "$(ESC_GREEN) '$(NAME)' was created. $(ESC_DEFAULT)✅"
		$(VALGRIND) $(VALFLAGS) ./philo 4 400 200 200

.PHONY: clean
clean	: ## Remove object
			@$(RM) $(OBJDIR)
			@$(RM) $(DPSDIR)
			@$(MAKE) clean -s -C ./libft
			@echo "$(ESC_RED)philosopher: '"$(OBJDIR)"' '"$(DPSDIR)"' has been deleted.$(ESC_DEFAULT)🗑️"

.PHONY: fclean
fclean	:	clean ## Remove object and static
			@$(MAKE) fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(ESC_RED)philosopher: '"$(NAME)"' has been deleted. $(ESC_DEFAULT)🗑️"

.PHONY: re
re	:			fclean all ## Retry cmpiles

.PHONY: help
help	: ## Display this help
	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
