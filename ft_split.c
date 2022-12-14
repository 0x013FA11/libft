/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:22 by sel-hano          #+#    #+#             */
/*   Updated: 2022/11/13 19:48:26 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

static int	ft_rows_count(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s != c) && (*(s + 1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_strtoken(char *s, char c)
{
	static char	*buffer;
	char		*token;

	if (!buffer)
		buffer = s;
	if (!*buffer)
		return (NULL);
	token = buffer;
	while (*buffer && *buffer != c)
		buffer++;
	while (*buffer && *buffer == c)
	{
		*buffer = '\0';
		buffer++;
	}
	return (token);
}

static void	ft_memclear(char **strs, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	strs = NULL;
}

char	**ft_split(char const *s, char c)
{
	t_split	sp;

	while (*s == c && *s)
		s++;
	sp.rows_count = ft_rows_count((char *)s, c);
	sp.token = ft_strtoken(ft_strdup(s), c);
	sp.ptr = malloc((sp.rows_count + 1) * sizeof(char *));
	if (!sp.ptr || !s) 
		return (free(sp.ptr), NULL);
	sp.i = 0;
	while (sp.token)
	{
		sp.ptr[sp.i] = malloc((ft_strlen(sp.token) + 1) * sizeof(char));
		if (!sp.ptr[sp.i])
			return (ft_memclear(sp.ptr, sp.i), NULL);
		ft_strlcpy(sp.ptr[sp.i], sp.token, ft_strlen(sp.token) + 1);
		sp.token = ft_strtoken(NULL, c);
		sp.i++;
	}
	sp.ptr[sp.i] = NULL;
	return (sp.ptr);
}
// int main ()
// {
// 	char s[] = "      split       this for   me  !       ";
// 	char **sp = ft_split("xxxxxxxxhello!", 120);
// 	int i = 0;
// 	while(sp[i])
// 	{
// 		printf("%s\n",sp[i]);
// 		i++;
// 	}
// 	return 0;
// }