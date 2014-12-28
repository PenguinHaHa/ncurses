#include <ncurses.h>
#include <curses.h>

int main(int argc, char* argv[])
{
  initscr();
  cbreak();
  start_color();
  init_pair(1, COLOR_RED, COLOR_GREEN);
  init_pair(2, COLOR_YELLOW, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(1));
  printw("Hello ncurses!\n");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  printw("COLS %d, LINES %d\n", COLS, LINES);
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(3));
  printw("Press any key to start a new key\n");
  attroff(COLOR_PAIR(3));
  refresh();
  getch();
  
  // create a new window  
  WINDOW *new;
  new = newwin(LINES/2, COLS/2, 10, 0);
  wbkgd(new, COLOR_PAIR(1));
  box(new, 0, 0);       // This function draw the edage of this new window
  mvwprintw(new, 5, 0, "This window is new!\n");
  mvwprintw(new, 6, 0, "Please any key to delete this window\n");
  wrefresh(new);
  getch();
  delwin(new);
  touchwin(stdscr);    // this function makes the windows disapear actually
  
  printw("Press any key to exit\n");
  getch();
  endwin();

  return 0;
}
