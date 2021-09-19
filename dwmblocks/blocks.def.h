// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {" ", "/home/edzdez/suckless/dwmblocks/scripts/cpu.sh", 10, 0},
    {" ", "free -h | grep Mem | awk '{print $3}'", 10, 0},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/network.sh", 60, 0},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/getbl.sh", 5, 1},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/getvol.sh", 5, 2},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/getbatt.sh", 15, 0},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/date.sh", 360, 0},
    {"", "/home/edzdez/suckless/dwmblocks/scripts/time.sh", 10, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
