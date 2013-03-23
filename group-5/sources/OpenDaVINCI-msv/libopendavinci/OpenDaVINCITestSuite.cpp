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
#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DisposalTestSuite.h"

static DisposalTest suite_DisposalTest;

static CxxTest::List Tests_DisposalTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DisposalTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DisposalTestSuite.h", 26, "DisposalTest", suite_DisposalTest, Tests_DisposalTest );

static class TestDescription_DisposalTest_testDisposal : public CxxTest::RealTestDescription {
public:
 TestDescription_DisposalTest_testDisposal() : CxxTest::RealTestDescription( Tests_DisposalTest, suiteDescription_DisposalTest, 28, "testDisposal" ) {}
 void runTest() { suite_DisposalTest.testDisposal(); }
} testDescription_DisposalTest_testDisposal;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/QueueTestSuite.h"

static QueueTest suite_QueueTest;

static CxxTest::List Tests_QueueTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_QueueTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/QueueTestSuite.h", 218, "QueueTest", suite_QueueTest, Tests_QueueTest );

static class TestDescription_QueueTest_testLIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testLIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 220, "testLIFO" ) {}
 void runTest() { suite_QueueTest.testLIFO(); }
} testDescription_QueueTest_testLIFO;

static class TestDescription_QueueTest_testFIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testFIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 241, "testFIFO" ) {}
 void runTest() { suite_QueueTest.testFIFO(); }
} testDescription_QueueTest_testFIFO;

static class TestDescription_QueueTest_testBufferedFIFOAsRegularFIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testBufferedFIFOAsRegularFIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 261, "testBufferedFIFOAsRegularFIFO" ) {}
 void runTest() { suite_QueueTest.testBufferedFIFOAsRegularFIFO(); }
} testDescription_QueueTest_testBufferedFIFOAsRegularFIFO;

static class TestDescription_QueueTest_testBufferedFIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testBufferedFIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 281, "testBufferedFIFO" ) {}
 void runTest() { suite_QueueTest.testBufferedFIFO(); }
} testDescription_QueueTest_testBufferedFIFO;

static class TestDescription_QueueTest_testFixedSizeBufferedFIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testFixedSizeBufferedFIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 352, "testFixedSizeBufferedFIFO" ) {}
 void runTest() { suite_QueueTest.testFixedSizeBufferedFIFO(); }
} testDescription_QueueTest_testFixedSizeBufferedFIFO;

static class TestDescription_QueueTest_testBufferedLIFOAsRegularLIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testBufferedLIFOAsRegularLIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 442, "testBufferedLIFOAsRegularLIFO" ) {}
 void runTest() { suite_QueueTest.testBufferedLIFOAsRegularLIFO(); }
} testDescription_QueueTest_testBufferedLIFOAsRegularLIFO;

static class TestDescription_QueueTest_testBufferedLIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testBufferedLIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 462, "testBufferedLIFO" ) {}
 void runTest() { suite_QueueTest.testBufferedLIFO(); }
} testDescription_QueueTest_testBufferedLIFO;

static class TestDescription_QueueTest_testFixedSizeBufferedLIFO : public CxxTest::RealTestDescription {
public:
 TestDescription_QueueTest_testFixedSizeBufferedLIFO() : CxxTest::RealTestDescription( Tests_QueueTest, suiteDescription_QueueTest, 533, "testFixedSizeBufferedLIFO" ) {}
 void runTest() { suite_QueueTest.testFixedSizeBufferedLIFO(); }
} testDescription_QueueTest_testFixedSizeBufferedLIFO;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/AbstractCIDModuleTestSuite.h"

static AbstractCIDModuleTest suite_AbstractCIDModuleTest;

static CxxTest::List Tests_AbstractCIDModuleTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AbstractCIDModuleTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/AbstractCIDModuleTestSuite.h", 81, "AbstractCIDModuleTest", suite_AbstractCIDModuleTest, Tests_AbstractCIDModuleTest );

static class TestDescription_AbstractCIDModuleTest_testAbstractCIDModule : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testAbstractCIDModule() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 83, "testAbstractCIDModule" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testAbstractCIDModule(); }
} testDescription_AbstractCIDModuleTest_testAbstractCIDModule;

static class TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleCID : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleCID() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 109, "testAbstractCIDModuleCID" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testAbstractCIDModuleCID(); }
} testDescription_AbstractCIDModuleTest_testAbstractCIDModuleCID;

static class TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID1 : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID1() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 128, "testAbstractCIDModuleWrongCID1" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testAbstractCIDModuleWrongCID1(); }
} testDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID1;

static class TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID2 : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID2() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 154, "testAbstractCIDModuleWrongCID2" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testAbstractCIDModuleWrongCID2(); }
} testDescription_AbstractCIDModuleTest_testAbstractCIDModuleWrongCID2;

static class TestDescription_AbstractCIDModuleTest_testKillAbstractCIDModule : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testKillAbstractCIDModule() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 179, "testKillAbstractCIDModule" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testKillAbstractCIDModule(); }
} testDescription_AbstractCIDModuleTest_testKillAbstractCIDModule;

static class TestDescription_AbstractCIDModuleTest_testExceptionAbstractCIDModule : public CxxTest::RealTestDescription {
public:
 TestDescription_AbstractCIDModuleTest_testExceptionAbstractCIDModule() : CxxTest::RealTestDescription( Tests_AbstractCIDModuleTest, suiteDescription_AbstractCIDModuleTest, 225, "testExceptionAbstractCIDModule" ) {}
 void runTest() { suite_AbstractCIDModuleTest.testExceptionAbstractCIDModule(); }
} testDescription_AbstractCIDModuleTest_testExceptionAbstractCIDModule;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConferenceFactoryTestSuite.h"

static ConferenceFactoryTest suite_ConferenceFactoryTest;

static CxxTest::List Tests_ConferenceFactoryTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ConferenceFactoryTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConferenceFactoryTestSuite.h", 70, "ConferenceFactoryTest", suite_ConferenceFactoryTest, Tests_ConferenceFactoryTest );

