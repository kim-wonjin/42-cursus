/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:19 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:21:19 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "structs.h"
# include "alloc_token.h"
# include "unset.h"

# define STDIN	0
# define STDOUT	1
# define STDERR	2

extern int	g_exit_status;

/*
** =============================================================================
** =============================================================================
*/

void	parse(t_cmd **cmd_list, char *line, char **envp);

/*
** =============================================================================
** =============================================================================
*/

t_cmd	*get_new_node(char *line, int pipe_flag, char **envp, int exit_flag);
char	check_quote(char *line);

/*
** =============================================================================
** =============================================================================
*/

int		exec(t_cmd *cmp_list, char *argv[], char **envp[]);
int		exec_function(t_cmd *cmd_list, char *argv[], char **envp[], int fds[]);

/*
** =============================================================================
** =============================================================================
*/

void	init_nbf(t_nbf *nbf);
int		free_nbf(t_nbf *nbf);
int		check_redirect(t_cmd *cmd_list, int fds[]);
void	exec_child(t_cmd *cmd_list, char *argv[], char **envp[], int fds[]);
int		exec_parents(int pid, int fds[]);

/*
** =============================================================================
** =============================================================================
*/

char	*strjoin_path(char const *s1, char const *s2);
int		check_whitespace(char *line);
void	free_list(t_cmd *cmd_list);

/*
** =============================================================================
** =============================================================================
*/

int		ft_cd(t_cmd *cmd_list);
int		ft_exit(t_cmd *cmd_list);
int		ft_pwd(int fd);
int		ft_echo(t_cmd *cmd_list, int fd);
int		ft_env(t_cmd *cmd_list, char **envp, int fd);
int		ft_export(t_cmd *cmd_list, char ***envp, int fd);

/*
** =============================================================================
** =============================================================================
*/

void	print_errstr(t_cmd *cmd_list);
void	error_write(char *error_str, char *err_cmdline, char *err_cmdline2);
void	print_errstr3(t_cmd *cmd_list);

/*
** =============================================================================
** =============================================================================
*/

char	**copy_envp(char **envs);
int		add_envp(char *cmd, char ***envp);
int		isvalid_export(char *line);
int		cnt_envp_row(char **envp);
char	**sort_env(char **envp);
int		haveequal(char *line);
void	add_key_envp(char ***envp, char *cmd, int keyindex);
void	set_signal(void);

/*
** =============================================================================
** =============================================================================
*/

int		redirect(t_cmd *cmd_list, int *last_index, int *fds[]);
int		redirect_check(t_cmd *cmd_list, int *fds[], int i);
int		check_fd_error(t_cmd *cmd_list, int errorcode, int error_index, int fd);

#endif
