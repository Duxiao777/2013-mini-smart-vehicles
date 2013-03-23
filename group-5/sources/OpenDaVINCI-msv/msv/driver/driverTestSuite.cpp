/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/XmlFilePrinter.h>

int main() {
 return CxxTest::XmlFilePrinter().run();
}
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/driver/testsuites/DriverTestSuite.h"

static DriverTest suite_DriverTest;

static CxxTest::List Tests_DriverTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DriverTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/driver/testsuites/DriverTestSuite.h", 36, "DriverTest", suite_DriverTest, Tests_DriverTest );

static class TestDescription_DriverTest_testDriverSuccessfullyCreated : public CxxTest::RealTestDescription {
public:
 TestDescription_DriverTest_testDriverSuccessfullyCreated() : CxxTest::RealTestDescription( Tests_DriverTest, suiteDescription_DriverTest, 70, "testDriverSuccessfullyCreated" ) {}
 void runTest() { suite_DriverTest.testDriverSuccessfullyCreated(); }
} testDescription_DriverTest_testDriverSuccessfullyCreated;

#include <cxxtest/Root.cpp>
