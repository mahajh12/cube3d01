/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:05:29 by malhamel          #+#    #+#             */
/*   Updated: 2023/01/31 14:15:09 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*alt;
	char	str;

	i = 0;
	alt = (char *)s;
	str = (char)c;
	while (alt[i] != '\0')
	{
		if (alt[i] == str)
		{
			return (&alt[i]);
		}
		i++;
	}
	if (c == '\0')
		return (&alt[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(*str));
	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1 [i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
