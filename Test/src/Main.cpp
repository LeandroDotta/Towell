#include <Log.h>
#include "Test.h"
#include "Engine/math/TestMath.h"
#include "Engine/math/TestMatrix3.h"
#include "Engine/math/TestMatrix4.h"
#include "Engine/math/TestVector2.h"
#include "Engine/math/TestVector3.h"
#include "Engine/window/TestScreen.h"

using namespace Towell::Test;

int main(int argc, char* argv[])
{
    Towell::Log::Init(Towell::Log::LevelTrace);
    
    std::vector<TestSuite*> testSuites = 
    {
        // math
        new TestMath(),
        new TestMatrix3(),
        new TestMatrix4(),
        new TestVector2(),
        new TestVector3(),

        // window
        new TestScreen(),
    };

    for (auto suite : testSuites)
    {
        suite->Run();
    }
    
    return 0;
}