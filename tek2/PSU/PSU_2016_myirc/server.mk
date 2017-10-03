##
## Makefile for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/Makefile
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon May 22 11:24:40 2017 Gauthier Cler
## Last update Mon May 22 11:24:40 2017 Gauthier Cler
##

NAME_SERVER =	server

SRCS_SERVER +=	src/server/main.c \
				src/server/args_handler/display_usage.c \
				src/server/args_handler/handle_args.c \
				src/server/buffer/initialize.c \
				src/server/buffer/pop.c \
				src/server/buffer/push.c \
				src/server/buffer/is_full.c \
				src/server/buffer/is_empty.c \
				src/server/initialize/initialize.c \
				src/server/parser/assess_command.c \
				src/server/parser/retrieve_command.c \
				src/server/run.c \
				src/server/channel_manager/queries/get_channel_by_id.c \
				src/server/channel_manager/queries/get_channel_by_name.c \
				src/server/channel_manager/queries/get_nb_active_channels.c \
				src/server/client_manager/actions/add_channel_to_client.c \
				src/server/client_manager/actions/remove_channel_of_client.c \
				src/server/client_manager/actions/rename_client.c \
				src/server/client_manager/queries/get_client_by_name.c \
				src/server/client_manager/queries/get_nb_connected_clients.c \
				src/server/client_manager/queries/is_connected_to_channel.c \
				src/common/error/throw_error.c \
				src/server/watcher/initialize.c \
				src/server/watcher/retrieve_commands.c \
				src/server/watcher/watch.c \
				src/server/watcher/watch_connections.c \
				src/common/ring_buffer/pop_bytes.c  \
				src/common/ring_buffer/pop.c  \
				src/common/ring_buffer/push_bytes.c  \
				src/common/ring_buffer/push.c  \
				src/common/ring_buffer/is_empty.c \
				src/common/ring_buffer/get_input_size.c \
				src/common/ring_buffer/get_free_space.c \
				src/common/ring_buffer/is_full.c \
				src/common/ring_buffer/initialize.c \
				src/common/ring_buffer/discard_data.c \
				src/common/socket/bind.c \
				src/common/socket/create.c \
				src/common/socket/init.c \
				src/common/socket/listen.c \
				src/server/parser/build_command.c \
				src/server/client_manager/actions/flush_disconnected_clients.c \
				src/server/client_manager/actions/remove_client_by_id.c \
				src/server/client_manager/actions/add_client.c \
				src/server/client_manager/queries/get_available_client_id.c \
				src/server/client_manager/queries/get_max_client_id.c \
				src/server/client_manager/queries/get_client_by_id.c \
				src/common/parser/strip_crlf.c \
				src/common/parser/split.c \
				src/common/parser/count_indexes.c \
				src/server/parser/dump_command.c \
				src/server/client_manager/actions/dump_client.c \
				src/server/client_manager/actions/flush_clients_buffers.c \
				src/server/engine/process_commands.c \
				src/server/engine/run_command.c \
				src/server/engine/commands/quit.c \
				src/server/engine/commands/set_nickname.c \
				src/server/engine/commands/register_user.c \
				src/server/engine/commands/list_channels.c \
				src/server/engine/commands/join_channel.c \
				src/server/engine/commands/leave_channel.c \
				src/server/engine/commands/list_users.c \
				src/server/engine/commands/list_channel_users.c \
				src/server/engine/commands/send_message.c \
				src/server/engine/commands/send_file.c \
				src/server/engine/commands/accept_file.c \
				src/server/engine/commands/invalid_command.c \
				src/common/misc/write_in_fd.c \
				src/server/channel_manager/queries/get_available_channel_id.c \
				src/server/channel_manager/queries/get_max_channel_id.c \
				src/server/engine/responses/messages/error_cannot_send_to_channel.c \
				src/server/engine/responses/messages/error_no_such_nick.c \
				src/server/engine/responses/messages/error_no_recipient.c \
				src/server/engine/responses/messages/error_no_text_to_send.c \
				src/server/engine/responses/nick/error_erroneus_nickname.c \
				src/server/engine/responses/nick/error_no_nickname_given.c \
				src/server/engine/responses/nick/error_nickname_in_use.c \
				src/server/engine/responses/common/error_need_more_params.c \
				src/server/engine/responses/registration/welcome_user.c \
				src/server/engine/responses/channel/list_start.c \
				src/server/engine/responses/channel/list_channel.c \
				src/server/engine/responses/channel/list_end.c \
				src/server/engine/responses/users/list_start.c \
				src/server/engine/responses/channel/error_no_such_channel.c \
				src/server/engine/responses/channel/join_broadcast.c \
				src/server/engine/responses/channel/error_not_on_channel.c \
				src/server/engine/responses/channel/part_broadcast.c \
				src/server/engine/responses/users/no_users.c \
				src/server/engine/responses/users/list_users.c \
				src/server/engine/responses/users/list_end.c \
				src/server/engine/responses/join/error_too_many_channels.c \
				src/server/channel_manager/actions/create_channel.c \
				src/server/engine/responses/names/names_end.c \
				src/server/engine/responses/names/names_list.c \
				src/server/engine/responses/registration/error_already_registered.c \
				src/server/engine/responses/registration/error_not_registered.c \
				src/server/client_manager/queries/get_nb_connected_on_channel.c \
				src/server/channel_manager/actions/remove_channel_by_id.c \
				src/server/channel_manager/actions/remove_channel_by_name.c \
				src/server/engine/responses/nick/rename_user.c \
				src/common/misc/is_number.c \
				src/common/misc/free_array.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

$(OBJS_SERVER): %.o : %.c
	$(CC) -c $(CFLAGS) -DSERVER_C $< -o $@

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)