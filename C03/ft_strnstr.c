/* compute_lps.c
 * Fill lps[0..m-1] for pattern `pat` of length m.
 *
 * Precondition:
 * - pat is a pointer to m bytes (not necessarily '\0' terminated if you pass length explicitly)
 * - lps points to an int array of length at least m (caller allocates)
 *
 * Behavior:
 * - If m == 0: nothing is written.
 * - Complexity: O(m)
 **/

#include <stddef.h> /* for size_t */

void	compute_lps(const char *pat, int m, int *lps)
{
	int	len; /* length of the previous longest prefix suffix */
	int	i;

	len = 0;
	if (m <= 0)
		return ;
	lps[0] = 0; /* lps[0] is always 0 */
	i = 1;
	while (i < m)
	{
		/* cast to unsigned char for safety if pat may contain negative char values */
		if ((unsigned char)pat[i] == (unsigned char)pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				/* fallback to the previous longest prefix */
				len = lps[len - 1];
				/* note: do NOT increment i here */
			}
			else
			{
				/* no prefix matches */
				lps[i] = 0;
				i++;
			}
		}
	}
}

/* ft_strnstr: haystack/needle are const, return char* to match or NULL */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		*lps = NULL;
	int		m;              /* needle length */
	size_t	n;           /* effective haystack length considered (<= len) */
	size_t	i;           /* index over haystack */
	int		j;              /* index over needle */

	/* Defensive parameter check */
	if (haystack == NULL || needle == NULL)
		return (NULL);
	/* Empty needle matches at start */
	if (needle[0] == '\0')
		return ((char *)haystack);
	/* Compute lengths */
	m = (int)ft_strlen(needle);
	if (m == 0) /* redundant with previous check but safe */
		return ((char *)haystack);
	/* If needle length > len, it cannot fit within first len bytes */
	if ((size_t)m > len)
		return (NULL);
	/* Determine how many haystack bytes we can actually examine (stop at '\0' or len) */
	n = 0;
	while (n < len && haystack[n] != '\0')
		n++;
	/* If haystack portion shorter than needle, impossible to match */
	if (n < (size_t)m)
		return (NULL);
	/* Allocate lps table (caller frees? we free here) */
	lps = (int *)malloc(sizeof(int) * (size_t)m);
	if (lps == NULL)
		return (NULL); /* allocation failure -> defensive NULL */
	compute_lps(needle, m, lps);
	/* KMP search over haystack[0..n-1] and needle[0..m-1] */
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((unsigned char)haystack[i] == (unsigned char)needle[j])
		{
			i++;
			j++;
			if (j == m)
			{
				/* match found at i - j */
				res = (char *)(haystack + i - j);
				free(lps);
				return (res);
			}
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
				/* do not increment i here */
			}
			else
			{
				i++;
			}
		}
	}
	free(lps);
	return (NULL);
}