static class TestDescription_ConferenceFactoryTest_testControlledContainerFactoryTestSuite : public CxxTest::RealTestDescription {
public:
 TestDescription_ConferenceFactoryTest_testControlledContainerFactoryTestSuite() : CxxTest::RealTestDescription( Tests_ConferenceFactoryTest, suiteDescription_ConferenceFactoryTest, 72, "testControlledContainerFactoryTestSuite" ) {}
 void runTest() { suite_ConferenceFactoryTest.testControlledContainerFactoryTestSuite(); }
} testDescription_ConferenceFactoryTest_testControlledContainerFactoryTestSuite;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ControlFlowTestSuite.h"

static ControlFlowTest suite_ControlFlowTest;

static CxxTest::List Tests_ControlFlowTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ControlFlowTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ControlFlowTestSuite.h", 247, "ControlFlowTest", suite_ControlFlowTest, Tests_ControlFlowTest );

static class TestDescription_ControlFlowTest_testControlledContainerFactoryTestSuite : public CxxTest::RealTestDescription {
public:
 TestDescription_ControlFlowTest_testControlledContainerFactoryTestSuite() : CxxTest::RealTestDescription( Tests_ControlFlowTest, suiteDescription_ControlFlowTest, 266, "testControlledContainerFactoryTestSuite" ) {}
 void runTest() { suite_ControlFlowTest.testControlledContainerFactoryTestSuite(); }
} testDescription_ControlFlowTest_testControlledContainerFactoryTestSuite;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ServiceTestSuite.h"

static ServiceTest suite_ServiceTest;

static CxxTest::List Tests_ServiceTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ServiceTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ServiceTestSuite.h", 89, "ServiceTest", suite_ServiceTest, Tests_ServiceTest );

static class TestDescription_ServiceTest_testService : public CxxTest::RealTestDescription {
public:
 TestDescription_ServiceTest_testService() : CxxTest::RealTestDescription( Tests_ServiceTest, suiteDescription_ServiceTest, 108, "testService" ) {}
 void runTest() { suite_ServiceTest.testService(); }
} testDescription_ServiceTest_testService;

static class TestDescription_ServiceTest_testSeveralServices : public CxxTest::RealTestDescription {
public:
 TestDescription_ServiceTest_testSeveralServices() : CxxTest::RealTestDescription( Tests_ServiceTest, suiteDescription_ServiceTest, 127, "testSeveralServices" ) {}
 void runTest() { suite_ServiceTest.testSeveralServices(); }
} testDescription_ServiceTest_testSeveralServices;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TimeFactoryTestSuite.h"

static TimeFactoryTest suite_TimeFactoryTest;

static CxxTest::List Tests_TimeFactoryTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TimeFactoryTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TimeFactoryTestSuite.h", 36, "TimeFactoryTest", suite_TimeFactoryTest, Tests_TimeFactoryTest );

static class TestDescription_TimeFactoryTest_testCopyControlledTime : public CxxTest::RealTestDescription {
public:
 TestDescription_TimeFactoryTest_testCopyControlledTime() : CxxTest::RealTestDescription( Tests_TimeFactoryTest, suiteDescription_TimeFactoryTest, 38, "testCopyControlledTime" ) {}
 void runTest() { suite_TimeFactoryTest.testCopyControlledTime(); }
} testDescription_TimeFactoryTest_testCopyControlledTime;

static class TestDescription_TimeFactoryTest_testControlledTimeFactoryTestSuite : public CxxTest::RealTestDescription {
public:
 TestDescription_TimeFactoryTest_testControlledTimeFactoryTestSuite() : CxxTest::RealTestDescription( Tests_TimeFactoryTest, suiteDescription_TimeFactoryTest, 51, "testControlledTimeFactoryTestSuite" ) {}
 void runTest() { suite_TimeFactoryTest.testControlledTimeFactoryTestSuite(); }
} testDescription_TimeFactoryTest_testControlledTimeFactoryTestSuite;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/CommandLineParserTestSuite.h"

static CommandLineParserTestSuite suite_CommandLineParserTestSuite;

static CxxTest::List Tests_CommandLineParserTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CommandLineParserTestSuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/CommandLineParserTestSuite.h", 21, "CommandLineParserTestSuite", suite_CommandLineParserTestSuite, Tests_CommandLineParserTestSuite );

static class TestDescription_CommandLineParserTestSuite_testParse : public CxxTest::RealTestDescription {
public:
 TestDescription_CommandLineParserTestSuite_testParse() : CxxTest::RealTestDescription( Tests_CommandLineParserTestSuite, suiteDescription_CommandLineParserTestSuite, 23, "testParse" ) {}
 void runTest() { suite_CommandLineParserTestSuite.testParse(); }
} testDescription_CommandLineParserTestSuite_testParse;

static class TestDescription_CommandLineParserTestSuite_testParseSeveralArgumentFromSameKey : public CxxTest::RealTestDescription {
public:
 TestDescription_CommandLineParserTestSuite_testParseSeveralArgumentFromSameKey() : CxxTest::RealTestDescription( Tests_CommandLineParserTestSuite, suiteDescription_CommandLineParserTestSuite, 51, "testParseSeveralArgumentFromSameKey" ) {}
 void runTest() { suite_CommandLineParserTestSuite.testParseSeveralArgumentFromSameKey(); }
} testDescription_CommandLineParserTestSuite_testParseSeveralArgumentFromSameKey;

static class TestDescription_CommandLineParserTestSuite_testGetInvalidArgument : public CxxTest::RealTestDescription {
public:
 TestDescription_CommandLineParserTestSuite_testGetInvalidArgument() : CxxTest::RealTestDescription( Tests_CommandLineParserTestSuite, suiteDescription_CommandLineParserTestSuite, 91, "testGetInvalidArgument" ) {}
 void runTest() { suite_CommandLineParserTestSuite.testGetInvalidArgument(); }
} testDescription_CommandLineParserTestSuite_testGetInvalidArgument;

static class TestDescription_CommandLineParserTestSuite_testParseIncompleteArgument : public CxxTest::RealTestDescription {
public:
 TestDescription_CommandLineParserTestSuite_testParseIncompleteArgument() : CxxTest::RealTestDescription( Tests_CommandLineParserTestSuite, suiteDescription_CommandLineParserTestSuite, 105, "testParseIncompleteArgument" ) {}
 void runTest() { suite_CommandLineParserTestSuite.testParseIncompleteArgument(); }
} testDescription_CommandLineParserTestSuite_testParseIncompleteArgument;

