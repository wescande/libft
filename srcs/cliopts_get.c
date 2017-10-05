/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 22:14:46 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 16:05:14 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	void *data must be a structure starting with `int flag`
**	to do polymorphism with t_data_template !
*/

#include "libft.h"

static char			**check_required(char ***av, char *arg, int n_args)
{
	char	**ret;
	int		i;
	char	delta;

	delta = 1;
	if (!av || !*av)
		return (NULL);
	if (!n_args)
		return (*av);
	i = -1;
	while (++i < n_args)
		if (arg && *arg && *(arg + 1))
		{
			**av = arg + 1;
			delta = 0;
			arg = NULL;
		}
		else if (!(*av)[i])
			return (NULL);
	ret = *av + delta;
	*av = *av + n_args + delta - 1;
	return (ret);
}

static int			cliopts_map(t_cliopts *map, char ***av,
								char *arg, void *data)
{
	char		**tab_tmp;
	char		**av_tmp;
	char		*tmp;

	av_tmp = *av;
	tmp = **av;
	if (!(tab_tmp = check_required(av, arg, map->arg_required)))
		return (ERR_SET(1, E_CO_MISS, *arg));
	if ((map->get)(tab_tmp, data, map->arg_required))
		return (ERR_SET(1, E_CO_ARG_INV, *arg));
	*av_tmp = tmp;
	return (0);
}

static int			cliopts_parse_short(
		char ***av, t_cliopts opt_map[], void *data)
{
	t_cliopts	*map;
	char		*arg;
	int			i;
	char		*tmp;

	arg = **av + 1;
	i = -1;
	while (arg[++i] && !(tmp = NULL))
	{
		if (!(map = cliopts_getmap_short(opt_map, arg[i])))
			return (ERR_SET(1, E_CO_INV, arg[i]));
		((t_data_template*)data)->flag |= map->flag_on;
		((t_data_template*)data)->flag &= ~map->flag_off;
		if (map->get)
		{
			if (cliopts_map(map, av, arg + i, data))
				return (1);
			if (map->arg_required)
				break ;
		}
	}
	return (++(*av) ? 0 : 0);
}

static int			cliopts_parse_long(
		char ***av, t_cliopts opt_map[], void *data)
{
	t_cliopts	*map;
	char		*arg;
	char		**tab_tmp;

	arg = **av + 2;
	if (!(map = cliopts_getmap_long(opt_map, arg)))
		return (ERR_SET(1, E_CO_INVL, arg));
	((t_data_template*)data)->flag |= map->flag_on;
	((t_data_template*)data)->flag &= ~map->flag_off;
	if (map->get)
	{
		if (!(tab_tmp = check_required(av, NULL, map->arg_required)))
			return (ERR_SET(1, E_CO_MISSL, arg));
		if ((map->get)(tab_tmp, data, map->arg_required))
			return (ERR_SET(1, E_CO_ARG_INVL, arg));
	}
	++(*av);
	return (0);
}

int					cliopts_get(char **av, t_cliopts opt_map[], void *data)
{
	if (!av)
		return (1);
	av++;
	while (av && *av)
	{
		if (ft_strcmp(*av, "-") == 0 || (ft_strcmp(*av, "--") == 0 && av++))
			break ;
		else if ((*av)[0] == '-' && (*av)[1] == '-')
		{
			if (cliopts_parse_long(&av, opt_map, data))
				return (1);
		}
		else if ((*av)[0] == '-')
		{
			if (cliopts_parse_short(&av, opt_map, data))
				return (1);
		}
		else
			break ;
	}
	((t_data_template*)data)->av_data = av;
	return (0);
}
