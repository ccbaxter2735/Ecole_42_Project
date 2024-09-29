/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:24:32 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/08 15:59:36 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define CMD 0
# define REDIR 1
# define D_REDIR 2
# define PIPE 3
# define TEMP 0
# define PERM 1
# define UNUSED -42

typedef enum e_state
{
	regular_state,
	heredoc_state,
	child_state,
	parent_state,
	restore,
}						t_state;

extern int				g_ret_sig;

typedef enum e_index
{
	env_print,
	p_split_index,
	tab_parse_index,
	unset_index,
	prompt_index,
	env_id,
}						t_index;

typedef enum e_error
{
	malloc_err,
	quote_err,
	syntax_err,
	token_err,
	sig_err,
}						t_error;

// MARK: chained list for heredoc
typedef struct s_here
{
	char				*line;
	struct s_here		*next;
}						t_here;

typedef struct s_parse
{
	int					nature;
	int					way;
	int					pid;
	char				*cmd_arg;
	char				*redirec;
	struct s_parse		*next;
}						t_parse;

typedef struct s_list_gc
{
	void				*addr_obj;
	int					status;
	int					index;
	struct s_list_gc	*next;
}						t_list_gc;

typedef struct s_vars
{
	t_state				prev_state;
	t_state				state;
	char				**env_shell;
	int					env_index;
	int					*pid_pipe;
	int					*fd_dup;
	int					ret_val;
	t_parse				**tab_t_parse;
	t_list_gc			*list_gc;
}						t_vars;

// Thomas
char					*ft_prompt(t_vars *vars);
void					ft_strerror(char *s);
void					msg_error(char *s, char *str);
void					free_array(char **tab);
int						ft_perror(char *s);
void					ft_close(int t_fd[2]);

char					**find_path(char **env, t_vars *vars, char *cmd,
							char **tmp_split);
char					*find_cmd(char *cmd, char **env, t_vars *vars,
							char **tmp_split);
void					ft_err_execve(char **tmp_split, char **env_bis,
							char *cmd);
int						open_file(char *file, int rd_wr, int nature);

int						cmd_exec(char *tmp, char **env, t_vars *vars);
void					cmd_failed(char **tmp_split, char **env_bis,
							int retval);
int						redirect(t_parse *pars);
int						exec_pipe(t_parse *pars, t_vars *vars, int last_fd);
int						exec_multipipe(t_vars *vars, int len);
void					wait_pid(t_vars *vars);
void					ft_fill_pid(int *pid_pipe, int n);
void					add_pid(int pid, int *pid_pipe);

t_here					*t_here_new(char *str);
void					ft_loop_heredoc(t_here *new, t_here *list_heredoc);
int						heredoc(t_parse *pars, t_vars *vars);
char					**heredoc_to_tab(t_here *here);
int						error_heredoc(char *str);
char					*ft_readline_heredoc(char *prompt, t_vars *vars);
char					*init_heredoc(t_here **list_heredoc, t_vars *v);
t_here					*get_last_elem_heredoc(t_here *list_heredoc);
void					print_list_heredoc(t_here *list_heredoc, int fd);
void					free_heredoc(t_here **list_heredoc, t_vars *vars);

t_parse					*append(t_parse *pars);

void					exec_fct(t_parse *pars, t_vars *vars);
void					exec_redir(t_parse *pars, t_vars *vars);
void					exec_function(t_parse *pars, t_vars *vars);
void					exec_minishell(t_parse *pars, t_vars *vars);
int						exec_built_in(t_parse *pars, t_vars *vars, int go);
int						is_built_in(t_parse *pars, t_vars *vars, int go);
void					loop_prompt(t_vars *vars);
void					wait_pid(t_vars *vars);
int						is_built_in(t_parse *pars, t_vars *vars, int go);
void					parent_act(int pid, t_vars *vars);
void					ft_reset(t_vars *vars);

int						ft_tab_len(t_parse **tab_parse);
t_parse					*t_pars_new(int nature, int way, char *redir,
							char *cmd);
void					init_fd(t_vars *vars);
void					restore_fd(t_vars *vars);

// built-in
int						exec_echo(t_parse *pars, int go, t_vars *vars);
int						write_err(char *c, int n, t_vars *vars);
int						exec_pwd(t_parse *pars, t_vars *vars, int go);
int						exec_cd(t_parse *pars, t_vars *vars, int go);
int						ft_cd_err(t_parse *pars, t_vars *vars);
int						exec_env(t_parse *pars, t_vars *vars, int go);
int						exec_export(t_parse *pars, t_vars *vars, int go);
int						exec_unset(t_parse *pars, t_vars *vars, int go);
int						exec_exit(t_parse *pars, t_vars *vars, int go);

