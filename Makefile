
#	Names
NAME_PIPEX		=	pipex

#	Includes
-include make/includes.mk
-include make/srcs.mk

#	Compilation
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs

INCLUDES_PATH	=	./includes

SRCS_OBJS		=	$(SRCS_SOURCES:.c=.o)

#	Delete
RM				=	rm -rf

#	RULES
#		Defaults:
all:	$(NAME_PIPEX)

#		Convert .c to .o
%.o:	%.c $(INCLUDES)
		@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

#		Compile Pipex
$(NAME_PIPEX):	$(INCLUDES) $(SRCS_OBJS)
					@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) $(SRCS_OBJS) -o $(NAME_PIPEX)
					@echo "\x1b[32mPipex Created"

#		Clean
clean:
					@$(RM) $(SRCS_OBJS)
					@echo "Cleaning all .o in project!"

#		Fclean
fclean:			clean
					@$(RM) $(NAME_PIPEX)
					@echo "Cleaning compiled programs!"

#		Re
re:				fclean all
					@echo "Cleaned and rebuild everything for Pipex!"

#		Generate .mk (Makefile includes)
gmk:
		@find includes -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk
		@find srcs -name '*.c' | sed 's/^/SRCS_SOURCES += /' > make/srcs.mk

#		PHONY
.PHONY:			all clean fclean re gmk
