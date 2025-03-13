#include "__preprocessor__.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    // CORE::clear_terminal();
    time_stamp("It just works");

    return 0;
}
#endif