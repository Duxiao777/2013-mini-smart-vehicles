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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/proxy/testsuites/ProxyTestSuite.h"

static ProxyTest suite_ProxyTest;

static CxxTest::List Tests_ProxyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ProxyTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/msv/proxy/testsuites/ProxyTestSuite.h", 36, "ProxyTest", suite_ProxyTest, Tests_ProxyTest );

static class TestDescription_ProxyTest_testProxySuccessfullyCreated : public CxxTest::RealTestDescription {
public:
 TestDescription_ProxyTest_testProxySuccessfullyCreated() : CxxTest::RealTestDescription( Tests_ProxyTest, suiteDescription_ProxyTest, 70, "testProxySuccessfullyCreated" ) {}
 void runTest() { suite_ProxyTest.testProxySuccessfullyCreated(); }
} testDescription_ProxyTest_testProxySuccessfullyCreated;

#include <cxxtest/Root.cpp>
