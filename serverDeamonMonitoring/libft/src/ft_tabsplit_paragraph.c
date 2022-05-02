/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:18:36 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/16 11:09:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			tablen(char **s)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i][0] == '\0')
			ret++;
		i++;
	}
	return (ret + 1);
}

static char			**ft_copy(int start, int i, char **s)
{
	char	**ret;
	int		j;

	if ((ret = ft_strstrnew((i - start) + 1)) == NULL)
		return (NULL);
	j = 0;
	while (start < i)
	{
		ret[j] = ft_strdup(s[start]);
		j++;
		start++;
	}
	ret[j] = NULL;
	return (ret);
}

char				***ft_tabsplit_paragraph(char **s)
{
	char	***tab;
	int		i;
	int		j;
	int		start;

	if ((tab = (char ***)malloc(sizeof(char **) * (tablen(s) + 1))) \
			== NULL)
		return (tab);
	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i][0] == '\0')
		{
			tab[j] = ft_copy(start, i, s);
			start = i + 1;
			j++;
		}
		i++;
	}
	tab[j] = ft_copy(start, i, s);
	tab[j + 1] = NULL;
	return (tab);
}
