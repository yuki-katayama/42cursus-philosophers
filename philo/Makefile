# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2022/05/10 23:04:37 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------ESCAPE CODE------------#
ifeq ($(shell uname), Linux)
	ESC_CLEAR_SCREEN		:=	\033[0;2J
	ESC_CLEAR_CURRENT_LINE	:=	\033[0;2K\r

	ESC_DEFAULT :=	\033[0;0m
	ESC_BOLD	:=	\033[0;1m
	ESC_UNDER	:=	\033[0;4m
	ESC_REV		:=	\033[0;7m

	ESC_BLACK		:=	\033[0;30m
	ESC_RED			:=	\033[0;31m
	ESC_GREEN		:=	\033[0;32m
	ESC_YELLOW		:=	\033[0;33m
	ESC_BLUE		:=	\033[0;34m
	ESC_PURPLE		:=	\033[0;35m
	ESC_CYAN		:=	\033[0;36m
	ESC_WHITE		:=	\033[0;37m

	ESC_BACK_BLACK		:=	\033[0;40m
	ESC_BACK_RED		:=	\033[0;41m
	ESC_BACK_GREEN		:=	\033[0;42m
	ESC_BACK_YELLOW		:=	\033[0;43m
	ESC_BACK_BLUE		:=	\033[0;44m
	ESC_BACK_PURPLE		:=	\033[0;45m
	ESC_BACK_CYAN		:=	\033[0;46m
	ESC_BACK_GRAY		:=	\033[0;47m
else
	ESC_CLEAR_SCREEN		:=	\x1b[2J
	ESC_CLEAR_CURRENT_LINE	:=	\x1b[2K\r

	ESC_DEFAULT :=	\x1b[0m
	ESC_BOLD	:=	\x1b[1m
	ESC_UNDER	:=	\x1b[4m
	ESC_REV		:=	\x1b[7m

	ESC_BLACK		:=	\x1b[30m
	ESC_RED			:=	\x1b[31m
	ESC_GREEN		:=	\x1b[32m
	ESC_YELLOW		:=	\x1b[33m
	ESC_BLUE		:=	\x1b[34m
	ESC_PURPLE		:=	\x1b[35m
	ESC_CYAN		:=	\x1b[36m
	ESC_WHITE		:=	\x1b[37m

	ESC_BACK_BLACK		:=	\x1b[40m
	ESC_BACK_RED		:=	\x1b[41m
	ESC_BACK_GREEN		:=	\x1b[42m
	ESC_BACK_YELLOW		:=	\x1b[43m
	ESC_BACK_BLUE		:=	\x1b[44m
	ESC_BACK_PURPLE		:=	\x1b[45m
	ESC_BACK_CYAN		:=	\x1b[46m
	ESC_BACK_GRAY		:=	\x1b[47m
endif

#-----------SET DIRECTORY--------#
INCDIR	:= -I./includes/philosopher_retry.h -I$(LIBDIR)
SRCDIR := ./srcs
SRCNAME	:=	main \
			utils \
			error \
			fork \
			init \
			philosopher \
			thread \
			eat \
			print_status \
			sleep \
			monitor
LIBDIR	:= ./libft
OBJDIR	:= ./objs
DPSDIR	:= ./dps

#-----------SET SRCS-------------#
INCDIR	:= -I./includes -I$(LIBDIR)

SRCS := $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCNAME)))

#-------------SET FLAGS--------------#
ifdef SAN_AD
	SANFLAGS := -g -fsanitize=address
else
ifdef SAN_TH
	SANFLAGS := -g -fsanitize=thread
else
ifdef SAN_LE
	SANFLAGS := -g -fsanitize=leak
endif
endif
endif

CFLAGS	:= -g -Wall -Wextra -Werror $(SANFLAGS)

VALGRIND := valgrind --tool=helgrind

#-------------SET VARIEBLE-----------#
NAME	:=	philo

CC		:= gcc

RM		:=	rm -rf

OBJS	:= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS		:= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

ifeq ($(shell uname),Linux)
    PTHREADFLG := -lpthread
endif
#-------------------------------------#

.PHONY: all
all	:	libft $(NAME) ## Run philo

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -MMD -MP $(INCDIR) $(PTHREADFLG) -c $< -o $@
	@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_YELLOW)$< ⌛"

-include $(DPS)


$(OBJDIR):
	@-mkdir -p $(OBJDIR)

$(DPSDIR):
	@-mkdir -p $(DPSDIR)

$(NAME):	$(OBJDIR) $(DPSDIR) $(OBJS)
			@-make -s -C libft/.
			@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_GREEN)philosopher: All files compiled into '$(OBJDIR)' and '$(DPSDIR)'. $(ESC_DEFAULT)✅\n"
			@$(CC) $(OBJS) $(CFLAGS) $(INCDIR) $(LIBDIR)/libft.a $(PTHREADFLG) -o $(NAME)
			@echo "$(ESC_GREEN)philosopher: '$(NAME)' was created. $(ESC_DEFAULT)✅"

.PHONY: val
val	:
	@valgrind --tool=helgrind ./philo 4 310 200 200

.PHONY: debug
debug: 
	@-make -s -e DEBUG=1

.PHONY: clean
clean	: ## Remove object
			@$(RM) $(OBJDIR)
			@$(RM) $(DPSDIR)
			@$(MAKE) clean -s -C ./libft
			@echo "$(ESC_RED)philosopher: '"$(OBJDIR)"' '"$(DPSDIR)"' has been deleted.$(ESC_DEFAULT)🗑️"

.PHONY: fclean
fclean	:	clean ## Remove object and static
			@$(MAKE) fclean -s -C ./libft
			@$(RM) $(NAME)
			@echo "$(ESC_RED)philosopher: '"$(NAME)"' has been deleted. $(ESC_DEFAULT)🗑️"

.PHONY: re
re	:	fclean all ## Retry cmpiles

.PHONY: help
help	: ## Display this help
	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
