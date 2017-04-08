/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 21:53:12 by wescande          #+#    #+#             */
/*   Updated: 2017/04/08 21:05:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define STDIN			STDIN_FILENO
# define STDOUT			STDOUT_FILENO
# define STDERR			STDERR_FILENO

# define PIPE_READ		0
# define PIPE_WRITE		1

# ifndef DG
#  define MSG0			"{BLU}%s, {CYA}%s, {GRE}%4d - {eoc}{red}"
#  define MSG1			__FILE__, __func__, __LINE__
#  define DG(f, ...)	ft_dprintf(2, MSG0 f "{eoc}\n", MSG1, ##__VA_ARGS__)
# endif

enum			e_bool
{
	false,
	true
};

typedef struct	s_ld
{
	void			*content;
	struct s_ld		*next;
	struct s_ld		*prev;
}				t_ld;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** CLIOPTS
*/

typedef struct	s_cliopts
{
	char		c;
	char		*str;
	long int	flag_on;
	long int	flag_off;
	int			(*get)();
	int			arg_required:1;
}				t_cliopts;

typedef struct	s_data_template
{
	long int	flag;
	char		**av_data;
}				t_data_template;

int				cliopts_get(char **av, t_cliopts opt_map[], void *data);
t_cliopts		*cliopts_getmap_long(t_cliopts opt_map[], char *arg);
t_cliopts		*cliopts_getmap_short(t_cliopts opt_map[], char arg);

/*
** ERROR
*/

# define ERRMSG_MAX_SIZE	150
# define ERR_PROTO(u, m)	"{red}%s: %s{eoc}\n", u, m
# define ERR_MSG(u, m)		ft_dprintf(2, ERR_PROTO(u, m))
# define ERR_SET(n, ...)	error_set(n, ##__VA_ARGS__)

enum	e_errors
{
	E_NOERR,
	E_CO_INV,
	E_CO_INVL,
	E_CO_MULT,
	E_CO_MISS,
	E_CO_MISSL,
	E_SYS_NOFILE,
	E_SYS_ISDIR,
	E_SYS_NOPERM,
	E_MAX,
};

int				error_set(int n, ...);
int				ft_perror(char *utility);

size_t			ft_strlen(const char *s);
size_t			ft_strlenchr(const char *s, char c);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *big, const char *little,
							size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strisdigit(const char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isspa(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
char			*ft_strtoupper(char *str);
int				ft_tolower(int c);

char			*ft_strnew(size_t size);
char			*ft_strnewc(size_t size, int c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplitspa(char const *str);
void			ft_tabdel(char ***mytab);
int				ft_tablen(char **mytab);

int				get_next_line(const int fd, char **line);

char			*ft_strjoinf(char *s1, char *s2, int state);
char			*ft_strsubf(char *s, unsigned int top, size_t l, short int mod);
void			*ft_memrealloc(void *ptr, size_t old_s, size_t new_s);

/*
** OUTPUT :
*/
int				ft_putchar(int c);
int				ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_tabprint(char **mytab);
void			ft_tabprint_fd(char **mytab, int fd);

/*
** LIST :
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *lnew);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstfree(t_list **alst);
t_list			*ft_lstreverse(t_list **lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstswap(t_list *l_cur);
void			ft_lstsort(t_list **begin_list, int (*cmp)());
/*
** LIST D:
*/
void			ft_ld_new(t_ld **alst, void *content);
t_ld			*ft_ld_front(t_ld	*ld);
void			ft_ld_pushfront(t_ld **alst, void *content);
void			ft_ld_pushback(t_ld **alst, void *content);
size_t			ft_ld_size(t_ld *ld);
void			ft_ld_del(t_ld **ld, void (*del)());
void			ft_ld_clear(t_ld **ld, void (*del)());
void			ft_ld_reverse(t_ld **lst);
t_ld			*ft_ld_back(t_ld *ld);
t_ld			*ft_ld_swap(t_ld *l_cur);
char			**ft_ld_to_tab(t_ld *ld);

/*
** WCHAR_T :
*/
size_t			ft_strwlen(const wchar_t *wstr);
short int		ft_charwlen(const wchar_t cw);
char			*ft_charwtochar(char *str, const wchar_t cw);
char			*ft_charwtonewchar(const wchar_t cw);
char			*ft_strwtostr(char *dest, const wchar_t *strw);
char			*ft_strwtonewstr(const wchar_t *strw);

/*
** MEM :
*/
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memjoin(const void *mem1, const void *mem2,
							size_t len1, size_t len2);
void			*ft_memjoinf(void *mem1, void *mem2, size_t len1, size_t len2);
void			ft_swapptr(void **ptr1, void **ptr2);

/*
** INT :
*/
long long int	ft_pow(int nb, int power);
long			ft_min(long n1, long n2);
long			ft_max(long n1, long n2);
short int		ft_num_len_base(long int num, short int len_base);
short int		ft_unum_len_base(unsigned long int num, short int len_base);
long int		ft_abs(long int num);
int				ft_atoi(const char *nptr);
long int		ft_atoli_base(const char *nptr, short len);
char			*ft_itoa(int n);
char			*ft_ftoa(long double n, short prec);
char			*ft_ftoa_base(long double n, short prec, short bas, int is_up);
char			*ft_litoa(long int n);
char			*ft_litoa_base(long int n, short int len_base, int is_maj);
char			*ft_ulitoa(unsigned long int n);
char			*ft_ulitoa_base(unsigned long int n, short int len_base,
								int is_maj);

/*
** PRINTF :
*/
int				ft_printf(const char *str, ...);
int				ft_asprintf(char **ret, const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_vdprintf(int fd, const char *str, va_list ap);
int				ft_vasprintf(char **ret, const char *str, va_list ap);

/*
** SYS :
*/
char	*ft_getenv(char **env, const char *key);

#endif
