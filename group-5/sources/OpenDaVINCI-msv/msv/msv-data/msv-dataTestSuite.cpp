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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/msv-data/testsuites/SensorBoardTestSuite.h"

static MSVDataTest suite_MSVDataTest;

static CxxTest::List Tests_MSVDataTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MSVDataTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/msv-data/testsuites/SensorBoardTestSuite.h", 18, "MSVDataTest", suite_MSVDataTest, Tests_MSVDataTest );

static class TestDescription_MSVDataTest_testDataSpecification : public CxxTest::RealTestDescription {
public:
 TestDescription_MSVDataTest_testDataSpecification() : CxxTest::RealTestDescription( Tests_MSVDataTest, suiteDescription_MSVDataTest, 30, "testDataSpecification" ) {}
 void runTest() { suite_MSVDataTest.testDataSpecification(); }
} testDescription_MSVDataTest_testDataSpecification;

static class TestDescription_MSVDataTest_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_MSVDataTest_testCopyConstructor() : CxxTest::RealTestDescription( Tests_MSVDataTest, suiteDescription_MSVDataTest, 45, "testCopyConstructor" ) {}
 void runTest() { suite_MSVDataTest.testCopyConstructor(); }
} testDescription_MSVDataTest_testCopyConstructor;

static class TestDescription_MSVDataTest_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_MSVDataTest_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_MSVDataTest, suiteDescription_MSVDataTest, 62, "testAssignmentOperator" ) {}
 void runTest() { suite_MSVDataTest.testAssignmentOperator(); }
} testDescription_MSVDataTest_testAssignmentOperator;

static class TestDescription_MSVDataTest_testSerialization : public CxxTest::RealTestDescription {
public:
 TestDescription_MSVDataTest_testSerialization() : CxxTest::RealTestDescription( Tests_MSVDataTest, suiteDescription_MSVDataTest, 80, "testSerialization" ) {}
 void runTest() { suite_MSVDataTest.testSerialization(); }
} testDescription_MSVDataTest_testSerialization;

#include <cxxtest/Root.cpp>