static class TestDescription_CommandLineParserTestSuite_testUnhandledArgument : public CxxTest::RealTestDescription {
public:
 TestDescription_CommandLineParserTestSuite_testUnhandledArgument() : CxxTest::RealTestDescription( Tests_CommandLineParserTestSuite, suiteDescription_CommandLineParserTestSuite, 139, "testUnhandledArgument" ) {}
 void runTest() { suite_CommandLineParserTestSuite.testUnhandledArgument(); }
} testDescription_CommandLineParserTestSuite_testUnhandledArgument;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SharedPointerTestSuite.h"

static SharedPointerTest suite_SharedPointerTest;

static CxxTest::List Tests_SharedPointerTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SharedPointerTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SharedPointerTestSuite.h", 32, "SharedPointerTest", suite_SharedPointerTest, Tests_SharedPointerTest );

static class TestDescription_SharedPointerTest_testCreateSharedPointer : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateSharedPointer() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 34, "testCreateSharedPointer" ) {}
 void runTest() { suite_SharedPointerTest.testCreateSharedPointer(); }
} testDescription_SharedPointerTest_testCreateSharedPointer;

static class TestDescription_SharedPointerTest_testCreateDestroySharedPointer : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateDestroySharedPointer() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 48, "testCreateDestroySharedPointer" ) {}
 void runTest() { suite_SharedPointerTest.testCreateDestroySharedPointer(); }
} testDescription_SharedPointerTest_testCreateDestroySharedPointer;

static class TestDescription_SharedPointerTest_testCreateDestroySharedPointerUsingCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateDestroySharedPointerUsingCopyConstructor() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 65, "testCreateDestroySharedPointerUsingCopyConstructor" ) {}
 void runTest() { suite_SharedPointerTest.testCreateDestroySharedPointerUsingCopyConstructor(); }
} testDescription_SharedPointerTest_testCreateDestroySharedPointerUsingCopyConstructor;

static class TestDescription_SharedPointerTest_testCreateDestroySharedPointerUsingAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateDestroySharedPointerUsingAssignmentOperator() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 88, "testCreateDestroySharedPointerUsingAssignmentOperator" ) {}
 void runTest() { suite_SharedPointerTest.testCreateDestroySharedPointerUsingAssignmentOperator(); }
} testDescription_SharedPointerTest_testCreateDestroySharedPointerUsingAssignmentOperator;

static class TestDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingCopyConstructor() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 111, "testCreateAndKeepSharedPointerUsingCopyConstructor" ) {}
 void runTest() { suite_SharedPointerTest.testCreateAndKeepSharedPointerUsingCopyConstructor(); }
} testDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingCopyConstructor;

static class TestDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingAssignmentOperator() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 138, "testCreateAndKeepSharedPointerUsingAssignmentOperator" ) {}
 void runTest() { suite_SharedPointerTest.testCreateAndKeepSharedPointerUsingAssignmentOperator(); }
} testDescription_SharedPointerTest_testCreateAndKeepSharedPointerUsingAssignmentOperator;

static class TestDescription_SharedPointerTest_testSharedPointerInsideSTL : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testSharedPointerInsideSTL() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 166, "testSharedPointerInsideSTL" ) {}
 void runTest() { suite_SharedPointerTest.testSharedPointerInsideSTL(); }
} testDescription_SharedPointerTest_testSharedPointerInsideSTL;

static class TestDescription_SharedPointerTest_testSharedPointerInsideSTLAndCopy : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedPointerTest_testSharedPointerInsideSTLAndCopy() : CxxTest::RealTestDescription( Tests_SharedPointerTest, suiteDescription_SharedPointerTest, 201, "testSharedPointerInsideSTLAndCopy" ) {}
 void runTest() { suite_SharedPointerTest.testSharedPointerInsideSTLAndCopy(); }
} testDescription_SharedPointerTest_testSharedPointerInsideSTLAndCopy;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConditionTestSuite.h"

static ConditionTest suite_ConditionTest;

static CxxTest::List Tests_ConditionTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ConditionTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConditionTestSuite.h", 92, "ConditionTest", suite_ConditionTest, Tests_ConditionTest );

static class TestDescription_ConditionTest_testLocking : public CxxTest::RealTestDescription {
public:
 TestDescription_ConditionTest_testLocking() : CxxTest::RealTestDescription( Tests_ConditionTest, suiteDescription_ConditionTest, 94, "testLocking" ) {}
 void runTest() { suite_ConditionTest.testLocking(); }
} testDescription_ConditionTest_testLocking;

static class TestDescription_ConditionTest_testWakeOne : public CxxTest::RealTestDescription {
public:
 TestDescription_ConditionTest_testWakeOne() : CxxTest::RealTestDescription( Tests_ConditionTest, suiteDescription_ConditionTest, 107, "testWakeOne" ) {}
 void runTest() { suite_ConditionTest.testWakeOne(); }
} testDescription_ConditionTest_testWakeOne;

static class TestDescription_ConditionTest_testWakeAll : public CxxTest::RealTestDescription {
public:
 TestDescription_ConditionTest_testWakeAll() : CxxTest::RealTestDescription( Tests_ConditionTest, suiteDescription_ConditionTest, 143, "testWakeAll" ) {}
 void runTest() { suite_ConditionTest.testWakeAll(); }
} testDescription_ConditionTest_testWakeAll;

static class TestDescription_ConditionTest_testTimeCondition : public CxxTest::RealTestDescription {
public:
 TestDescription_ConditionTest_testTimeCondition() : CxxTest::RealTestDescription( Tests_ConditionTest, suiteDescription_ConditionTest, 183, "testTimeCondition" ) {}
 void runTest() { suite_ConditionTest.testTimeCondition(); }
} testDescription_ConditionTest_testTimeCondition;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TimeStampTestSuite.h"

static TimeStampTest suite_TimeStampTest;

static CxxTest::List Tests_TimeStampTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TimeStampTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TimeStampTestSuite.h", 21, "TimeStampTest", suite_TimeStampTest, Tests_TimeStampTest );

