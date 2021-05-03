/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:31:34 by abarot            #+#    #+#             */
/*   Updated: 2021/05/03 16:06:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE	15
# define RESET   		"\033[0m"
# define BLACK   		"\033[30m"
# define RED     		"\033[31m"
# define GREEN   		"\033[32m"
# define YELLOW  		"\033[33m"
# define BLUE    		"\033[34m"
# define MAGENTA 		"\033[35m"
# define CYAN    		"\033[36m"
# define WHITE   		"\033[37m"
# define BOLDBLACK   	"\033[1m\033[30m"
# define BOLDRED     	"\033[1m\033[31m"
# define BOLDGREEN   	"\033[1m\033[32m"
# define BOLDYELLOW  	"\033[1m\033[33m"
# define BOLDBLUE    	"\033[1m\033[34m"
# define BOLDMAGENTA 	"\033[1m\033[35m"
# define BOLDCYAN    	"\033[1m\033[36m"
# define BOLDWHITE   	"\033[1m\033[37m"

int			ft_atoi(const char *s);
long		ft_atol(const char *s);
char		*ft_itoa(int n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t num, size_t size);
int			ft_isdigit(int c);
int			ft_is_space(int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_replace_in_str(char *o_str, char *to_replace, char *elt);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
char		*ft_remove_in_str(char *str, char *char_set);
int			ft_is_char_in_set(char c, char *char_set);
int			ft_count_line(char **map);
int			ft_isft_str(char *str, int (*f)(int));
int			ft_get_sign(const char *s, int *sign);
void		ft_swap(int *a, int *b);
void		ft_clear_map(char **map);
void		ft_sort_array(int *array, int size);
#endif
