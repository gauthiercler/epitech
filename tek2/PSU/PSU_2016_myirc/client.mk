##
## Makefile for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/Makefile
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon May 22 11:24:40 2017 Gauthier Cler
## Last update Mon May 22 11:24:40 2017 Gauthier Cler
##

NAME_CLIENT =	client

SRCS_CLIENT +=	src/client/main.c \
				src/client/parser/assess_command.c \
				src/common/error/throw_error.c \
				src/client/run.c \
				src/client/initialize/initialize.c \
				src/client/commands/accept_file.c \
				src/client/commands/change_nickname.c \
				src/client/commands/connect_to_server.c \
				src/client/commands/join_channel.c \
				src/client/commands/leave_channel.c \
				src/client/commands/list_channel_users.c \
				src/client/commands/list_channels.c \
				src/client/commands/list_users.c \
				src/client/commands/private_message.c \
				src/client/commands/channel_message.c \
				src/client/commands/send_file.c \
				src/common/parser/split.c \
				src/client/parser/build_command.c \
				src/client/misc/not_connected_message.c \
				src/client/misc/close_connection.c \
				src/common/misc/array_length.c \
				src/common/misc/write_in_fd.c \
				src/common/socket/connect.c \
				src/common/socket/create.c \
				src/client/watcher/initialize.c \
				src/client/watcher/watch.c \
				src/client/watcher/retrieve_commands.c \
				src/client/watcher/retrieve_command.c \
				src/common/ring_buffer/discard_data.c \
				src/common/ring_buffer/get_free_space.c \
				src/common/ring_buffer/get_input_size.c \
				src/common/ring_buffer/initialize.c \
				src/common/ring_buffer/is_empty.c \
				src/common/ring_buffer/is_full.c \
				src/common/ring_buffer/pop.c \
				src/common/ring_buffer/pop_bytes.c \
				src/common/ring_buffer/push.c \
				src/common/ring_buffer/push_bytes.c \
				src/common/misc/free_ptr.c \
				src/client/parser/parse_response.c \
				src/client/responses/display_response.c \
				src/common/parser/strip_crlf.c \
				src/client/responses/clean_response.c \
				src/client/responses/assess_response.c \
				src/client/responses/ping_response.c \
				src/client/responses/received_message.c \
				src/client/misc/display_time.c \
				src/client/responses/joined_channel.c \
				src/client/responses/leaved_channel.c \
				src/client/channels/add_channel.c \
				src/client/channels/get_max_channel_name.c \
				src/client/channels/remove_channel.c \
				src/client/channels/update_channels_ids.c \
				src/client/responses/changed_username.c \
				src/client/channels/get_max_channel_id.c \
				src/common/misc/is_number.c \
				src/client/misc/change_user.c \
				src/client/responses/welcome_message.c \
				src/client/responses/list_user.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)