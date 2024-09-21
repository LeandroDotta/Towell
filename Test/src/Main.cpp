#include <Log.h>
#include "../Test.h"

using namespace Towell;

int main(int argc, char* argv[])
{
    Towell::Log::Init(Towell::Log::LevelTrace);
    
    Test::test("Sum", []() -> void {
        Test::assertEqual(1, 1, "One is equal one");
        Test::assertEqual(1, 2, "One is different than two");
    });
    
    return 0;
}