static class TestDescription_TimeStampTest_testTimeStamp28042009 : public CxxTest::RealTestDescription {
public:
 TestDescription_TimeStampTest_testTimeStamp28042009() : CxxTest::RealTestDescription( Tests_TimeStampTest, suiteDescription_TimeStampTest, 23, "testTimeStamp28042009" ) {}
 void runTest() { suite_TimeStampTest.testTimeStamp28042009(); }
} testDescription_TimeStampTest_testTimeStamp28042009;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TCPTestSuite.h"

static TCPAcceptorTestsuite suite_TCPAcceptorTestsuite;

static CxxTest::List Tests_TCPAcceptorTestsuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TCPAcceptorTestsuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TCPTestSuite.h", 109, "TCPAcceptorTestsuite", suite_TCPAcceptorTestsuite, Tests_TCPAcceptorTestsuite );

static class TestDescription_TCPAcceptorTestsuite_testAccept : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPAcceptorTestsuite_testAccept() : CxxTest::RealTestDescription( Tests_TCPAcceptorTestsuite, suiteDescription_TCPAcceptorTestsuite, 112, "testAccept" ) {}
 void runTest() { suite_TCPAcceptorTestsuite.testAccept(); }
} testDescription_TCPAcceptorTestsuite_testAccept;

static class TestDescription_TCPAcceptorTestsuite_testMultipleAccept : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPAcceptorTestsuite_testMultipleAccept() : CxxTest::RealTestDescription( Tests_TCPAcceptorTestsuite, suiteDescription_TCPAcceptorTestsuite, 131, "testMultipleAccept" ) {}
 void runTest() { suite_TCPAcceptorTestsuite.testMultipleAccept(); }
} testDescription_TCPAcceptorTestsuite_testMultipleAccept;

static class TestDescription_TCPAcceptorTestsuite_testNoAcceptBoost : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPAcceptorTestsuite_testNoAcceptBoost() : CxxTest::RealTestDescription( Tests_TCPAcceptorTestsuite, suiteDescription_TCPAcceptorTestsuite, 150, "testNoAcceptBoost" ) {}
 void runTest() { suite_TCPAcceptorTestsuite.testNoAcceptBoost(); }
} testDescription_TCPAcceptorTestsuite_testNoAcceptBoost;

static TCPConnectionTestSuite suite_TCPConnectionTestSuite;

static CxxTest::List Tests_TCPConnectionTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TCPConnectionTestSuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TCPTestSuite.h", 264, "TCPConnectionTestSuite", suite_TCPConnectionTestSuite, Tests_TCPConnectionTestSuite );

static class TestDescription_TCPConnectionTestSuite_testTransfer : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPConnectionTestSuite_testTransfer() : CxxTest::RealTestDescription( Tests_TCPConnectionTestSuite, suiteDescription_TCPConnectionTestSuite, 267, "testTransfer" ) {}
 void runTest() { suite_TCPConnectionTestSuite.testTransfer(); }
} testDescription_TCPConnectionTestSuite_testTransfer;

static class TestDescription_TCPConnectionTestSuite_testError : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPConnectionTestSuite_testError() : CxxTest::RealTestDescription( Tests_TCPConnectionTestSuite, suiteDescription_TCPConnectionTestSuite, 286, "testError" ) {}
 void runTest() { suite_TCPConnectionTestSuite.testError(); }
} testDescription_TCPConnectionTestSuite_testError;

static TCPGathererTestSuite suite_TCPGathererTestSuite;

static CxxTest::List Tests_TCPGathererTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TCPGathererTestSuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TCPTestSuite.h", 306, "TCPGathererTestSuite", suite_TCPGathererTestSuite, Tests_TCPGathererTestSuite );

static class TestDescription_TCPGathererTestSuite_testNoGathering : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPGathererTestSuite_testNoGathering() : CxxTest::RealTestDescription( Tests_TCPGathererTestSuite, suiteDescription_TCPGathererTestSuite, 326, "testNoGathering" ) {}
 void runTest() { suite_TCPGathererTestSuite.testNoGathering(); }
} testDescription_TCPGathererTestSuite_testNoGathering;

static class TestDescription_TCPGathererTestSuite_testGathering : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPGathererTestSuite_testGathering() : CxxTest::RealTestDescription( Tests_TCPGathererTestSuite, suiteDescription_TCPGathererTestSuite, 345, "testGathering" ) {}
 void runTest() { suite_TCPGathererTestSuite.testGathering(); }
} testDescription_TCPGathererTestSuite_testGathering;

static class TestDescription_TCPGathererTestSuite_testMixedGathering : public CxxTest::RealTestDescription {
public:
 TestDescription_TCPGathererTestSuite_testMixedGathering() : CxxTest::RealTestDescription( Tests_TCPGathererTestSuite, suiteDescription_TCPGathererTestSuite, 371, "testMixedGathering" ) {}
 void runTest() { suite_TCPGathererTestSuite.testMixedGathering(); }
} testDescription_TCPGathererTestSuite_testMixedGathering;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlTestSuite.h"

static RuntimeControlTest suite_RuntimeControlTest;

static CxxTest::List Tests_RuntimeControlTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RuntimeControlTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlTestSuite.h", 91, "RuntimeControlTest", suite_RuntimeControlTest, Tests_RuntimeControlTest );

static class TestDescription_RuntimeControlTest_testRuntimeControlRegularRun : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlTest_testRuntimeControlRegularRun() : CxxTest::RealTestDescription( Tests_RuntimeControlTest, suiteDescription_RuntimeControlTest, 93, "testRuntimeControlRegularRun" ) {}
 void runTest() { suite_RuntimeControlTest.testRuntimeControlRegularRun(); }
} testDescription_RuntimeControlTest_testRuntimeControlRegularRun;

static class TestDescription_RuntimeControlTest_testRuntimeControlSpecializedConfigurationRegularRun : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlTest_testRuntimeControlSpecializedConfigurationRegularRun() : CxxTest::RealTestDescription( Tests_RuntimeControlTest, suiteDescription_RuntimeControlTest, 153, "testRuntimeControlSpecializedConfigurationRegularRun" ) {}
 void runTest() { suite_RuntimeControlTest.testRuntimeControlSpecializedConfigurationRegularRun(); }
} testDescription_RuntimeControlTest_testRuntimeControlSpecializedConfigurationRegularRun;

