#include <ncurses.h>
#include <stdio.h>
#define MINDELAY 10
#define MAXDELAY 500
#define DEFAULTDELAY 100
#define ROWS 25
#define COLS 80

void ncursess(void);
void end_ncurses(void);
void init_field(int r, int c, int field[r][c]);
void copy_field(int r, int c, int src[r][c], int dst[r][c]);
int cnt_neighbors(int r, int c, int f[r][c], int x, int y);
void next_generation(int cur[ROWS][COLS], int nxt[ROWS][COLS]);
void draw_field(int r, int c, int f[r][c]);
int read_pairs(int field[ROWS][COLS], int first_x, int first_y);
int read_matrix(int field[ROWS][COLS], int first_row[COLS]);
int parse_line(char *line, int nums[COLS], int *count);
int read_auto(int field[ROWS][COLS]);
int handle_input(int delay, int *exit_flag);
void game_loop(int field[ROWS][COLS]);

int main(void) {
    int field[ROWS][COLS];
    int result = 0;
    init_field(ROWS, COLS, field);
    result = read_auto(field);
    if (result == 0) {
        ncursess();
        game_loop(field);
        end_ncurses();
    } else {
        printf("n/a");
    }
    return 0;
}
void ncursess(void) {
    FILE *tty = fopen("/dev/tty", "r");
    if (tty) {
        freopen("/dev/tty", "r", stdin);
        fclose(tty);
    }
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    keypad(stdscr, 1);
    nodelay(stdscr, 1);
}
void end_ncurses(void) { endwin(); }
void init_field(int r, int c, int field[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) field[i][j] = 0;
}
void copy_field(int r, int c, int src[r][c], int dst[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) dst[i][j] = src[i][j];
}
int cnt_neighbors(int r, int c, int f[r][c], int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
        for (int dx = -1; dx <= 1; dx++)
            if (dx != 0 || dy != 0) {
                int nx = (x + dx + c) % c;
                int ny = (y + dy + r) % r;
                if (f[ny][nx] == 1) count++;
            }
    return count;
}
void next_generation(int cur[ROWS][COLS], int nxt[ROWS][COLS]) {
    for (int y = 0; y < ROWS; y++)
        for (int x = 0; x < COLS; x++) {
            int n = cnt_neighbors(ROWS, COLS, cur, x, y);
            if (cur[y][x] == 1)
                nxt[y][x] = (n == 2 || n == 3);
            else
                nxt[y][x] = (n == 3);
        }
}
void draw_field(int r, int c, int f[r][c]) {
    for (int y = 0; y < r; y++)
        for (int x = 0; x < c; x++) {
            if (f[y][x] == 1) {
                attron(COLOR_PAIR(1));
                mvprintw(y, x, "X");
                attroff(COLOR_PAIR(1));
            } else {
                mvprintw(y, x, " ");
            }
        }
    refresh();
}
int read_pairs(int field[ROWS][COLS], int first_x, int first_y) {
    int result = 0;
    int x = first_x;
    int y = first_y;
    int reading = 1;
    while (reading == 1) {
        if (x == -1 && y == -1) {
            reading = 0;
        } else if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
            result = 1;
            reading = 0;
        } else {
            field[y][x] = 1;
            if (scanf("%d %d", &x, &y) != 2) reading = 0;
        }
    }
    return result;
}
int read_matrix(int field[ROWS][COLS], int first_row[COLS]) {
    int result = 0;
    for (int x = 0; x < COLS; x++) field[0][x] = first_row[x];
    int y = 1;
    int ok = 1;
    while (y < ROWS && ok == 1) {
        int x = 0;
        while (x < COLS && ok == 1) {
            if (scanf("%d", &field[y][x]) != 1) {
                result = 1;
                ok = 0;
            }
            x++;
        }
        y++;
    }
    return result;
}
int parse_line(char *line, int nums[COLS], int *count) {
    int result = 0;
    char *p = line;
    int parsing = 1;
    while (parsing == 1 && *p != '\0' && *p != '\n') {
        while (*p == ' ') p++;
        if (*p == '\0' || *p == '\n') {
            parsing = 0;
        } else {
            int val, n;
            if (sscanf(p, "%d%n", &val, &n) == 1) {
                nums[*count] = val;
                (*count)++;
                p += n;
            } else {
                result = 1;
                parsing = 0;
            }
        }
    }
    return result;
}
int read_auto(int field[ROWS][COLS]) {
    char line[2048];
    int nums[COLS];
    int count = 0;
    int result = 0;
    if (fgets(line, sizeof(line), stdin)) {
        result = parse_line(line, nums, &count);
        if (result == 0) {
            if (count == 2) {
                result = read_pairs(field, nums[0], nums[1]);
            } else if (count == COLS) {
                result = read_matrix(field, nums);
            } else {
                result = 1;
            }
        }
    } else {
        result = 1;
    }
    return result;
}
int handle_input(int delay, int *exit_flag) {
    int ch = getch();
    if (ch == ' ') {
        *exit_flag = 1;
    } else if (ch == 'a' || ch == 'A') {
        delay -= 10;
        if (delay < MINDELAY) delay = MINDELAY;
    } else if (ch == 'z' || ch == 'Z') {
        delay += 10;
        if (delay > MAXDELAY) delay = MAXDELAY;
    }
    return delay;
}
void game_loop(int field[ROWS][COLS]) {
    int current[ROWS][COLS];
    int next[ROWS][COLS];
    int delay = DEFAULTDELAY;
    int exit_flag = 0;
    init_field(ROWS, COLS, current);
    init_field(ROWS, COLS, next);
    copy_field(ROWS, COLS, field, current);
    while (exit_flag == 0) {
        clear();
        draw_field(ROWS, COLS, current);
        delay = handle_input(delay, &exit_flag);
        if (exit_flag == 0) {
            next_generation(current, next);
            copy_field(ROWS, COLS, next, current);
            napms(delay);
        }
    }
}
