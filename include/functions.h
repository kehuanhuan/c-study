extern char *get_local_ip();
extern void change(int *a, int *b);
extern char whoaim();
extern void printPageSize();

struct Book {
    char *title;
    int pages;
    char *author;
};