static class TestDescription_RuntimeControlTest_testRuntimeControlCorruptConfigurationRun : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlTest_testRuntimeControlCorruptConfigurationRun() : CxxTest::RealTestDescription( Tests_RuntimeControlTest, suiteDescription_RuntimeControlTest, 206, "testRuntimeControlCorruptConfigurationRun" ) {}
 void runTest() { suite_RuntimeControlTest.testRuntimeControlCorruptConfigurationRun(); }
} testDescription_RuntimeControlTest_testRuntimeControlCorruptConfigurationRun;

static class TestDescription_RuntimeControlTest_testRuntimeControlRegularRunNoSetupCalled : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlTest_testRuntimeControlRegularRunNoSetupCalled() : CxxTest::RealTestDescription( Tests_RuntimeControlTest, suiteDescription_RuntimeControlTest, 252, "testRuntimeControlRegularRunNoSetupCalled" ) {}
 void runTest() { suite_RuntimeControlTest.testRuntimeControlRegularRunNoSetupCalled(); }
} testDescription_RuntimeControlTest_testRuntimeControlRegularRunNoSetupCalled;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ClockTestSuite.h"

static ClockTest suite_ClockTest;

static CxxTest::List Tests_ClockTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ClockTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ClockTestSuite.h", 21, "ClockTest", suite_ClockTest, Tests_ClockTest );

static class TestDescription_ClockTest_testClock : public CxxTest::RealTestDescription {
public:
 TestDescription_ClockTest_testClock() : CxxTest::RealTestDescription( Tests_ClockTest, suiteDescription_ClockTest, 23, "testClock" ) {}
 void runTest() { suite_ClockTest.testClock(); }
} testDescription_ClockTest_testClock;

static class TestDescription_ClockTest_testCopyClock : public CxxTest::RealTestDescription {
public:
 TestDescription_ClockTest_testCopyClock() : CxxTest::RealTestDescription( Tests_ClockTest, suiteDescription_ClockTest, 67, "testCopyClock" ) {}
 void runTest() { suite_ClockTest.testCopyClock(); }
} testDescription_ClockTest_testCopyClock;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SerializationTestSuite.h"

static SerializationTest suite_SerializationTest;

static CxxTest::List Tests_SerializationTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SerializationTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SerializationTestSuite.h", 118, "SerializationTest", suite_SerializationTest, Tests_SerializationTest );

static class TestDescription_SerializationTest_testSerializationDeserialization : public CxxTest::RealTestDescription {
public:
 TestDescription_SerializationTest_testSerializationDeserialization() : CxxTest::RealTestDescription( Tests_SerializationTest, suiteDescription_SerializationTest, 120, "testSerializationDeserialization" ) {}
 void runTest() { suite_SerializationTest.testSerializationDeserialization(); }
} testDescription_SerializationTest_testSerializationDeserialization;

static class TestDescription_SerializationTest_testArraySerialisation : public CxxTest::RealTestDescription {
public:
 TestDescription_SerializationTest_testArraySerialisation() : CxxTest::RealTestDescription( Tests_SerializationTest, suiteDescription_SerializationTest, 143, "testArraySerialisation" ) {}
 void runTest() { suite_SerializationTest.testArraySerialisation(); }
} testDescription_SerializationTest_testArraySerialisation;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ContainerTestSuite.h"

static ContainerTest suite_ContainerTest;

static CxxTest::List Tests_ContainerTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ContainerTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ContainerTestSuite.h", 20, "ContainerTest", suite_ContainerTest, Tests_ContainerTest );

static class TestDescription_ContainerTest_testContainerData : public CxxTest::RealTestDescription {
public:
 TestDescription_ContainerTest_testContainerData() : CxxTest::RealTestDescription( Tests_ContainerTest, suiteDescription_ContainerTest, 22, "testContainerData" ) {}
 void runTest() { suite_ContainerTest.testContainerData(); }
} testDescription_ContainerTest_testContainerData;

static class TestDescription_ContainerTest_testContainerDataUserType : public CxxTest::RealTestDescription {
public:
 TestDescription_ContainerTest_testContainerDataUserType() : CxxTest::RealTestDescription( Tests_ContainerTest, suiteDescription_ContainerTest, 38, "testContainerDataUserType" ) {}
 void runTest() { suite_ContainerTest.testContainerDataUserType(); }
} testDescription_ContainerTest_testContainerDataUserType;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SharedMemoryTestSuite.h"

static SharedMemoryTest suite_SharedMemoryTest;

static CxxTest::List Tests_SharedMemoryTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SharedMemoryTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/SharedMemoryTestSuite.h", 18, "SharedMemoryTest", suite_SharedMemoryTest, Tests_SharedMemoryTest );

static class TestDescription_SharedMemoryTest_testSharedMemory : public CxxTest::RealTestDescription {
public:
 TestDescription_SharedMemoryTest_testSharedMemory() : CxxTest::RealTestDescription( Tests_SharedMemoryTest, suiteDescription_SharedMemoryTest, 20, "testSharedMemory" ) {}
 void runTest() { suite_SharedMemoryTest.testSharedMemory(); }
} testDescription_SharedMemoryTest_testSharedMemory;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/MutexTestSuite.h"

static MutexTest suite_MutexTest;

static CxxTest::List Tests_MutexTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MutexTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/MutexTestSuite.h", 34, "MutexTest", suite_MutexTest, Tests_MutexTest );

static class TestDescription_MutexTest_testTryLock : public CxxTest::RealTestDescription {
public:
 TestDescription_MutexTest_testTryLock() : CxxTest::RealTestDescription( Tests_MutexTest, suiteDescription_MutexTest, 36, "testTryLock" ) {}
 void runTest() { suite_MutexTest.testTryLock(); }
} testDescription_MutexTest_testTryLock;

static class TestDescription_MutexTest_testLockAndUnlock : public CxxTest::RealTestDescription {
public:
 TestDescription_MutexTest_testLockAndUnlock() : CxxTest::RealTestDescription( Tests_MutexTest, suiteDescription_MutexTest, 42, "testLockAndUnlock" ) {}
 void runTest() { suite_MutexTest.testLockAndUnlock(); }
} testDescription_MutexTest_testLockAndUnlock;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/KeyValueConfigurationTestSuite.h"

