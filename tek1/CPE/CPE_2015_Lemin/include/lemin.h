/*
** lemin.h for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 16:34:22 2016 Anas Buyumad
** Last update Mon Apr 25 17:26:30 2016 Gauthier Cler
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include		<stdbool.h>

#ifndef START
# define START		(1)
#endif

#ifndef END
# define END		(2)
#endif

#ifndef NULL_STR
# define NULL_STR	(3)
#endif

#ifndef START_STRING
# define START_STRING	"##start"
#endif

#ifndef COMMENT_STRING
# define COMMENT_STRING	"#"
#endif

#ifndef END_STRING
# define END_STRING	"##end"
#endif

#ifndef SUCCESS
# define SUCCESS	(0)
#endif

#ifndef ERROR
# define ERROR		(-1)
#endif

#ifndef READ_SIZE
# define READ_SIZE	(4096)
#endif

typedef struct s_list	t_list;
typedef struct s_path	t_path;

struct			s_path
{
  char			*name;
  t_path		*next;
};

struct			s_list
{
  char			*valeur;
  t_list		*next;
};

typedef struct		s_coor
{
  int			x;
  int			y;
}			t_coor;

typedef struct		s_graph
{
  char			*name;
  t_coor		coo;
  int			pos;
  int			capacity;
  char			**links;
  bool			isol;
  bool			visited;
  char			*antecedent;
  int			weight;
}			t_graph;

typedef struct		s_fourmi
{
  char			*node;
}			t_fourmi;

typedef struct		s_lemin
{
  int			nb_ant;
  t_graph		*graph;
  t_list		*list;
  t_fourmi		*fourmis;
  t_path		*path;
}			t_lemin;

/*
** MISC
*/

void			free_array(char **str);
void			my_strncpy(char *, char *, int);
int			my_strlen(char *str);
char			*get_next_line(const int fd);
int			format(int fd, char *str, ...);
int			put_nb(int fd, int nb);
int			put_fd(int fd, char *string);
int			str_len(char *strings);
char			*my_strdup(char *str);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int nb);
int			my_atoi(char *str);
char			*epur_str(char *line);
char			**my_str_to_wordtab(char *);
void			*p_error(char *str);

/*
** PARSING
*/

int			graph_links(t_graph *graph);

int			is_room(char *line);
int			check_links(t_graph *graph);
int			check_list_links(t_graph *graph, t_list *list);
int			is_link(char *line);
int			fill_links(t_graph *graph, t_list *list);
int			fill_graph(t_graph *graph, t_list *list);
int			parsing(t_lemin *lemin);

int			add_liste(t_list **p, char *val);
int			add_fin_liste(t_list **p, char *val);
void			disp_liste(t_list *p);
int			liste_len(t_list *p);

/*
** DIJKSTRA
*/

void			attack(t_lemin *lemin);
int			attack_finished(t_graph *graphs, t_fourmi *fourmis);
int			get_end_index(t_graph *graphs);
int			get_start_index(t_graph *graphs);
int			get_node_index(t_graph *graphs, char *name);
void			evaluate_weights(t_graph *graphs);
void			evaluate_neighbors(t_graph *graphs, t_graph *graph);
int			get_paths(t_lemin *lemin);
t_path			*dijkstra(t_graph *graphs);

/*
** GEN_ANTHILL
*/

int			gen_anthill(t_lemin *lemin);

/*
** CLEAN
*/

void			clean_struct(t_lemin *lemin);
void			free_tab(char **tab);

#endif
