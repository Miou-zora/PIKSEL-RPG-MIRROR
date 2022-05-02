##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =					$(SRC_ANIMATOR)										\
						$(SRC_SPRITE_DATA)									\
						$(SRC_ARMOR)										\
						$(SRC_WEAPON)										\
						$(SRC_ENEMY)										\
						$(SRC_CLOCK)										\
						$(SRC_ELEMENTARY)									\
						$(SRC_EVENT)										\
						$(SRC_GAME_MANAGEMENT)								\

PATH_GAME_MANAGEMENT =	src/game_management

SRC_GAME_MANAGEMENT =	$(PATH_GAME_MANAGEMENT)/init_game.c					\
						$(PATH_GAME_MANAGEMENT)/update.c					\
						$(PATH_GAME_MANAGEMENT)/display.c					\

PATH_EVENT =			src/event_management

SRC_EVENT =				$(PATH_EVENT)/event_handler.c						\

MAIN 		=			src/main.c

PATH_ELEMENTARY =		src/elementary

SRC_ELEMENTARY =		$(PATH_ELEMENTARY)/get_file.c						\
						$(PATH_ELEMENTARY)/get_data_from_file.c				\
						$(PATH_ELEMENTARY)/freen.c							\
						$(PATH_ELEMENTARY)/put_str_error.c					\
						$(PATH_ELEMENTARY)/get_files_from_directory.c		\
						$(PATH_ELEMENTARY)/freen_array.c					\
						$(PATH_ELEMENTARY)/verif_extension.c				\

PATH_ENEMY =			src/entities/enemy

SRC_ENEMY =				$(PATH_ENEMY)/create_enemy.c						\
						$(PATH_ENEMY)/destroy_enemy.c						\
						$(PATH_ENEMY)/load_enemy.c							\
						$(PATH_ENEMY)/fill_enemy.c							\

PATH_CLOCK_DATA =		$(PATH_ELEMENTARY)/clock

SRC_CLOCK =				$(PATH_CLOCK_DATA)/create_clock_data.c				\
						$(PATH_CLOCK_DATA)/destroy_clock_data.c				\
						$(PATH_CLOCK_DATA)/update_clock_data.c				\
						$(PATH_CLOCK_DATA)/drain_clock_data.c				\
						$(PATH_CLOCK_DATA)/set_framerate_clock_data.c		\

PATH_ARMOR =			src/items/armor

SRC_ARMOR =				$(PATH_ARMOR)/create_armor.c						\
						$(PATH_ARMOR)/fill_armor.c							\
						$(PATH_ARMOR)/destroy_armor.c						\
						$(PATH_ARMOR)/load_armor.c							\
						$(PATH_ARMOR)/create_all_armors.c					\
						$(PATH_ARMOR)/destroy_all_armors.c					\
						$(PATH_ARMOR)/load_all_armors.c						\
						$(PATH_ARMOR)/fill_all_armors.c						\
						$(PATH_ARMOR)/print_all_armors.c					\

PATH_WEAPON =			src/items/weapon

SRC_WEAPON =			$(PATH_WEAPON)/create_weapon.c						\
						$(PATH_WEAPON)/fill_weapon.c						\
						$(PATH_WEAPON)/destroy_weapon.c						\
						$(PATH_WEAPON)/load_weapon.c						\
						$(PATH_WEAPON)/create_all_weapons.c					\
						$(PATH_WEAPON)/destroy_all_weapons.c				\
						$(PATH_WEAPON)/load_all_weapons.c					\
						$(PATH_WEAPON)/fill_all_weapons.c					\
						$(PATH_WEAPON)/print_all_weapons.c					\

PATH_SPRITE_DATA =		src/sprite_data

SRC_SPRITE_DATA =		$(PATH_SPRITE_DATA)/create_sprite_data.c			\
						$(PATH_SPRITE_DATA)/destroy_sprite_data.c			\
						$(PATH_SPRITE_DATA)/load_sprite_data.c				\

PATH_ANIMATOR =			src/animator

SRC_ANIMATOR =			$(PATH_ANIMATOR)/create_animator.c					\
						$(PATH_ANIMATOR)/destroy_animator.c					\
						$(PATH_ANIMATOR)/load_animator.c					\
						$(PATH_ANIMATOR)/fill_animator.c					\
						$(PATH_ANIMATOR)/increment_animator_image_pos.c		\
						$(PATH_ANIMATOR)/refresh_animator.c					\
						$(PATH_ANIMATOR)/update_animator.c					\

OBJ_SRC		=	$(SRC:%.c=%.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(TEST_FONC:%.c=%.o)

CC			=	gcc

TEST_BINARY	=	unit_tests

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
			$(CC) $(OBJ_SRC) $(MAIN) $(CFLAGS) -o $(NAME) $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de %s réussi\n" \
				$(NAME)

make_lib:
			@$(MK) -C lib/my/

debug:		CFLAGS += -g
debug:		re

tests_menu:		make_lib $(OBJ_SRC)
				@$(CC) $(OBJ_SRC) $(TESTS_MENU) $(CFLAGS_MENU) -o "tests_menu" $(LFLAGS) -g
				@printf "\033[32m[Message]\033[39m Compilation de tests_menu \
				réussi\n"

clean:
			echo $(SRC_ANIMATOR)
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
			@printf "\033[32m[Message]\033[39m Compilation de tests_ennemy"

tests_player:	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(TEST_PLAYER) $(CFLAGS) -o "tests_player" $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de tests_player \
			réussi\n"

tests_background:	make_lib $(OBJ_SRC)
			@$(CC) $(OBJ_SRC) $(TEST_BACKGROUND) $(CFLAGS) -o "tests_background" $(LFLAGS)
			@printf "\033[32m[Message]\033[39m Compilation de tests_background \
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
			@$(RM) $(BINARY_TEST_ANIMATION)
			@$(RM) $(TEST_BINARY)
			@$(RM) $(NAME_DEBUG)
			@$(RM) ./lib/libmy.a
			@printf "\033[31m[Message]\033[39m FClean %s reussi !\n" $(NAME)

re:				fclean all

.PHONY:		clean fclean tclean re all tests_run cpy debug make_lib $(NAME)
