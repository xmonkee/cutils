#include "dcl.h"

int main(int argc, char **argv)
{
    if(argc < 2)
        return 1;
    return parse(argv[1], 0);
}
