#include "catch_amalgamated.hpp"
#include "ProgramState.hpp"
#include "Statement.hpp"
#include "MoveInstruction.hpp"
#include "AddInstruction.hpp"
#include "SubtractionInstruction.hpp"
#include "CmpInstruction.hpp"
#include "JmpInstruction.hpp"
#include "JLInstruction.hpp"
#include "JEInstruction.hpp"
#include "EndInstruction.hpp"
#include "runSim.hpp"
#include <fstream>
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails,
// your score for the portion will be zero, regardless of other considerations.

namespace
{

        /*
        This LOOKS LIKE a lot of test cases!
        Remember you DO NOT need to pass every case the first time you build.
        build and run tests for the starting code, and look through the case(s) that fail.
        Read the description in the test files.

        Decide which one you think will be the easiest to achieve:  what is the smallest amount of programming you can do to pass one more test case?  Write that code and find out.  If you now pass it, repeat -- what is the smallest amount of programming you can do to pass one more test case (without causing any previously-passing test cases to now fail).

        Believe it or not, this will make programming a lot easier.  In future projects, you might want to write a lot of different test cases yourself at the beginning, based on reading the skeleton code and the project requirements, and then try the above approach.  You might find yourself turning what feels like a very large and intimidating programming assignment into a series of small, very manageable mini-projects.

        */

        TEST_CASE("StoreAConstant", "[RequiredMoveOperations]")
        {
                ProgramState ps;
                MoveInstruction m1{"eax", "15"};
                m1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);
        }

        TEST_CASE("MoveAConstant", "[RequiredMoveOperations]")
        {
                ProgramState ps;
                MoveInstruction m1{"eax", "15"};
                m1.execute(&ps);
                MoveInstruction m2{"ebx", "eax"};
                m2.execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);
                REQUIRE(ps.getRegister(1) == 15);
        }

        TEST_CASE("MoveUsesPolymorphism", "[RequiredMoveOperations]")
        {
                ProgramState ps;
                Statement *m1 = new MoveInstruction{"eax", "15"};
                m1->execute(&ps);
                Statement *m2 = new MoveInstruction{"ebx", "eax"};
                m2->execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);
                REQUIRE(ps.getRegister(1) == 15);
        }

        TEST_CASE("AddAConstant", "[RequiredArithmeticOperations]")
        {
                ProgramState ps;
                MoveInstruction m1("eax", "15");
                m1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);

                AddInstruction ai1("eax", "20");
                ai1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 35);
        }

        TEST_CASE("AddARegister", "[RequiredArithmeticOperations]")
        {
                ProgramState ps;
                MoveInstruction m1("eax", "15");
                m1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);

                MoveInstruction m2("ebx", "20");
                m2.execute(&ps);
                REQUIRE(ps.getRegister(1) == 20);

                AddInstruction ai1("eax", "ebx");
                ai1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 35);
        }

        // This test case is NOT REQUIRED to be eligible for grading.
        // Remember that does not mean that this functionality won't
        // be graded;  rather, it just means this test does not affect
        // your eligibility to be graded.
        // This is provided to demonstrate functionality of the subtract operation.
        TEST_CASE("Subtraction", "[FYI]")
        {
                ProgramState ps;
                MoveInstruction m1{"eax", "15"};
                m1.execute(&ps);
                REQUIRE(ps.getRegister(0) == 15);

                MoveInstruction m2{"ebx", "20"};
                m2.execute(&ps);
                REQUIRE(ps.getRegister(1) == 20);

                SubtractionInstruction si1{"eax", "ebx"};
                si1.execute(&ps);
                REQUIRE(ps.getRegister(0) == -5);
        }

        // [RequiredAllOperations] does an unconditional jump and the program counter changes appropriately.

        TEST_CASE("UnconditionalJump", "[RequiredAllOperations]")
        {
                ProgramState ps;
                JmpInstruction js{"5"};
                js.execute(&ps);
                REQUIRE(ps.getCounter() == 5);
        }

        // "Full Programs" test cases use the full set of available operations,
        // although some individual programs may only use a subset.

        TEST_CASE("StoreAConstantAsAProgram", "[RequiredFullPrograms]")
        {
                std::ifstream in{"prog1.txt"};
                ProgramState ps;
                runSimulator(in, &ps);
                REQUIRE(ps.getRegister(0) == 15);
                REQUIRE(ps.getRegister(1) == 20);
        }

        TEST_CASE("MoveAConstantAsAProgram", "[RequiredFullPrograms]")
        {
                std::ifstream in{"prog2.txt"};
                ProgramState ps;
                runSimulator(in, &ps);
                REQUIRE(ps.getRegister(0) == 15);
                REQUIRE(ps.getRegister(1) == 15);
        }

        TEST_CASE("TestingUnconditionalJump", "[RequiredFullPrograms]")
        {
                std::ifstream in{"test.txt"};
                ProgramState ps;
                runSimulator(in, &ps);
                REQUIRE(ps.getRegister(0) == 16);
                REQUIRE(ps.getRegister(1) == 10);
                REQUIRE(ps.getCounter() == 6);
        }

        TEST_CASE("TestingLessThanConditionalJUmp", "[RequiredFullPrograms]")
        {
                std::ifstream in{"test1.txt"};
                ProgramState ps;
                runSimulator(in, &ps);
                REQUIRE(ps.getRegister(0) == 15);
                REQUIRE(ps.getRegister(1) == 11);
                REQUIRE(ps.getCounter() == 9);
        }

        TEST_CASE("TestingEqConditionalJUmp", "[RequiredFullPrograms]")
        {
                std::ifstream in{"test2.txt"};
                ProgramState ps;
                runSimulator(in, &ps);
                REQUIRE(ps.getRegister(0) == 10);
                REQUIRE(ps.getRegister(1) == 12);
                REQUIRE(ps.getCounter() == 12);
        }

} // end namespace
