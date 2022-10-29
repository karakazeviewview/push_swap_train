#include "libft.h"
//#include <libc.h>

size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t dst_len;

	if (!dst && src && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	i = 0;
	while (i + dst_len + 1 < dstsize && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (dst_len < dstsize)
		dst[i + dst_len] = '\0';
	if (dst_len > dstsize)
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}

// int main(void)
// {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));
// 	printf("01\n%zu\t%zu\n\n", ft_strlcat(dst1, "", 100), strlcat(dst2, "", 100));
// 	printf("02\n%zu\t%zu\n\n", dst1, dst2);
// 	printf("03\n%zu\t%zu\n\n", ft_strlcat(dst1, "", 100), strlcat(dst2, "", 100));
// 	printf("04\n%s\t%s\n\n", dst1, dst2);
// 	printf("05\n%zu\t%zu\n\n", ft_strlcat(dst1, "wordl", 100));
// 	printf("06\n%zu\t%zu\n\n", dst1, dst2);
// 	char *srd1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	prnitf("07\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 0), strlcat(dst2, src2, 0));
// 	printf("08\n%s\t%s\n\n", dst1, dst2);
// 	printf("09\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 10), strlcat(dst2, src2, 10));
// 	printf("10\n%s\t%s\n\n", dst1, dst2);
// 	printf("11\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 50), strlcat(dst2, src2));
// 	printf("%lu\n", ft_strlcat(NULL, src1, 1));
// 	printf("%lu\n", ft_strlcat(NULL, NULL, 0));
// 	printf("%lu\n", ft_strlcat(NULL, NULL, 1));
// }