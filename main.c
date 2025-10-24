#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Helper function for ft_strmapi */
char incr_char(unsigned int i, char c)
{
    (void)i;
    return c + 1;
}

/* Helper function for ft_striteri */
void iter_func(unsigned int i, char *c)
{
    *c += 1;
    (void)i;
}

int main(void)
{
    printf("=== FT_STRLEN ===\n");
    printf("Normal: %zu\n", ft_strlen("Hello"));
    printf("Empty string: %zu\n", ft_strlen(""));

    printf("\n=== FT_IS* ===\n");
    printf("isalpha('a'): %d\n", ft_isalpha('a'));
    printf("isdigit('5'): %d\n", ft_isdigit('5'));
    printf("isalnum('!'): %d\n", ft_isalnum('!'));
    printf("isascii(128): %d\n", ft_isascii(128));
    printf("isprint('\\0'): %d\n", ft_isprint('\0'));

    printf("\n=== FT_TOUPPER / FT_TOLOWER ===\n");
    printf("toupper('a'): %c\n", ft_toupper('a'));
    printf("toupper('Z'): %c\n", ft_toupper('Z'));
    printf("tolower('A'): %c\n", ft_tolower('A'));
    printf("tolower('z'): %c\n", ft_tolower('z'));

    printf("\n=== FT_STRNCMP ===\n");
    printf("cmp equal: %d\n", ft_strncmp("abc", "abc", 3));
    printf("cmp partial: %d\n", ft_strncmp("abc", "abd", 3));
    printf("cmp empty: %d\n", ft_strncmp("", "", 1));

    printf("\n=== FT_MEMSET / FT_BZERO / FT_MEMCPY / FT_MEMMOVE ===\n");
    char buf[10];
    ft_memset(buf, 'X', 10);
    printf("memset: %.10s\n", buf);

    ft_bzero(buf, 10);
    printf("bzero: ");
    for(int i = 0; i < 10; i++) printf("%d ", buf[i]);
    printf("\n");

    char src[] = "12345";
    char dest[6];
    ft_memcpy(dest, src, 6);
    printf("memcpy: %s\n", dest);

    char overlap[] = "ABCDE";
    ft_memmove(overlap+1, overlap, 4);
    overlap[5] = '\0';
    printf("memmove overlapping: %s\n", overlap);

    printf("\n=== FT_STRDUP ===\n");
    char *dup = ft_strdup("Test");
    printf("dup normal: %s\n", dup);
    free(dup);

    dup = ft_strdup("");
    printf("dup empty: %s\n", dup);
    free(dup);

    dup = ft_strdup(NULL);
    printf("dup NULL: %p\n", dup);

    printf("\n=== FT_SUBSTR ===\n");
    char *sub = ft_substr("Hello", 1, 3);
    printf("substr normal: %s\n", sub);
    free(sub);

    sub = ft_substr(NULL, 0, 5);
    printf("substr NULL: %p\n", sub);

    sub = ft_substr("Hi", 10, 5);
    printf("substr out of bounds: %s\n", sub);
    free(sub);

    printf("\n=== FT_STRJOIN ===\n");
    char *join = ft_strjoin("Hello", "World");
    printf("join normal: %s\n", join);
    free(join);

    join = ft_strjoin(NULL, "World");
    printf("join NULL left: %s\n", join);
    free(join);

    join = ft_strjoin("Hello", NULL);
    printf("join NULL right: %s\n", join);
    free(join);

    join = ft_strjoin(NULL, NULL);
    printf("join both NULL: %p\n", join);
    free(join);

    printf("\n=== FT_STRTRIM ===\n");
    char *trim = ft_strtrim("  abc  ", " ");
    printf("trim normal: '%s'\n", trim);
    free(trim);

    trim = ft_strtrim(NULL, " ");
    printf("trim NULL s1: %p\n", trim);

    trim = ft_strtrim("abc", NULL);
    printf("trim NULL set: '%s'\n", trim);
    free(trim);

    trim = ft_strtrim("", " ");
    printf("trim empty string: '%s'\n", trim);
    free(trim);

    trim = ft_strtrim("aaa", "a");
    printf("trim full chars removed: '%s'\n", trim);
    free(trim);

    printf("\n=== FT_ITOA ===\n");
    char *num = ft_itoa(0);
    printf("itoa 0: %s\n", num);
    free(num);

    num = ft_itoa(INT_MAX);
    printf("itoa INT_MAX: %s\n", num);
    free(num);

    num = ft_itoa(INT_MIN);
    printf("itoa INT_MIN: %s\n", num);
    free(num);

    printf("\n=== FT_SPLIT ===\n");
    char **split = ft_split("a,b,,c,", ',');
    printf("split commas and empty: \n");
    for(int i=0; split[i]; i++) { printf("[%s]\n", split[i]); free(split[i]); }
    free(split);

    split = ft_split(NULL, ',');
    printf("split NULL: %p\n", split);

    split = ft_split("", ',');
    printf("split empty string: \n");
    for(int i=0; split[i]; i++) { printf("[%s]\n", split[i]); free(split[i]); }
    free(split);

    printf("\n=== FT_STRMAPI ===\n");
    char *mapi = ft_strmapi("abcd", incr_char);
    printf("strmapi normal: %s\n", mapi);
    free(mapi);

    mapi = ft_strmapi(NULL, incr_char);
    printf("strmapi NULL string: %p\n", mapi);

    printf("\n=== FT_STRITERI ===\n");
    char str_iter[] = "abcd";
    ft_striteri(str_iter, iter_func);
    printf("striteri normal: %s\n", str_iter);

    ft_striteri(NULL, iter_func); // should not crash

    printf("\n=== FT_PUT*FD ===\n");
    ft_putchar_fd('A', 1);
    ft_putstr_fd("BC", 1);
    ft_putendl_fd("D", 1);
    ft_putnbr_fd(123, 1);
    ft_putnbr_fd(-456, 1);
    printf("\n");

    return 0;
}