static ConfigurationTest suite_ConfigurationTest;

static CxxTest::List Tests_ConfigurationTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ConfigurationTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/KeyValueConfigurationTestSuite.h", 22, "ConfigurationTest", suite_ConfigurationTest, Tests_ConfigurationTest );

static class TestDescription_ConfigurationTest_testReadSimpleData : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadSimpleData() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 24, "testReadSimpleData" ) {}
 void runTest() { suite_ConfigurationTest.testReadSimpleData(); }
} testDescription_ConfigurationTest_testReadSimpleData;

static class TestDescription_ConfigurationTest_testReadSimpleDataCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadSimpleDataCopyConstructor() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 59, "testReadSimpleDataCopyConstructor" ) {}
 void runTest() { suite_ConfigurationTest.testReadSimpleDataCopyConstructor(); }
} testDescription_ConfigurationTest_testReadSimpleDataCopyConstructor;

static class TestDescription_ConfigurationTest_testReadSimpleDataAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadSimpleDataAssignmentOperator() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 96, "testReadSimpleDataAssignmentOperator" ) {}
 void runTest() { suite_ConfigurationTest.testReadSimpleDataAssignmentOperator(); }
} testDescription_ConfigurationTest_testReadSimpleDataAssignmentOperator;

static class TestDescription_ConfigurationTest_testReadCommentedData : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadCommentedData() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 134, "testReadCommentedData" ) {}
 void runTest() { suite_ConfigurationTest.testReadCommentedData(); }
} testDescription_ConfigurationTest_testReadCommentedData;

static class TestDescription_ConfigurationTest_testReadCommentedDataCaseInsensitive : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadCommentedDataCaseInsensitive() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 174, "testReadCommentedDataCaseInsensitive" ) {}
 void runTest() { suite_ConfigurationTest.testReadCommentedDataCaseInsensitive(); }
} testDescription_ConfigurationTest_testReadCommentedDataCaseInsensitive;

static class TestDescription_ConfigurationTest_testReadCommentedDataSubset : public CxxTest::RealTestDescription {
public:
 TestDescription_ConfigurationTest_testReadCommentedDataSubset() : CxxTest::RealTestDescription( Tests_ConfigurationTest, suiteDescription_ConfigurationTest, 206, "testReadCommentedDataSubset" ) {}
 void runTest() { suite_ConfigurationTest.testReadCommentedDataSubset(); }
} testDescription_ConfigurationTest_testReadCommentedDataSubset;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlContainerMultipleAppsTestSuite.h"

static RuntimeControlContainerMultipleAppsTest suite_RuntimeControlContainerMultipleAppsTest;

