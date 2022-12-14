/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:59:39 by sel-hano          #+#    #+#             */
/*   Updated: 2022/11/13 19:59:42 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	strlen;

	if (dstsize)
		strlen = ft_strlen(dst);
	if (dst && dstsize)
		if (dstsize > strlen)
			return (strlen + ft_strlcpy(dst + strlen, src, dstsize - strlen));
	return (dstsize + ft_strlen(src));
}
