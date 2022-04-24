##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

MAIN 		=	src/main.c

SRC 		=	src/elementary/get_file.c			\
				src/elementary/get_data_from_file.c	\
				src/elementary/freen.c				\
				src/elementary/put_str_error.c		\
				src/load_management/create_armor.c	\
				src/load_management/fill_armor.c	\
				src/load_management/destroy_armor.c	\
				src/load_management/load_armor.c	\
				src/load_management/create_sprite_data.c	\
				src/load_management/destroy_sprite_data.c	\
				src/load_management/load_sprite_data.c	\

TEST_FONC	=	tests/elementary/test_freen.c	\
				tests/elementary/test_put_str_error.c	\
				tests/load_management/test_create_armor.c	\
				tests/load_management/test_create_sprite_data.c	\
				tests/load_management/test_load_sprite_data.c	\
				tests/load_management/test_destroy_sprite_data.c	\
				tests/load_management/test_load_armor.c	\
				tests/elementary/test_get_file.c

MAIN_DEBUG	=	src/temp_test.c

OBJ_SRC		=	$(SRC:%.c=%.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(TEST_FONC:%.c=%.o)

CC			=	gcc

TEST_BINARY	=	unit_tests

TEST_PLAYER =	src/entities/player/test_file_player.c    \

CFLAGS		=	-Wall -Wextra -Wshadow -Werror -I./include -lcsfml-audio \
				-lcsfml-graphics -lm -lcsfml-system -lcsfml-window

TESTS_FLAGS	=	--coverage -lcriterion

LFLAGS		=	-L./lib -lmy

NAME		=	my_rpg

MK			=	make -s

MV			=	mv

%.o:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@
			@printf "\033[35m[Compilation]\033[39m %s\n" $<

all:		$(NAME)

$(NAME):	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(MAIN) $(CFLAGS) -o $(NAME) $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de %s réussi\n" \
				$(NAME)

make_lib:
			@$(MK) -C lib/my/

debug:		CFLAGS += -g
debug:		re

clean:
			@$(RM) $(OBJ_SRC)
			@$(RM) $(OBJ_TEST)
			@$(MK) -C lib/my/ clean
			@printf "\033[31m[Message]\033[39m Clean libmy reussi !\n"
			@printf "\033[31m[Message]\033[39m Clean %s reussi !\n" $(NAME)

tests_run:		tclean $(NAME)
			$(CC) $(SRC) $(TEST_FONC) $(CFLAGS) $(TESTS_FLAGS) $(LFLAGS) \
			-o $(TEST_BINARY)
			./$(TEST_BINARY)
			@printf "\033[32m[Message]\033[39m Compilation de tests réussi !\n"
			$(MV) *.gcda tests
			$(MV) *.gcno tests
			gcovr -e tests
			gcovr -e tests -bu

tests_player:	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(TEST_PLAYER) $(CFLAGS) -o "tests_ennemy" $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de tests_player \
			réussi\n"

tclean:
			@$(RM) tests/*.gcda
			@$(RM) tests/*.gcno
			@$(RM) *.gcda
			@$(RM) *.gcno
			@$(RM) $(TEST_BINARY)
			@printf "\033[31m[Message]\033[39m TClean %s reussi !\n" $(NAME)

fclean:			clean	tclean
			@$(MK) -C lib/my/ fclean
			@printf "\033[31m[Message]\033[39m FClean libmy reussi !\n"
			@$(RM) $(NAME)
			@$(RM) $(TEST_BINARY)
			@$(RM) $(NAME_DEBUG)
			@$(RM) ./lib/libmy.a
			@printf "\033[31m[Message]\033[39m FClean %s reussi !\n" $(NAME)

re:				fclean all

.PHONY:		clean fclean tclean re all tests_run cpy debug make_lib $(NAME)