static CxxTest::List Tests_RuntimeControlContainerMultipleAppsTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RuntimeControlContainerMultipleAppsTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlContainerMultipleAppsTestSuite.h", 279, "RuntimeControlContainerMultipleAppsTest", suite_RuntimeControlContainerMultipleAppsTest, Tests_RuntimeControlContainerMultipleAppsTest );

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqOneSP : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqOneSP() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 281, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqOneSP" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqOneSP(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqOneSP;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsOneReceivingDataFromOtherAppSameFreqOneSP : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsOneReceivingDataFromOtherAppSameFreqOneSP() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 413, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsOneReceivingDataFromOtherAppSameFreqOneSP" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsOneReceivingDataFromOtherAppSameFreqOneSP(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsOneReceivingDataFromOtherAppSameFreqOneSP;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2OneSP : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2OneSP() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 558, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2OneSP" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2OneSP(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2OneSP;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSameFreq : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSameFreq() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 696, "testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSameFreq" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSameFreq(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSameFreq;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSP2TwiceAsFastAsSP1 : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSP2TwiceAsFastAsSP1() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 811, "testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSP2TwiceAsFastAsSP1" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSP2TwiceAsFastAsSP1(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingOneAppTwoSystemPartsSP2TwiceAsFastAsSP1;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSameFreq : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSameFreq() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 937, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSameFreq" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSameFreq(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSameFreq;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2TwoSystemPartsSameFreq : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2TwoSystemPartsSameFreq() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 1096, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2TwoSystemPartsSameFreq" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2TwoSystemPartsSameFreq(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1twiceAsFastAsA2TwoSystemPartsSameFreq;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSP2TwiceAsFastAsSP1 : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSP2TwiceAsFastAsSP1() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 1287, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSP2TwiceAsFastAsSP1" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSP2TwiceAsFastAsSP1(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsSameFreqTwoSystemPartsSP2TwiceAsFastAsSP1;

static class TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1TwiceAsFastAsA2FreqTwoSystemPartsSP2TwiceAsFastAsSP1 : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1TwiceAsFastAsA2FreqTwoSystemPartsSP2TwiceAsFastAsSP1() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerMultipleAppsTest, suiteDescription_RuntimeControlContainerMultipleAppsTest, 1468, "testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1TwiceAsFastAsA2FreqTwoSystemPartsSP2TwiceAsFastAsSP1" ) {}
 void runTest() { suite_RuntimeControlContainerMultipleAppsTest.testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1TwiceAsFastAsA2FreqTwoSystemPartsSP2TwiceAsFastAsSP1(); }
} testDescription_RuntimeControlContainerMultipleAppsTest_testRuntimeControlContainerRegularRunReceivingSendingTwoAppsA1TwiceAsFastAsA2FreqTwoSystemPartsSP2TwiceAsFastAsSP1;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RunnerTestSuite.h"

static RunnerTest suite_RunnerTest;

static CxxTest::List Tests_RunnerTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RunnerTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RunnerTestSuite.h", 32, "RunnerTest", suite_RunnerTest, Tests_RunnerTest );

static class TestDescription_RunnerTest_testFrequencies : public CxxTest::RealTestDescription {
public:
 TestDescription_RunnerTest_testFrequencies() : CxxTest::RealTestDescription( Tests_RunnerTest, suiteDescription_RunnerTest, 34, "testFrequencies" ) {}
 void runTest() { suite_RunnerTest.testFrequencies(); }
} testDescription_RunnerTest_testFrequencies;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DataStoreTestSuite.h"

static DataStoreTest suite_DataStoreTest;

static CxxTest::List Tests_DataStoreTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DataStoreTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DataStoreTestSuite.h", 159, "DataStoreTest", suite_DataStoreTest, Tests_DataStoreTest );

static class TestDescription_DataStoreTest_testDataStore : public CxxTest::RealTestDescription {
public:
 TestDescription_DataStoreTest_testDataStore() : CxxTest::RealTestDescription( Tests_DataStoreTest, suiteDescription_DataStoreTest, 162, "testDataStore" ) {}
 void runTest() { suite_DataStoreTest.testDataStore(); }
} testDescription_DataStoreTest_testDataStore;

static class TestDescription_DataStoreTest_testMassData : public CxxTest::RealTestDescription {
public:
 TestDescription_DataStoreTest_testMassData() : CxxTest::RealTestDescription( Tests_DataStoreTest, suiteDescription_DataStoreTest, 183, "testMassData" ) {}
 void runTest() { suite_DataStoreTest.testMassData(); }
} testDescription_DataStoreTest_testMassData;

static class TestDescription_DataStoreTest_testSerializationDeserialization : public CxxTest::RealTestDescription {
public:
 TestDescription_DataStoreTest_testSerializationDeserialization() : CxxTest::RealTestDescription( Tests_DataStoreTest, suiteDescription_DataStoreTest, 228, "testSerializationDeserialization" ) {}
 void runTest() { suite_DataStoreTest.testSerializationDeserialization(); }
} testDescription_DataStoreTest_testSerializationDeserialization;

static class TestDescription_DataStoreTest_testDataStoreForDataExchange : public CxxTest::RealTestDescription {
public:
 TestDescription_DataStoreTest_testDataStoreForDataExchange() : CxxTest::RealTestDescription( Tests_DataStoreTest, suiteDescription_DataStoreTest, 257, "testDataStoreForDataExchange" ) {}
 void runTest() { suite_DataStoreTest.testDataStoreForDataExchange(); }
} testDescription_DataStoreTest_testDataStoreForDataExchange;

static class TestDescription_DataStoreTest_testSerializationDeserializationWithFileBackend : public CxxTest::RealTestDescription {
public:
 TestDescription_DataStoreTest_testSerializationDeserializationWithFileBackend() : CxxTest::RealTestDescription( Tests_DataStoreTest, suiteDescription_DataStoreTest, 301, "testSerializationDeserializationWithFileBackend" ) {}
 void runTest() { suite_DataStoreTest.testSerializationDeserializationWithFileBackend(); }
} testDescription_DataStoreTest_testSerializationDeserializationWithFileBackend;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConnectionTestSuite.h"

static ConnectionTestsuite suite_ConnectionTestsuite;

static CxxTest::List Tests_ConnectionTestsuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ConnectionTestsuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConnectionTestSuite.h", 38, "ConnectionTestsuite", suite_ConnectionTestsuite, Tests_ConnectionTestsuite );

static class TestDescription_ConnectionTestsuite_testAcceptAndConnect : public CxxTest::RealTestDescription {
public:
 TestDescription_ConnectionTestsuite_testAcceptAndConnect() : CxxTest::RealTestDescription( Tests_ConnectionTestsuite, suiteDescription_ConnectionTestsuite, 40, "testAcceptAndConnect" ) {}
 void runTest() { suite_ConnectionTestsuite.testAcceptAndConnect(); }
} testDescription_ConnectionTestsuite_testAcceptAndConnect;

static class TestDescription_ConnectionTestsuite_testErrorHandler : public CxxTest::RealTestDescription {
public:
 TestDescription_ConnectionTestsuite_testErrorHandler() : CxxTest::RealTestDescription( Tests_ConnectionTestsuite, suiteDescription_ConnectionTestsuite, 89, "testErrorHandler" ) {}
 void runTest() { suite_ConnectionTestsuite.testErrorHandler(); }
} testDescription_ConnectionTestsuite_testErrorHandler;

static class TestDescription_ConnectionTestsuite_testTransfer : public CxxTest::RealTestDescription {
public:
 TestDescription_ConnectionTestsuite_testTransfer() : CxxTest::RealTestDescription( Tests_ConnectionTestsuite, suiteDescription_ConnectionTestsuite, 120, "testTransfer" ) {}
 void runTest() { suite_ConnectionTestsuite.testTransfer(); }
} testDescription_ConnectionTestsuite_testTransfer;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ZipTestSuite.h"

static ZipTest suite_ZipTest;

static CxxTest::List Tests_ZipTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ZipTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ZipTestSuite.h", 23, "ZipTest", suite_ZipTest, Tests_ZipTest );

static class TestDescription_ZipTest_testDecompression : public CxxTest::RealTestDescription {
public:
 TestDescription_ZipTest_testDecompression() : CxxTest::RealTestDescription( Tests_ZipTest, suiteDescription_ZipTest, 25, "testDecompression" ) {}
 void runTest() { suite_ZipTest.testDecompression(); }
} testDescription_ZipTest_testDecompression;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DMCPDiscovererTestSuite.h"

static DMCPDiscovererTestsuite suite_DMCPDiscovererTestsuite;

static CxxTest::List Tests_DMCPDiscovererTestsuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DMCPDiscovererTestsuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DMCPDiscovererTestSuite.h", 60, "DMCPDiscovererTestsuite", suite_DMCPDiscovererTestsuite, Tests_DMCPDiscovererTestsuite );

static class TestDescription_DMCPDiscovererTestsuite_testClientAndServer : public CxxTest::RealTestDescription {
public:
 TestDescription_DMCPDiscovererTestsuite_testClientAndServer() : CxxTest::RealTestDescription( Tests_DMCPDiscovererTestsuite, suiteDescription_DMCPDiscovererTestsuite, 64, "testClientAndServer" ) {}
 void runTest() { suite_DMCPDiscovererTestsuite.testClientAndServer(); }
} testDescription_DMCPDiscovererTestsuite_testClientAndServer;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/FalseSerializationTestSuite.h"

static FalseSerializationTest suite_FalseSerializationTest;

static CxxTest::List Tests_FalseSerializationTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_FalseSerializationTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/FalseSerializationTestSuite.h", 94, "FalseSerializationTest", suite_FalseSerializationTest, Tests_FalseSerializationTest );

static class TestDescription_FalseSerializationTest_testSerializationDeserialization : public CxxTest::RealTestDescription {
public:
 TestDescription_FalseSerializationTest_testSerializationDeserialization() : CxxTest::RealTestDescription( Tests_FalseSerializationTest, suiteDescription_FalseSerializationTest, 96, "testSerializationDeserialization" ) {}
 void runTest() { suite_FalseSerializationTest.testSerializationDeserialization(); }
} testDescription_FalseSerializationTest_testSerializationDeserialization;

static class TestDescription_FalseSerializationTest_testTimeStamp35 : public CxxTest::RealTestDescription {
public:
 TestDescription_FalseSerializationTest_testTimeStamp35() : CxxTest::RealTestDescription( Tests_FalseSerializationTest, suiteDescription_FalseSerializationTest, 115, "testTimeStamp35" ) {}
 void runTest() { suite_FalseSerializationTest.testTimeStamp35(); }
} testDescription_FalseSerializationTest_testTimeStamp35;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlContainerTestSuite.h"

static RuntimeControlContainerTest suite_RuntimeControlContainerTest;

static CxxTest::List Tests_RuntimeControlContainerTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RuntimeControlContainerTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/RuntimeControlContainerTestSuite.h", 197, "RuntimeControlContainerTest", suite_RuntimeControlContainerTest, Tests_RuntimeControlContainerTest );

static class TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingNotSending : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingNotSending() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerTest, suiteDescription_RuntimeControlContainerTest, 199, "testRuntimeControlContainerRegularRunReceivingNotSending" ) {}
 void runTest() { suite_RuntimeControlContainerTest.testRuntimeControlContainerRegularRunReceivingNotSending(); }
} testDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingNotSending;

