/* Screen constants */
#define VIDEO_ADRESS 0xB8000
#define MAX_COLS 80
#define MAX_ROWS 25
#define WHITE_ON_BLACK 0x0F
#define RED_ON_BLACK 0x4F

/* Screen I/O ports */
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

/* Private kernel functions */
int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char character, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);


