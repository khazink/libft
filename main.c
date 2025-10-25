#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define OK(msg) printf("[OK]   %s\n", msg)
#define KO(msg) printf("[KO]   %s\n", msg)

static void test_char_functions(void)
{
    printf("\nCHAR / CLASSIFICATION TESTS\n");
    (ft_isalpha('A') ? OK("ft_isalpha('A')") : KO("ft_isalpha('A')"));
    (ft_isdigit('5') ? OK("ft_isdigit('5')") : KO("ft_isdigit('5')"));
    (ft_toupper('a') == 'A' ? OK("ft_toupper('a')") : KO("ft_toupper('a')"));
    (ft_tolower('Z') == 'z' ? OK("ft_tolower('Z')") : KO("ft_tolower('Z')"));
}

static void test_string_search(void)
{
    printf("\nSTRING SEARCH TESTS\n");
    (ft_strlen("Hello") == 5 ? OK("ft_strlen(\"Hello\")") : KO("ft_strlen(\"Hello\")"));

    char *dup = ft_strdup("dup me");
    if (dup && strcmp(dup, "dup me") == 0)
        OK("ft_strdup(\"dup me\")");
    else
        KO("ft_strdup(\"dup me\")");
    free(dup);
}

static void test_memory(void)
{
    printf("\nMEMORY TESTS\n");
    char buf[5] = {1, 2, 3, 4, 5};
    ft_bzero(buf, 5);
    int ok = 1;
    for (int i = 0; i < 5; i++)
        if (buf[i] != 0) ok = 0;
    ok ? OK("ft_bzero") : KO("ft_bzero");
}

static void test_strlcpy_cat(void)
{
    printf("\nSTRLCPY / STRLCAT TESTS\n");
    char src[] = "123456";
    char d1[5] = {0};
    size_t r1 = ft_strlcpy(d1, src, sizeof(d1));
    (r1 == strlen(src) ? OK("ft_strlcpy return") : KO("ft_strlcpy return"));
    (strncmp(d1, "1234", 4) == 0 ? OK("ft_strlcpy contents truncated") : KO("ft_strlcpy contents truncated"));

    char d2[10] = "ABC";
    size_t r2 = ft_strlcat(d2, src, sizeof(d2));
    (r2 == 3 + strlen(src) ? OK("ft_strlcat return") : KO("ft_strlcat return"));
    (strncmp(d2, "ABC1234", 7) == 0 ? OK("ft_strlcat contents") : KO("ft_strlcat contents"));
}

static void test_string_manip(void)
{
    printf("\nSTRING MANIPULATION TESTS\n");
    char *s = ft_substr("Hello", 1, 3);
    (s && strcmp(s, "ell") == 0 ? OK("ft_substr basic") : KO("ft_substr basic"));
    free(s);

    char *j = ft_strjoin("Hello", "World");
    (j && strcmp(j, "HelloWorld") == 0 ? OK("ft_strjoin") : KO("ft_strjoin"));
    free(j);

    char *t = ft_strtrim("  Test  ", " ");
    (t && strcmp(t, "Test") == 0 ? OK("ft_strtrim") : KO("ft_strtrim"));
    free(t);

    char **arr = ft_split("a,b,c", ',');
    if (arr && strcmp(arr[0], "a") == 0 && strcmp(arr[1], "b") == 0 && strcmp(arr[2], "c") == 0)
        OK("ft_split basic");
    else
        KO("ft_split basic");
    for (int i = 0; arr && arr[i]; i++)
        free(arr[i]);
    free(arr);

    char *i1 = ft_itoa(42);
    (strcmp(i1, "42") == 0 ? OK("ft_itoa(42)") : KO("ft_itoa(42)"));
    free(i1);

    char minstr[12];
    char *i2 = ft_itoa(INT_MIN);
    snprintf(minstr, sizeof(minstr), "%d", INT_MIN);
    (strcmp(i2, minstr) == 0 ? OK("ft_itoa(INT_MIN)") : KO("ft_itoa(INT_MIN)"));
    free(i2);
}

static char map_plus_one(unsigned int i, char c)
{
    (void)i;
    return c + 1;
}

static void iter_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

static void test_strmapi_iteri(void)
{
    printf("\nFT_STRMAPI / FT_STRITERI TESTS\n");

    char *mapped = ft_strmapi("ab", map_plus_one);
    (mapped && strcmp(mapped, "bc") == 0 ? OK("ft_strmapi") : KO("ft_strmapi"));
    free(mapped);

    char s[] = "abc";
    ft_striteri(s, iter_upper);
    (strcmp(s, "ABC") == 0 ? OK("ft_striteri") : KO("ft_striteri"));
}

static void test_fd(void)
{
    printf("\nFD OUTPUT TESTS\n");
    int fds[2];
    pipe(fds);
    ft_putstr_fd("OK", fds[1]);
    close(fds[1]);

    char buf[3] = {0};
    read(fds[0], buf, 2);
    close(fds[0]);

    (strcmp(buf, "OK") == 0 ? OK("fd functions wrote something") : KO("fd functions wrote something"));
}

static void test_atoi(void)
{
    printf("\nATOI Tests\n");
    (ft_atoi("0") == 0 ? OK("ft_atoi(\"0\")") : KO("ft_atoi(\"0\")"));
    (ft_atoi("42") == 42 ? OK("ft_atoi(\"42\")") : KO("ft_atoi(\"42\")"));
    (ft_atoi("   -42abc") == -42 ? OK("ft_atoi(\"   -42abc\")") : KO("ft_atoi(\"   -42abc\")"));
}

static void del_fn(void *p)
{
    free(p);
}

static void up_list(void *p)
{
    char *s = (char *)p;
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
}

static void test_list(void)
{
    printf("\nLINKED LIST (BONUS) Tests\n");

    t_list *head = ft_lstnew(ft_strdup("one"));
    t_list *n2 = ft_lstnew(ft_strdup("two"));
    t_list *n3 = ft_lstnew(ft_strdup("three"));

    ft_lstadd_front(&head, n2);
    ft_lstadd_front(&head, n3);

    (ft_lstsize(head) == 3 ? OK("ft_lstsize") : KO("ft_lstsize"));

    t_list *last = ft_lstlast(head);
    (last && strcmp(last->content, "one") == 0 ? OK("ft_lstlast") : KO("ft_lstlast"));

    ft_lstiter(head, up_list);
    (strcmp(head->content, "THREE") == 0 ? OK("ft_lstiter") : KO("ft_lstiter"));

    ft_lstclear(&head, del_fn);
    (head == NULL ? OK("ft_lstclear") : KO("ft_lstclear"));
}

int main(void)
{
    printf("LIBFT COMPREHENSIVE TESTER\n");

    test_char_functions();
    test_string_search();
    test_memory();
    test_strlcpy_cat();
    test_string_manip();
    test_strmapi_iteri();
    test_fd();
    test_atoi();
    test_list();

    printf("\n✅ All tests complete!\n");
    return 0;
}

