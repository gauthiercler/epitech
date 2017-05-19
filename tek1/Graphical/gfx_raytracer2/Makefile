##
## Makefile for Makefile in /home/montag_v/rendu/gfx_raytracer2
##
## Made by montag_v
## Login   <montag_v@epitech.net>
##
## Started on  Fri May 20 16:44:15 2016 montag_v
## Last update Sun May 22 15:42:47 2016 Buyumad Anas
##

NAME		=	raytracer2

LIB		=	-L/home/${USER}/.froot/lib/ -llapin 		\
			-L/usr/local/lib		 		\
			-lsfml-audio 					\
			-lsfml-graphics 				\
			-lsfml-window 					\
			-lsfml-system 					\
			-lstdc++ -ldl 					\
			-lm						\
			-lpthread					\
			-D_REENTRANT					\
			-lX11

CFLAGS		+=	-W 						\
			-Wall 						\
			-I/home/${USER}/.froot/include/ 		\
			-Iinclude 					\

SRC		=	srcs/main.c					\
			srcs/misc/full_pix.c				\
			srcs/misc/my_strdup.c				\
			srcs/misc/format.c				\
			srcs/misc/my_atoi.c				\
			srcs/misc/my_atof.c				\
			srcs/misc/put_fd.c				\
			srcs/misc/put_nb.c				\
			srcs/misc/str_len.c				\
			srcs/misc/pixel.c				\
			srcs/misc/get_next_line.c			\
			srcs/misc/my_strcmp.c				\
			srcs/misc/liste.c				\
			srcs/misc/my_str_to_wordtab.c			\
			srcs/misc/my_wordtab.c				\
			srcs/misc/freetab.c				\
			srcs/misc/get_pix.c				\
			srcs/misc/get_color.c				\
			srcs/loading/load_ini.c				\
			srcs/loading/load_coord.c			\
			srcs/loading/load_color.c			\
			srcs/loading/find_scope.c			\
			srcs/loading/load_obj.c				\
			srcs/loading/load_complex_obj.c			\
			srcs/loading/load_lux.c				\
			srcs/loading/load_eye.c				\
			srcs/loading/load_tab_funct.c			\
			srcs/loading/init_obj.c				\
			srcs/loading/load_faces.c			\
			srcs/loading/load_texture.c			\
			srcs/loading/load_mtl.c				\
			srcs/loading/init_trigo.c			\
			srcs/loading/init_data.c			\
			srcs/events/key_handle.c			\
			srcs/threading/init_threads.c			\
			srcs/threading/start_threads.c			\
			srcs/threading/blur_computing.c			\
			srcs/computation/screen_renderer.c		\
			srcs/computation/render_pixel.c			\
			srcs/computation/intersection/intersection.c	\
			srcs/computation/intersection/sphere.c		\
			srcs/computation/intersection/cone.c		\
			srcs/computation/intersection/plane.c		\
			srcs/computation/intersection/cylinder.c	\
			srcs/computation/intersection/polygon.c		\
			srcs/computation/intersection/hit_is_in_range.c	\
			srcs/computation/rays/compute_ray.c		\
			srcs/computation/configure_hitpoint.c		\
			srcs/computation/shadows/compute_shadows.c	\
			srcs/computation/light/compute_light.c		\
			srcs/computation/matrices/get_angle.c		\
			srcs/computation/matrices/rotation_x.c		\
			srcs/computation/matrices/rotation_y.c		\
			srcs/computation/matrices/rotation_z.c		\
			srcs/computation/matrices/rotate_inverse.c	\
			srcs/computation/matrices/mult_matrices.c	\
			srcs/computation/intersection/get_root.c	\
			srcs/computation/intersection/get_simple_root.c	\
			srcs/computation/color/compute_color.c		\
			srcs/computation/texture/texturing.c		\
			srcs/computation/texture/norme.c		\
			srcs/computation/texture/texture.c		\
			srcs/deletion/delete_raytracer.c		\
			srcs/deletion/delete_list.c			\
			srcs/saving/save.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

DEBUG		=	no

OPTI		=	no

ifeq ($(DEBUG), yes)
        CFLAGS  +=      -g
endif

ifeq ($(OPTI), yes)
        LIB  +=      -pg
endif

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(FLAGS) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:		fclean all
