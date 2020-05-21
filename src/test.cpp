#include <ncurses.h>
int main(){
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_YELLOW);
    init_pair(2, COLOR_RED, COLOR_GREEN);
    // bkgd(COLOR_PAIR(1));
    
    
    attron(COLOR_PAIR(2));    
    mvprintw(3, 1, "    ");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    mvprintw(1, 1, "C++ programming");
    mvprintw(2, 1, "Computer Science @ Kookmin Univ.");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    border('*', '*', '*', '*', '*', '*', '*', '*');
    attroff(COLOR_PAIR(2));
    refresh();
    getch();
    endwin();
    return 0;
}