static class TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSending : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSending() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerTest, suiteDescription_RuntimeControlContainerTest, 263, "testRuntimeControlContainerRegularRunReceivingSending" ) {}
 void runTest() { suite_RuntimeControlContainerTest.testRuntimeControlContainerRegularRunReceivingSending(); }
} testDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSending;

static class TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppTwiceAsFastAsSC : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppTwiceAsFastAsSC() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerTest, suiteDescription_RuntimeControlContainerTest, 341, "testRuntimeControlContainerRegularRunReceivingSendingAppTwiceAsFastAsSC" ) {}
 void runTest() { suite_RuntimeControlContainerTest.testRuntimeControlContainerRegularRunReceivingSendingAppTwiceAsFastAsSC(); }
} testDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppTwiceAsFastAsSC;

static class TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppHalfAsFastAsSC : public CxxTest::RealTestDescription {
public:
 TestDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppHalfAsFastAsSC() : CxxTest::RealTestDescription( Tests_RuntimeControlContainerTest, suiteDescription_RuntimeControlContainerTest, 419, "testRuntimeControlContainerRegularRunReceivingSendingAppHalfAsFastAsSC" ) {}
 void runTest() { suite_RuntimeControlContainerTest.testRuntimeControlContainerRegularRunReceivingSendingAppHalfAsFastAsSC(); }
} testDescription_RuntimeControlContainerTest_testRuntimeControlContainerRegularRunReceivingSendingAppHalfAsFastAsSC;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConferenceClientModuleTestSuite.h"

static ConferenceClientModuleTest suite_ConferenceClientModuleTest;

static CxxTest::List Tests_ConferenceClientModuleTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ConferenceClientModuleTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/ConferenceClientModuleTestSuite.h", 118, "ConferenceClientModuleTest", suite_ConferenceClientModuleTest, Tests_ConferenceClientModuleTest );

static class TestDescription_ConferenceClientModuleTest_testConferenceClientModule : public CxxTest::RealTestDescription {
public:
 TestDescription_ConferenceClientModuleTest_testConferenceClientModule() : CxxTest::RealTestDescription( Tests_ConferenceClientModuleTest, suiteDescription_ConferenceClientModuleTest, 137, "testConferenceClientModule" ) {}
 void runTest() { suite_ConferenceClientModuleTest.testConferenceClientModule(); }
} testDescription_ConferenceClientModuleTest_testConferenceClientModule;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DMCPConnectionTestSuite.h"

static DMCPConnectionTestsuite suite_DMCPConnectionTestsuite;

static CxxTest::List Tests_DMCPConnectionTestsuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DMCPConnectionTestsuite( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/DMCPConnectionTestSuite.h", 38, "DMCPConnectionTestsuite", suite_DMCPConnectionTestsuite, Tests_DMCPConnectionTestsuite );

static class TestDescription_DMCPConnectionTestsuite_testClientAndServer : public CxxTest::RealTestDescription {
public:
 TestDescription_DMCPConnectionTestsuite_testClientAndServer() : CxxTest::RealTestDescription( Tests_DMCPConnectionTestsuite, suiteDescription_DMCPConnectionTestsuite, 51, "testClientAndServer" ) {}
 void runTest() { suite_DMCPConnectionTestsuite.testClientAndServer(); }
} testDescription_DMCPConnectionTestsuite_testClientAndServer;

#include "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TreeNodeTestSuite.h"

static TreeNodeTest suite_TreeNodeTest;

static CxxTest::List Tests_TreeNodeTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TreeNodeTest( "/home/msv/2013-mini-smart-vehicles/group-5/sources/OpenDaVINCI-msv/libopendavinci/testsuites/TreeNodeTestSuite.h", 19, "TreeNodeTest", suite_TreeNodeTest, Tests_TreeNodeTest );

static class TestDescription_TreeNodeTest_testSimpleTree : public CxxTest::RealTestDescription {
public:
 TestDescription_TreeNodeTest_testSimpleTree() : CxxTest::RealTestDescription( Tests_TreeNodeTest, suiteDescription_TreeNodeTest, 38, "testSimpleTree" ) {}
 void runTest() { suite_TreeNodeTest.testSimpleTree(); }
} testDescription_TreeNodeTest_testSimpleTree;

#include <cxxtest/Root.cpp>
