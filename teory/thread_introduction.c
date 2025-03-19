/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:00:30 by dasalaza          #+#    #+#             */
/*   Updated: 2025/03/19 18:34:28 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h> 

static void *threadFunc(void *arg)
{
    char *s = (char *) arg;
    printf("%s", s);
    return (void *) strlen(s);
}

//int main(int argc, char *argv[])
int main(void)
{
    pthread_t t1;
    void *res;
    int s;

    s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
    if (s != 0)
		printf("err_create\n");
        //errExitEN(s, "pthread_create");

    printf("Message from main()\n");

    s = pthread_join(t1, &res);
    if (s != 0)
		printf("eeror pthread_ join\n");
        //errExitEN(s, "pthread_join");

    printf("Thread returned %ld\n", (long) res);
    printf("Thread returned %s\n", (char *) res);
    exit(EXIT_SUCCESS);
}

