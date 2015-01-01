#include <ncurses.h>
#include <curses.h>

int main(int argc, char* argv[])
{
  int i = 0;

  initscr();
  
  if(has_colors() == FALSE)
  {
    printw("No Color\n");
    printw("Press any key to exit..\n");
    refresh();
    getch();
    endwin();
  }
  start_color();

  init_pair(1, COLOR_YELLOW, COLOR_BLUE);


  printw("This is main windows, press any key to start a new one\n");
  getch();

  WINDOW *new;
  new = newwin(10, 40, 10, 10);
  scrollok(new, TRUE);
  idlok(new, TRUE);
//  box(new, '*', '*');
  box(new, 0, 0);
  wsetscrreg(new, 1, 8);

//  wattrset(new, COLOR_PAIR(1));
  wbkgd(new, COLOR_PAIR(1));

  
  mvwprintw(new, 1, 0, "This is line 1\n");
  waddstr(new, "This is line 2\n");
  waddstr(new, "This is line 3\n");
  waddstr(new, "Press any key to scroll up\n");
  wrefresh(new);

  getch();
  wscrl(new, 2);
  waddstr(new, "Press any key to scroll down\n");
  wrefresh(new);
  getch();
  wscrl(new, -1);
  wrefresh(new);
  
  getch();
  endwin();
  return 0;
}
