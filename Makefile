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
						$(SRC_MENU)											\
						$(SRC_BACKGROUND)									\
						$(SRC_PLAYER)										\
						$(SRC_PARTICLES)									\
						$(SRC_INVENTORY)									\
						$(SRC_NPC)											\
						$(SRC_CINEMATIC)									\
						$(SRC_SOUND_MUSIC)

SRC_CINEMATIC	=		src/init_game/init_cinematic.c						\
						src/init_game/init_cinematic_sprites.c				\
						src/game_management/update_cinematic.c				\
						src/game_management/update_clock_cinematic.c		\
						src/game_management/display_cinematic.c				\

SRC_INVENTORY	=		src/items/spawn_random_loot.c						\
						src/game_management/display_loot_and_inventory.c	\
						src/init_game/init_inventory.c						\
						src/event_management/key_management/handle_inv.c	\
						src/event_management/key_management/add_armor.c		\
						src/event_management/key_management/add_weapon.c	\
						src/items/remove_loot.c								\

PATH_PARTICLES =		src/particle

SRC_PARTICLES =			$(PATH_PARTICLES)/create_framebuffer.c				\
						$(PATH_PARTICLES)/create_nest_particle.c			\
						$(PATH_PARTICLES)/update_nest_particle.c			\
						$(PATH_PARTICLES)/put_nest_particle_on_framebuffer.c\
						$(PATH_PARTICLES)/destroy_nest_particle.c

SRC_MENU	=			src/init_game/init_menu.c							\
						src/event_management/menu/handle_menu_functions.c	\
						src/init_game/init_menu_positions.c					\
						src/event_management/menu/handle_menu_events.c		\
						src/event_management/menu/handle_settings_events.c	\
						src/event_management/menu/handle_fps.c				\
						src/event_management/menu/handle_music_and_sound.c	\
						src/event_management/menu/how_to_play.c				\
						src/init_game/init_how_to_play.c					\
						src/game_management/display_one_more_char.c			\
						src/game_management/update_how_to_play.c			\
						src/event_management/key_management/pause_event.c	\
						src/game_management/display_pause.c					\

PATH_PLAYER = 			src/player

SRC_PLAYER = 			$(PATH_PLAYER)/init_player.c 						\
			 			$(PATH_PLAYER)/init_stats.c 						\
						$(PATH_PLAYER)/display_player.c 					\
						$(PATH_PLAYER)/display_hitbox.c 					\
						$(PATH_PLAYER)/init_player_clock.c 					\

PATH_GAME_MANAGEMENT =	src/game_management

SRC_GAME_MANAGEMENT =	$(PATH_GAME_MANAGEMENT)/init_game.c					\
						$(PATH_GAME_MANAGEMENT)/update.c					\
						$(PATH_GAME_MANAGEMENT)/display.c					\
						$(PATH_GAME_MANAGEMENT)/display_stats.c				\
						$(PATH_GAME_MANAGEMENT)/move_player_up.c 			\
						$(PATH_GAME_MANAGEMENT)/move_player_down.c 			\
						$(PATH_GAME_MANAGEMENT)/handle_stats.c				\
						$(PATH_GAME_MANAGEMENT)/update_player_attack.c 		\
						$(PATH_GAME_MANAGEMENT)/update_player_move.c 		\

PATH_EVENT =			src/event_management

SRC_EVENT =				$(PATH_EVENT)/key_management/event_handler.c		\
						$(PATH_EVENT)/key_management/event_key.c			\
						$(PATH_EVENT)/key_management/key_d_event.c 			\
						$(PATH_EVENT)/key_management/key_q_event.c 			\
						$(PATH_EVENT)/key_management/key_s_event.c 			\
						$(PATH_EVENT)/key_management/key_z_event.c 			\
						$(PATH_EVENT)/key_management/key_f_event.c 			\
						$(PATH_EVENT)/key_management/attack_key_event.c		\
						$(PATH_EVENT)/key_management/add_armor_down.c		\
						$(PATH_EVENT)/key_management/handle_loot.c			\
						$(PATH_EVENT)/key_management/detect_press_q_and_d.c \
						$(PATH_EVENT)/map_changement/city_to_forest.c 		\
						$(PATH_EVENT)/map_changement/city_to_room.c 		\
						$(PATH_EVENT)/map_changement/room_to_city.c 		\
						$(PATH_EVENT)/map_changement/forest_to_labo.c 		\
						$(PATH_EVENT)/map_changement/labo_to_forest.c 		\
						$(PATH_EVENT)/map_changement/forest_to_city.c 		\

