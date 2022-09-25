#pragma once

#include "list.h"

#include <ncurses.h>
#include <locale.h>
#include <time.h>

#define MX_RAND ((float)(rand() / (float)RAND_MAX))

//structure that describes a trail
//of characters going down on the screen
//stored in a linked list
typedef int uchar;

typedef struct s_trail {
    uchar *char_seq;
    uchar head;
    int max_len;
    int y_head_pos;
    int x_head_pos;
}              t_trail;

t_trail *mx_new_trail(void);
void mx_update_trails(t_list *list);
void mx_print_trails(t_list *list);
void mx_create_start_trails(t_list *list);
void mx_add_trails(t_list **list, int n);
void mx_free_trails(t_list **list);


uchar *mx_ustrcpy(uchar *dst, const uchar *src);
uchar *mx_ustrdup(const uchar *str);
uchar *mx_ustrjoin(uchar const *s1, uchar const *s2);
int mx_ustrlen(const uchar *s);
uchar *mx_ustrnew(const int size);



