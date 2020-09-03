#include <cstdio>
#include <cstdlib>
#include "Resource.h"

static void Fail(const char* msg)
{
    std::printf("FAIL %s\n", msg);
    std::exit(1);
}

int main()
{
    if (IDD_ABOUTBOX != 100)
        Fail("about");
    if (IDR_MAINFRAME != 128)
        Fail("mainframe");
    if (IDR_WINDOWTYPE != 129)
        Fail("type");
    std::printf("OK WindowSizeTests\n");
    return 0;
}
