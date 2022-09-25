#include "../inc/header.h"

t_trail *mx_new_trail(void) {
    t_trail *new = malloc(sizeof(t_trail));
    if (new == NULL) return NULL;
    int rand_pos = COLS * MX_RAND;
    int max_len = LINES * MX_RAND;
    int head = 0x30a0 + (0x30ff - 0x30a0) * MX_RAND;
    if (max_len < 3) max_len = 3;
    new->char_seq = mx_ustrnew(max_len);
    new->head = head;
    new->max_len = max_len;
    new->x_head_pos = rand_pos;
    new->y_head_pos = 0;
    return new;
}

void mx_update_trails(t_list *list) {
    for (t_list *tmp = list; tmp != NULL; tmp = tmp->next) {
        t_trail *trail = (t_trail *)tmp->data;
        uchar head_str[2];
        head_str[0] = trail->head;
        head_str[1] = '\0';
        //update trail
        uchar *n_str = mx_ustrjoin(trail->char_seq, head_str);
        free(trail->char_seq);
        trail->char_seq = n_str;
        //if trail has max length - trim exess chars
        if (mx_ustrlen(n_str) > trail->max_len) {
            uchar *tmpstr = mx_ustrdup(n_str + (mx_ustrlen(n_str) - trail->max_len));
            trail->char_seq = tmpstr;
            free(n_str);
        }
        //new head
        trail->head = 0x30a0 + (0x30ff - 0x30a0) * MX_RAND;
        //lower by one pos
        trail->y_head_pos++;
    }
}

void mx_print_trails(t_list *list) {
    erase();
    for (t_list *tmp = list; tmp != NULL; tmp = tmp->next) {
        t_trail *trail = (t_trail *)tmp->data;
        uchar *str = trail->char_seq;
        int len = mx_ustrlen(str);
        int y_cur = trail->y_head_pos - len;
        int x_cur = trail->x_head_pos;
        if (y_cur > LINES) continue;
        
        attron(COLOR_PAIR(1));
        
        for (int i = 0; i < len; i++) {
            attron(COLOR_PAIR(1));
            mvprintw(y_cur + i,x_cur, "%lc", str[i]);
        }

        attroff(COLOR_PAIR(1));
        mvprintw(trail->y_head_pos, x_cur, "%lc", trail->head);
    }
}

void mx_add_trails(t_list **list, int n) {
    for (int i = 0; i < n; i++) {
        mx_push_front(list, mx_new_trail());
    }
}

void mx_free_trails(t_list **list) {
    t_list *nxt;
    for (t_list *tmp = *list; tmp != NULL; tmp = nxt) {
        nxt = tmp->next;
        t_trail *tr = (t_trail *)tmp->data;
        free(tr->char_seq);
        free(tr);
        free(tmp);
    }
    *list = NULL;
}