// built-in utils
int						exp_cdt(char *str);
char					*erase_quote(char *source);
int						if_other_word(char *s, int j);
int						change_backslash_keys(char c);
int						write_word_annexe1(char *s, int i, t_vars *vars);
int						write_word_annexe2(char *s, int i, t_vars *vars);
void					return_path(char *path, t_vars *vars);

// PJ
void					ft_error_parse(t_error error, t_list_gc *bordel,
							int n_exit);
char					**ft_cpytab(char **tab, t_vars *vars);
int						is_options(char *str);

// garbage
void					*gc_malloc(size_t size, t_vars *vars, int status,
							int index);
void					gc_del(t_list_gc *bordel, int status, int index,
							void *addr);
void					gc_clear(t_list_gc *bordel);
char					*ft_strdup_gc(const char *src, t_vars *vars,
							int info[2], int n);
int						parsing(char *tmp, t_vars *vars);
char					**ft_split_gc(const char *s, char c, t_vars *vars,
							int info[3]);
char					*ft_strjoin_gc(char *s1, char *s2, t_vars *vars,
							int info[2]);
void					print_garbage(t_list_gc *bordel);
char					*ft_itoa_gc(int nb, t_vars *vars, int info[2]);

// env
int						print_env(char **env);
char					**ft_env(char **env, t_vars *vars, char *str,
							int action);
char					**ft_env_del(char **env, char *str, t_vars *vars);
char					**ft_env_add(char **env, char *str, t_vars *vars);
char					*get_env(char *str, t_vars *vars);
void					get_vars_env(t_vars *vars);

// parsing
char					**init_parse(char **env, t_vars *vars);
int						clear_tmp(char *tmp);
int						empty_quotes(char *str);
int						ft_empty_pars(t_parse *pars, t_vars *vars);
int						len_split(char **tab);
int						ft_fill_str(char **p_tab, t_vars *vars);
char					*ft_expand(t_vars *vars, int i[3]);
int						is_var(char c);
void					join_expand(int *x, char *st[4], t_vars *vars,
							int info[2]);
int						ft_build_list(char **p_tab, t_vars *vars);
void					ft_clear_cmd(char *str, int *i, t_vars *vars,
							t_parse **cmd);
int						is_wsp(char c);
int						pick_token(char *str, int x);
int						is_delim(char c, int token);
t_parse					*ft_one_list(char *str, t_vars *vars);
void					ab_parse(t_parse **list, t_parse *new);
int						ft_check(char *str, t_vars *vars, int i);
t_parse					*new_parse(int nature, int way, char *str,
							t_vars *vars);
int						ft_is_token(char *str, int *go_forward, t_vars *vars);
int						ft_tokener(char *str, int *i, t_vars *vars,
							t_parse **list_parse);
int						ft_check_token(const char *str, t_vars *vars);
void					ft_cmd(char *str, int *i, t_vars *vars, t_parse **cmd);
int						quotes(int *quote, char c);
char					**ft_split_parse(const char *s, char c, t_vars *vars,
							int info[6]);
int						ft_empty(const char *str, char c, t_vars *vars);
int						ft_split_check(const char *str, char c, t_vars *vars,
							int *quote);
char					**free_split_gc(char **split);
void					ft_blank(t_vars *vars, t_parse **cmd, int info[2]);
int						ft_init_vars(int *len, int *i, int *x, int info[2]);
char					*ft_spe_char(char *str, int *quote, t_vars *vars);
int						ft_end_split(const char *str, t_vars *vars);
void					ft_init_list(t_vars *vars, int len, int info);
int						print_list(t_vars *vars);
char					*str_token(char *str, t_vars *vars, char *token,
							int *i);
char					**ft_split_wsp(char const *s, int i[2], t_vars *vars);
int						len_tab(char **str);
void					get_x(int *x, char *str);
char					**free_split(char **split);

// signals
int						init_sigs_interact(t_vars *vars);
int						init_sigs_not_interact(t_vars *vars);
int						init_sigs_heredoc(t_vars *vars);
void					ft_restore_sig(t_vars *vars);
int						restore_sig(t_vars *vars);
void					get_ret_value(int status, int save, t_vars *vars);
void					get_ret_val(int *ret_value, t_vars *vars);
void					set_ret_val(t_vars *vars, int value);
void					ft_parent(int pid, t_vars *vars);

#endif