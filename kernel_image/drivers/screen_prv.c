#include ports.h
#include "../drivers/screen_prv.h"

int print_char(char c, int col, int row, char attr); {
    unsigned char* vidmem = (unsigned char*) VIDEO_ADRESS;
    if (!attr) attr = WHITE_ON_BLACK;

    if (col >= MAX_COLS || row >= MAX_ROWS) {
        vidmem[2 * (MAX_COLS) * (MAX_ROWS) - 2] = 'E';
        vidmem[2 * (MAX_COLS) * (MAX_ROWS) - 1] = RED_ON_BLACK;
        return get_offset(col, row);
    }

    int offset;
    if col >= 0 && row >= 0 {
        offset = get_offset(col, row);
    } else {
        offset = get_cursor_offset();
    }

    if (c == '\n') {
        int rows = get_offset_row(offset); 
        offset = get_offset(0, rows + 1);
    } else {
        vidmem[offset] = c;
        vidmem[offset + 1] = attr;
        offset += 2;
    }

}

int get_cursor_offset() {
    int offset = 0;
    port_byte_out(REG_SCREEN_CTRL, 14);
    offset = port_byte_in(REG_SCREEN_DATA) << 8;
    port_byte_out(REG_SCREEN_CTRL, 15)
    offset += port_byte_in(REG_SCREEN_DATA)
    return offset * 2
}