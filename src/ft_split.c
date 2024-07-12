#include "../cube.h"

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t	i;
// 	char	*s;
// 	char	*d;

// 	i = 0;
// 	s = (char *) src;
// 	d = (char *) dst;
// 	if (dst == src)
// 		return (dst);
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (d);
// }

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*s;

// 	s = (unsigned char *)b;
// 	while (len--)
// 	{
// 		s[len] = c;
// 	}
// 	return (b);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	if ((size != 0 && count > SIZE_MAX / size))
// 		return (NULL);
// 	ptr = malloc(count * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_memset(ptr, 0, count * size);
// 	return (ptr);
// }

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)str), c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs[i]);
		}
		i++;
	}
	return (strs);
}