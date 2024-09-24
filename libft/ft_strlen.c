/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:58:26 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/04/17 11:04:21 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s ++;
		len ++;
	}
	return (len);
}
/*
int	main (void)
{
	const char	*src;

	src = "Hello World!";
	printf("%i\n", ft_strlen (src));
	return (0);
}
*/