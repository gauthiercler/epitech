##
## Makefile for client in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy
## 
## Made by clement
## Login   <clement.nancelle@epitech.eu>
## 
## Started on  Fri Jun 23 13:07:13 2017 clement
## Last update Sun Jul  2 21:03:10 2017 Valentin Montagne
##

CC		=	gcc

NAME		=	zappy_server

MV		=	mv

CFLAGS		=	-Iincludes/parser -Iincludes -I../lib/cextended/includes -I../lib/cnetwork/includes -Wall -Wextra

SRCS		=	srcs/parser/parser.c					\
                        srcs/parser/arguments/parse_arguments.c			\
                        srcs/parser/arguments/parse_port.c			\
                        srcs/parser/print.c					\
                        srcs/parser/is.c					\
                        srcs/parser/arguments/parse_width.c			\
                        srcs/parser/arguments/parse_height.c			\
                        srcs/parser/arguments/parse_nb_client.c			\
                        srcs/parser/arguments/parse_freq.c			\
                        srcs/parser/arguments/parse_team_names.c		\
                        main.c							\
                        srcs/chrono/new.c					\
                        srcs/chrono/reset.c					\
                        srcs/chrono/time_elapsed.c				\
                        srcs/chrono/destroy.c					\
                        srcs/incantation/new.c					\
                        srcs/parser/parse_stream.c				\
                        srcs/parser/ai/parse_ai.c				\
                        srcs/parser/ai/parse_broadcast.c			\
                        srcs/parser/ai/parse_object.c				\
                        srcs/egg_list/new.c					\
                        srcs/egg_list/size.c					\
                        srcs/egg_list/dump.c					\
                        srcs/egg_list/front.c					\
                        srcs/egg_list/destroy.c					\
                        srcs/egg_list/pop.c					\
                        srcs/egg_list/push.c					\
                        srcs/parser/graphical/parse_graphical.c			\
                        srcs/incantation/tick.c					\
                        srcs/incantation/is_ended.c				\
                        srcs/incantation/validate.c				\
                        srcs/incantation/destroy.c				\
                        srcs/egg/new.c srcs/egg/tick.c				\
                        srcs/egg/is_hatched.c					\
                        srcs/egg/destroy.c					\
                        srcs/inventory/new.c					\
                        srcs/inventory/take_linemate.c				\
                        srcs/inventory/drop_linemate.c				\
                        srcs/inventory/take_deraumere.c				\
                        srcs/inventory/drop_deraumere.c				\
                        srcs/inventory/take_sibur.c				\
                        srcs/inventory/drop_sibur.c				\
                        srcs/inventory/take_mendiane.c				\
                        srcs/inventory/drop_mendiane.c				\
                        srcs/inventory/tale_phiras.c				\
                        srcs/inventory/drop_phiras.c				\
                        srcs/inventory/take_thystame.c				\
                        srcs/inventory/drop_thystame.c				\
                        srcs/inventory/destroy.c				\
                        srcs/map/new.c						\
                        srcs/map/convert.c					\
                        srcs/map/get_tile_by_position.c				\
                        srcs/map/move.c						\
                        srcs/map/take.c						\
                        srcs/map/drop.c						\
                        srcs/map/get_tile_by_player.c				\
                        srcs/map/add_player.c					\
                        srcs/map/remove_player.c				\
                        srcs/map/direction.c					\
                        srcs/map/destroy.c					\
                        srcs/inventory/take_food.c				\
                        srcs/inventory/drop_food.c				\
                        srcs/player/destroy.c					\
                        srcs/player/drop.c					\
                        srcs/player/level_up.c					\
                        srcs/player/move.c					\
                        srcs/player/new.c					\
                        srcs/player/take.c					\
                        srcs/player/tick.c					\
                        srcs/tile/new.c						\
                        srcs/tile/destroy.c					\
                        srcs/tile/add_player.c					\
                        srcs/tile/remove_player.c				\
                        srcs/tile/nb_player.c					\
                        srcs/tile/nb_player_at.c				\
                        srcs/player_list/nb_player_at_level.c			\
                        srcs/player_list/push.c					\
                        srcs/player_list/pop.c					\
                        srcs/tile/add_egg.c					\
                        srcs/tile/remove_egg.c					\
                        srcs/egg_list/pop_egg.c					\
                        srcs/tile/add_ore.c					\
                        srcs/player_list/destroy.c				\
                        srcs/player_list/new.c					\
                        srcs/player_list/size.c					\
                        srcs/server/destroy.c					\
                        srcs/server/new.c					\
                        srcs/server/run.c					\
                        srcs/team_list/new.c					\
                        srcs/team_list/destroy.c				\
                        srcs/team_list/add_team.c				\
                        srcs/team_list/remove_team.c				\
                        srcs/team_list/get_team.c				\
                        srcs/team/new.c						\
                        srcs/team/destroy.c					\
                        srcs/team/nb_at_level.c					\
                        srcs/team/add_player.c					\
                        srcs/team/remove_player.c				\
                        srcs/server/place_ressources.c				\
                        srcs/map/spawn_resources.c				\
                        srcs/tile/spawn.c					\
                        srcs/team/get_name.c					\
                        srcs/graph_client/send_player_position.c		\
                        srcs/graph_client/send_player_lvl.c			\
                        srcs/graph_client/send_player_inventory.c		\
                        srcs/graph_client/send_player_end.c			\
                        srcs/graph_client/send_player_broadcast.c		\
                        srcs/graph_client/send_player_inc.c			\
                        srcs/graph_client/send_player_end_inc.c			\
                        srcs/graph_client/send_egg_spawn.c			\
                        srcs/graph_client/send_player_death.c			\
                        srcs/graph_client/send_egg_open.c			\
                        srcs/graph_client/send_time.c				\
                        srcs/graph_client/send_end_game.c			\
                        srcs/graph_client/send_msg.c				\
                        srcs/graph_client/send_unknown.c			\
                        srcs/graph_client/new.c					\
                        srcs/graph_client/destroy.c				\
                        srcs/graph_client/send_map_size.c			\
                        srcs/graph_client/send_cell_content.c			\
                        srcs/graph_client/send_player_spawn.c			\
                        srcs/server/initialize.c				\
                        srcs/server/generate_map.c				\
                        srcs/tile/remove_ore.c					\
                        srcs/server/listen_ai.c					\
                        srcs/server/listen_gfx.c				\
                        srcs/parser/arguments/print_help.c			\
                        srcs/egg_list/apply.c					\
                        srcs/player_list/apply.c				\
                        srcs/server/generate_tracking.c				\
                        srcs/server/handle_network.c				\
                        srcs/server/compute_timeout.c				\
                        srcs/server/accept_clients.c				\
                        srcs/player/need_write.c				\
                        srcs/server/receive_data.c				\
                        srcs/server/clean_players.c				\
                        srcs/server/send_data.c					\
                        srcs/player/send_network.c				\
                        srcs/player/send.c					\
                        srcs/team_list/apply.c					\
                        srcs/egg_list/empty.c					\
                        srcs/player_list/empty.c				\
                        srcs/team_list/empty.c					\
                        srcs/team_list/dump.c					\
                        srcs/server/handle_connection_queue.c			\
                        srcs/player/disconnect.c				\
                        srcs/server/handle_players.c				\
                        srcs/server/tick.c					\
                        srcs/command_list/apply.c				\
                        srcs/command_list/destroy.c				\
                        srcs/command_list/empty.c				\
                        srcs/command_list/new.c					\
                        srcs/command_list/pop.c					\
                        srcs/command_list/push.c				\
                        srcs/command_list/size.c				\
                        srcs/command/destroy.c					\
                        srcs/command/fill.c					\
                        srcs/command/new.c					\
                        srcs/command_list/first.c				\
                        srcs/command/add_data.c					\
                        srcs/command/exec.c					\
                        srcs/parser/ai/response/response_forward.c		\
                        srcs/player/turn.c					\
                        srcs/parser/ai/response/response_right.c		\
                        srcs/parser/ai/response/response_left.c			\
                        srcs/parser/ai/response/response_look.c			\
                        srcs/tile/to_str.c					\
                        srcs/graph_client_list/new.c				\
                        srcs/graph_client_list/destroy.c			\
                        srcs/graph_client_list/apply.c				\
                        srcs/graph_client_list/empty.c				\
                        srcs/graph_client_list/pop.c				\
                        srcs/graph_client_list/push.c				\
                        srcs/graph_client/send.c				\
                        srcs/graph_client/send_network.c			\
                        srcs/graph_client/need_write.c				\
                        srcs/graph_client/send_map.c				\
                        srcs/parser/ai/response/response_take.c			\
                        srcs/parser/ai/response/response_drop.c			\
                        srcs/parser/ai/response/response_inventory.c		\
                        srcs/parser/ai/response/response_broadcast.c		\
                        srcs/server/clean_gfx.c					\
                        srcs/graph_client_list/new_player.c			\
                        srcs/parser/ai/response/response_unknown.c		\
                        srcs/parser/ai/response/response_fork.c			\
                        srcs/parser/ai/response/response_inc.c			\
                        srcs/parser/ai/response/response_connect_number.c	\
                        srcs/parser/ai/response/response_eject.c		\
                        srcs/team/first_egg.c					\
                        srcs/team/nb_eggs.c					\
                        srcs/team/place_available.c				\
                        srcs/team/pop_egg.c					\
                        srcs/team/push_egg.c					\
                        srcs/parser/arguments/parse_food_rate.c			\
                        srcs/parser/arguments/parse_linemate_rate.c		\
                        srcs/parser/arguments/parse_deraumere_rate.c		\
                        srcs/parser/arguments/parse_sibur_rate.c		\
                        srcs/parser/arguments/parse_mendiane_rate.c		\
                        srcs/parser/arguments/parse_phiras_rate.c		\
                        srcs/parser/arguments/parse_thystame_rate.c		\
                        srcs/parser/arguments/parse_rate.c			\
                        srcs/player/get_cardinal.c				\
                        srcs/server/sync_gfx.c					\
                        srcs/parser/ai/response/check_level.c			\
			srcs/parser/arguments/parse_port_ai.c			\
			srcs/parser/arguments/parse_port_gfx.c			\
			srcs/server/from_egg.c					\
			srcs/parser/tab_to_str.c


OBJS		=	$(SRCS:.c=.o)

RM		=	rm -rf

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

all:	$(NAME)


$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -L../lib/cextended -lcextended -L../lib/cnetwork -lcnetwork -lm
		$(MV) $(NAME) ..

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
