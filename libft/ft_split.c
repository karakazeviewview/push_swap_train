/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:08:42 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:08:43 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ret, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret);
	return (NULL);
}

static char	**make_ret(char const *s, char c, char **ret)
{
	char const	*head;
	char const	*tail;
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			head = s;
			while (*s != c && *s)
				s++;
			tail = s;
			ret[i] = ft_strndup(head, tail - head);
			if (!ret[i])
				return (ft_free(ret, i));
			i++;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

static size_t	word_count(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!ret)
		return (NULL);
	ret = make_ret(s, c, ret);
	return (ret);
}
