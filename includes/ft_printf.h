/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:42:53 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 12:07:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

# define ABS(x) ((x < 0) ? (-x) : x)
# define CASTVA_ARG(valist, cast) ((cast)va_arg(valist, cast))

# define DEF			"\033[00m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

# define INV			"\033[07m"

# define BG_BLACK		"\033[40m"
# define BG_RED			"\033[41m"
# define BG_GREEN		"\033[42m"
# define BG_YELLOW		"\033[43m"
# define BG_BLUE		"\033[44m"
# define BG_PURPLE		"\033[45m"
# define BG_CYAN		"\033[46m"
# define BG_WHITE		"\033[47m"
# define BG_DEFAULT		"\033[49m"

typedef struct		s_conv
{
	char					*str;
	int						len;
	short int				index_conv;
	unsigned long long int	num;
	long double				dbl;
	int						base;
	int						is_neg;
	int						sha;
	int						spa;
	int						left;
	int						sign;
	int						is_long_long;
	int						is_short;
	int						is_long;
	int						is_char;
	short int				width;
	short int				acc;
	char					pad;
	char					spec;
}					t_conv;

enum				e_fun_conv
{
	s = 0,
	b_s,
	p,
	d,
	b_d,
	i,
	o,
	b_o,
	u,
	b_u,
	x,
	b_x,
	c,
	b_c,
	b,
	b_b,
	e,
	b_e,
	f,
	b_f,
	g,
	b_g,
	a,
	b_a,
	n,
	n_fun
};

typedef struct s_wrk	t_wrk;

struct				s_wrk
{
	char			*buf;
	char			*ans;
	int				len;
	int				curlen;
	void			(*fun[n_fun + 1])(t_wrk *w, t_conv *tmp, va_list ap);
};

void				printf_core(t_wrk *w, va_list ap);

void				ft_colorize(t_wrk *w);
void				ft_resolve_conv(t_wrk *w, t_conv *tmp);
void				ft_set_flag(t_conv *tmp, char **end, va_list ap);
void				initialize_work(const char *str, t_wrk *w);

void				add_s(t_conv *tmp, char *in);
void				add_i(t_conv *tmp);
void				add_f(t_conv *tmp);
void				add_e(t_conv *tmp);

void				fill_c(char **str, t_conv *tmp, short int len);
void				fill_numbers(t_conv *tmp, short int len);
void				fill_numbers_left(t_conv *tmp, short int len);

/*
** STANDARDS
*/
void				conv_s(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_s(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_p(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_i(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_d(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_o(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_o(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_u(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_u(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_x(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_x(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_c(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_c(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_unknow(t_wrk *w, t_conv *tmp, va_list ap);
/*
** BINAIRE
*/
void				conv_b(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_b(t_wrk *w, t_conv *tmp, va_list ap);
/*
** DOUBLES
*/
void				conv_e(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_e(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_f(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_f(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_g(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_g(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_a(t_wrk *w, t_conv *tmp, va_list ap);
void				conv_b_a(t_wrk *w, t_conv *tmp, va_list ap);
/*
** N
*/
void				conv_n(t_wrk *w, t_conv *tmp, va_list ap);
#endif
