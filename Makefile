##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC 		=	src/free.c \
				src/display.c \
				src/set_mouse_cursor.c \
				src/init_game/init_cursor.c \
				src/init_game/init_window.c \
				src/init_game/init_game_end.c \
				src/init_game/init_how_to_play.c \
				src/init_game/init_intro.c \
				src/init_game/init_menu.c \
				src/init_game/init_options.c \
				src/init_game/init_pause.c \
				src/init_game/init_rpg.c \
				src/init_game/init_sound.c \
				src/init_game/init_music.c \
				src/init_game/init_sprite.c \
				src/init_game/init_clock.c \
				src/analyse_event/change_menu.c \
				src/elementary/get_file.c			\
				src/elementary/get_data_from_file.c	\
				src/elementary/freen.c				\
				src/elementary/put_str_error.c		\
				src/load_management/create_armor.c	\
				src/load_management/fill_armor.c	\
				src/load_management/destroy_armor.c	\
				src/load_management/load_armor.c	\
				src/load_management/create_sprite_data.c	\
				src/load_management/destroy_sprite_data.c	\
				src/load_management/load_sprite_data.c		\
				src/ennemy/create_ennemy.c 		\
				src/ennemy/destroy_ennemy.c 	\
				src/ennemy/fill_ennemy.c 	\
				src/ennemy/load_ennemy.c 	\

TESTS_MENU =	tests/menu/main.c \
				tests/menu/analyse_event/event.c \
				tests/menu/init_game/init_scene.c \
				tests/menu/init_game/init_clock.c \
				tests/menu/init_game/init_sprite.c \
				tests/menu/init_game/init_window.c \
				tests/menu/analyse_event/change_menu.c \
				tests/menu/analyse_event/event.c \
				tests/menu/display.c \
				tests/menu/init_game/init_settings.c \
				tests/menu/free_game/free_scene.c \
				tests/menu/analyse_event/handle_settings.c \

MAIN 		=	src/main.c


SRC_ELEMENTARY =		src/elementary/get_file.c							\
						src/elementary/get_data_from_file.c					\
						src/elementary/freen.c								\
						src/elementary/put_str_error.c						\
						src/elementary/get_files_from_directory.c			\
						src/elementary/freen_array.c						\
						src/elementary/verif_extension.c					\

SRC_LOAD_MANAGEMENT =	src/load_management/create_armor.c					\
						src/load_management/fill_armor.c					\
						src/load_management/destroy_armor.c					\
						src/load_management/load_armor.c					\
						src/load_management/create_sprite_data.c			\
						src/load_management/destroy_sprite_data.c			\
						src/load_management/load_sprite_data.c				\
						src/load_management/load_all_armors.c				\
						src/load_management/fill_all_armors.c				\
						src/load_management/destroy_all_armors.c			\
						src/load_management/create_all_armors.c				\
						src/load_management/print_all_armors.c				\
						src/load_management/create_animator.c				\
						src/load_management/destroy_animator.c				\
						src/load_management/create_clock_data.c				\
						src/load_management/destroy_clock_data.c			\
						src/load_management/fill_animator.c					\
						src/load_management/load_animator.c					\
						src/load_management/load_weapon.c					\
						src/load_management/create_weapon.c					\
						src/load_management/destroy_weapon.c				\
						src/load_management/fill_weapon.c					\

SRC =					$(SRC_ELEMENTARY)									\
						$(SRC_LOAD_MANAGEMENT)								\

TEST_FONC =		tests/elementary/test_freen.c								\
				tests/elementary/test_put_str_error.c						\
				tests/load_management/test_create_armor.c					\
				tests/load_management/test_create_sprite_data.c				\
				tests/load_management/test_load_sprite_data.c				\
				tests/load_management/test_destroy_sprite_data.c			\
				tests/load_management/test_load_armor.c						\
				tests/load_management/test_load_all_armors.c				\
				tests/elementary/test_get_file.c							\
				tests/elementary/test_get_number_of_files_in_directory.c	\
				tests/elementary/test_get_files_from_directory.c			\
				tests/load_management/test_load_animator.c					\
				tests/load_management/test_load_weapon.c

TEST_ENNEMY = 	tests/ennemy/test_ennemy_main.c	\

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

tests_menu:		make_lib $(OBJ_SRC)
				@$(CC) $(OBJ_SRC) $(TESTS_MENU) $(CFLAGS) -o "tests_menu" $(LFLAGS)
				@printf "\033[32m[Message]\033[39m Compilation de tests_menu \
				réussi\n"

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

tests_ennemy: 	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(TEST_ENNEMY) $(CFLAGS) -o "tests_ennemy" $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de tests_ennemy \
tests_player:	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(TEST_PLAYER) $(CFLAGS) -o "tests_player" $(LFLAGS)
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
