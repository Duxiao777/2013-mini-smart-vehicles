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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/recorder/testsuites/RecorderTestSuite.h"

static RecorderTest suite_RecorderTest;

static CxxTest::List Tests_RecorderTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RecorderTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/recorder/testsuites/RecorderTestSuite.h", 60, "RecorderTest", suite_RecorderTest, Tests_RecorderTest );

static class TestDescription_RecorderTest_testRecorder : public CxxTest::RealTestDescription {
public:
 TestDescription_RecorderTest_testRecorder() : CxxTest::RealTestDescription( Tests_RecorderTest, suiteDescription_RecorderTest, 79, "testRecorder" ) {}
 void runTest() { suite_RecorderTest.testRecorder(); }
} testDescription_RecorderTest_testRecorder;

static class TestDescription_RecorderTest_testRecorderCommand : public CxxTest::RealTestDescription {
public:
 TestDescription_RecorderTest_testRecorderCommand() : CxxTest::RealTestDescription( Tests_RecorderTest, suiteDescription_RecorderTest, 191, "testRecorderCommand" ) {}
 void runTest() { suite_RecorderTest.testRecorderCommand(); }
} testDescription_RecorderTest_testRecorderCommand;

static class TestDescription_RecorderTest_testRecorderRemoteControl : public CxxTest::RealTestDescription {
public:
 TestDescription_RecorderTest_testRecorderRemoteControl() : CxxTest::RealTestDescription( Tests_RecorderTest, suiteDescription_RecorderTest, 222, "testRecorderRemoteControl" ) {}
 void runTest() { suite_RecorderTest.testRecorderRemoteControl(); }
} testDescription_RecorderTest_testRecorderRemoteControl;

#include <cxxtest/Root.cpp>
