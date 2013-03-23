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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/cockpit/testsuites/CockpitTestSuite.h"

static CockpitTest suite_CockpitTest;

static CxxTest::List Tests_CockpitTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CockpitTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/cockpit/testsuites/CockpitTestSuite.h", 36, "CockpitTest", suite_CockpitTest, Tests_CockpitTest );

static class TestDescription_CockpitTest_testCockpitSuccessfullyCreated : public CxxTest::RealTestDescription {
public:
 TestDescription_CockpitTest_testCockpitSuccessfullyCreated() : CxxTest::RealTestDescription( Tests_CockpitTest, suiteDescription_CockpitTest, 70, "testCockpitSuccessfullyCreated" ) {}
 void runTest() { suite_CockpitTest.testCockpitSuccessfullyCreated(); }
} testDescription_CockpitTest_testCockpitSuccessfullyCreated;

#include <cxxtest/Root.cpp>
