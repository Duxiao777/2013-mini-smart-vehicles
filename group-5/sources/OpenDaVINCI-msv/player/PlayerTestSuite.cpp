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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/player/testsuites/PlayerTestSuite.h"

static PlayerTest suite_PlayerTest;

static CxxTest::List Tests_PlayerTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PlayerTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/player/testsuites/PlayerTestSuite.h", 87, "PlayerTest", suite_PlayerTest, Tests_PlayerTest );

static class TestDescription_PlayerTest_testPlayerCommand : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testPlayerCommand() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 106, "testPlayerCommand" ) {}
 void runTest() { suite_PlayerTest.testPlayerCommand(); }
} testDescription_PlayerTest_testPlayerCommand;

static class TestDescription_PlayerTest_testRealtimeReplayNoRewind : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testRealtimeReplayNoRewind() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 143, "testRealtimeReplayNoRewind" ) {}
 void runTest() { suite_PlayerTest.testRealtimeReplayNoRewind(); }
} testDescription_PlayerTest_testRealtimeReplayNoRewind;

static class TestDescription_PlayerTest_testDoubleRealtimeReplayNoRewind : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testDoubleRealtimeReplayNoRewind() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 263, "testDoubleRealtimeReplayNoRewind" ) {}
 void runTest() { suite_PlayerTest.testDoubleRealtimeReplayNoRewind(); }
} testDescription_PlayerTest_testDoubleRealtimeReplayNoRewind;

static class TestDescription_PlayerTest_testHalfRealtimeReplayNoRewind : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testHalfRealtimeReplayNoRewind() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 395, "testHalfRealtimeReplayNoRewind" ) {}
 void runTest() { suite_PlayerTest.testHalfRealtimeReplayNoRewind(); }
} testDescription_PlayerTest_testHalfRealtimeReplayNoRewind;

static class TestDescription_PlayerTest_testRealtimeReplayAutoRewind : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testRealtimeReplayAutoRewind() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 526, "testRealtimeReplayAutoRewind" ) {}
 void runTest() { suite_PlayerTest.testRealtimeReplayAutoRewind(); }
} testDescription_PlayerTest_testRealtimeReplayAutoRewind;

static class TestDescription_PlayerTest_testRealtimeReplayNoRewindRemoteControl : public CxxTest::RealTestDescription {
public:
 TestDescription_PlayerTest_testRealtimeReplayNoRewindRemoteControl() : CxxTest::RealTestDescription( Tests_PlayerTest, suiteDescription_PlayerTest, 669, "testRealtimeReplayNoRewindRemoteControl" ) {}
 void runTest() { suite_PlayerTest.testRealtimeReplayNoRewindRemoteControl(); }
} testDescription_PlayerTest_testRealtimeReplayNoRewindRemoteControl;

#include <cxxtest/Root.cpp>
