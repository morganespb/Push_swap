/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:19:36 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/23 09:38:09 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    print_list(t_list *lst)
{
    int i;
    i = 0;
    while (lst)
    {
        printf("element %d: %s\n", i, (char *)lst->content);
        lst = lst->next;
        i++;
    }
}

void    del_content(void *content)
{
    free(content);
}

void   uppercase_content(void *content)
{
    int i;
    char *str;

    str = (char *)content;
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
}

void    *duplicate_upper(void *content)
{
    char *src;
    char *copy;
    int i;

    src = (char *)content;
    copy = malloc(ft_strlen(src) + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (src[i])
    {
        if (src[i] >= 'a' && src[i] <= 'z')
            copy[i] = src[i] - 32;
        else
            copy[i] = src[i];
        i++;
    }    
    copy[i] = '\0';
    return (copy);
}

int main(void)
{
    t_list *lst;
    t_list *new_element;
    t_list *mapped;

    lst = NULL;
    mapped = NULL;

    printf("---LSTNEW---\n");
    new_element = ft_lstnew(ft_strdup("hello"));
    if (new_element)
        printf("new element: %s\n", (char *)new_element->content);
    
    printf("\n---LSTADDFRONT---\n");
    {
        ft_lstadd_front(&lst, new_element);
        ft_lstadd_front(&lst, ft_lstnew(ft_strdup("world")));
        print_list(lst);
    }
    printf("\n---LSTSIZE---\n");
    printf("size: %d\n", ft_lstsize(lst));

    printf("\n---LSTLAST---\n");
    printf("last content: %s\n", (char *)ft_lstlast(lst)->content);

    printf("\n---LSTITER(uppercase)---\n");
    ft_lstiter(lst, uppercase_content);
    print_list(lst);

    printf("\n---LSTMAP---\n");
    mapped = ft_lstmap(lst, duplicate_upper, del_content);
    print_list(mapped);

    printf("\n---LSTDELONE---\n");
    new_element = ft_lstnew(ft_strdup("DELETE"));
    printf("before: %s\n", (char *)new_element->content);
    ft_lstdelone(new_element, del_content);
    printf("delete done\n");

    printf("\n---LSTCLEAR---\n");
    ft_lstclear(&lst, del_content);
    ft_lstclear(&mapped, del_content);
    printf("lst cleared: %p\n", (void *)lst);
    printf("mapped cleared: %p\n", (void *)mapped);
    return 0;
}