MAIN 		=			src/main.c

PATH_ELEMENTARY =		src/elementary

SRC_ELEMENTARY =		$(PATH_ELEMENTARY)/get_file.c						\
						$(PATH_ELEMENTARY)/get_data_from_file.c				\
						$(PATH_ELEMENTARY)/freen.c							\
						$(PATH_ELEMENTARY)/put_str_error.c					\
						$(PATH_ELEMENTARY)/get_files_from_directory.c		\
						$(PATH_ELEMENTARY)/freen_array.c					\
						$(PATH_ELEMENTARY)/verif_extension.c				\
						$(PATH_ELEMENTARY)/get_distance.c					\

PATH_ENEMY =			src/entities/enemy

SRC_ENEMY =				$(PATH_ENEMY)/create_enemy.c						\
						$(PATH_ENEMY)/destroy_enemy.c						\
						$(PATH_ENEMY)/load_enemy.c							\
						$(PATH_ENEMY)/fill_enemy.c							\
						$(PATH_ENEMY)/display_enemy.c						\
						$(PATH_ENEMY)/update_enemy.c						\
						$(PATH_ENEMY)/is_dead_enemy.c						\
						$(PATH_ENEMY)/spawn_enemy.c							\
						$(PATH_ENEMY)/init_enemy.c							\
						$(PATH_ENEMY)/enemy_attack_player.c					\
						$(PATH_ENEMY)/player_attack_enemy.c					\
						$(PATH_ENEMY)/move_enemy.c 							\
						$(PATH_ENEMY)/update_healthbar.c					\
						$(PATH_ENEMY)/display_healthbar.c

PATH_CLOCK_DATA =		$(PATH_ELEMENTARY)/clock

SRC_CLOCK =				$(PATH_CLOCK_DATA)/create_clock_data.c				\
						$(PATH_CLOCK_DATA)/destroy_clock_data.c				\
						$(PATH_CLOCK_DATA)/update_clock_data.c				\
						$(PATH_CLOCK_DATA)/drain_clock_data.c				\
						$(PATH_CLOCK_DATA)/set_framerate_clock_data.c		\
						$(PATH_CLOCK_DATA)/init_clock_data.c				\
						$(PATH_CLOCK_DATA)/reset_clock_data.c				\

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

PATH_BACKGROUND = 		src/background

SRC_BACKGROUND = 		$(PATH_BACKGROUND)/init_background.c				\
						$(PATH_BACKGROUND)/init_background_town.c			\
						$(PATH_BACKGROUND)/init_background_forest.c			\

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

PATH_NPC = 				src/npc

SRC_NPC = 				$(PATH_NPC)/init_npc.c 								\
						$(PATH_NPC)/display_npc.c 							\
						$(PATH_NPC)/move_npc.c 								\
						$(PATH_NPC)/update_npc.c 							\

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
						$(PATH_ANIMATOR)/re_set_animator.c					\

PATH_CINEMATIC	=		tests/cinematic

SRC_CINEMATIC_TESTS	=	$(PATH_CINEMATIC)/main_loop.c						\
						$(PATH_CINEMATIC)/events.c							\
						$(PATH_CINEMATIC)/create_sprites.c					\
						$(PATH_CINEMATIC)/display_sprites.c					\
						$(PATH_CINEMATIC)/clock_cinematic.c					\
						$(PATH_CINEMATIC)/clock_cinematic_text.c			\
						$(PATH_CINEMATIC)/create_sprite_skip.c				\
						src/menu/text_zones/handle_texts_zones.c			\
						src/menu/text_zones/display_one_more_char.c			\
						src/menu/text_zones/display_text_zone.c				\

SRC_SOUND_MUSIC	=		src/init_game/init_sound.c							\

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

clean:
			echo $(SRC_ANIMATOR)
			@$(RM) $(OBJ_SRC)
			@$(RM) $(OBJ_TEST)
			@$(MK) -C lib/my/ clean
			@printf "\033[31m[Message]\033[39m Clean libmy reussi !\n"
			@printf "\033[31m[Message]\033[39m Clean %s reussi !\n" $(NAME)

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
