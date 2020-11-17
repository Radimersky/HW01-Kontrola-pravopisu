#include <stdio.h>  // printf
#include <string.h> // strlen

#include "hw01.h"
#include "hw01_tests.h"

/*
 * This file uses a minimalistic testing framework. You are not required to
 * understand it perfectly and you will see a much better one
 * with more features later in the course.
 *
 * For now, you can write simple tests below lines marked with TODO.
 * All you need are two functions(*) SHOULD_PASS and SHOULD_FAIL.
 *
 * For instance,
 *
 *      TEST_FUNCTION(noTwoConsecutiveSpaces);
 *
 * says that the function being tested is "noTwoConsecutiveSpaces".
 * Then,
 *
 *      SHOULD_PASS("Hello, World");
 *
 * requires that the function returns true on "Hello, World".
 * Otherwise the test fails and you need to fix your function.
 * Similartly,
 *
 *      SHOULD_FAIL("Hello,  world");
 *
 * asserts that noTwoConsecutiveSpaces returns false on given input,
 * otherwise the test fails. You can call as many SHOULD_PASS or SHOULD_FAIL
 * as you like, with different parameters.
 *
 * (*) Those are not really functions, but sssh!
 */

TEST(noTwoConsecutiveSpaces) {
    TEST_FUNCTION(noTwoConsecutiveSpaces);

    SHOULD_PASS("Hello, world");
    SHOULD_PASS( "H e l l o , w o r l d ");
    SHOULD_FAIL("Hello,  world");
    SHOULD_FAIL("Hello,  world  ");
    SHOULD_FAIL("    Hello,  world  ");

    // You can write your own tests below this line.

    // TODO

    // ... but ABOVE this one.
    TEST_DONE;
}

TEST(sentenceStartsWithUppercase) {
    TEST_FUNCTION(sentenceStartsWithUppercase);

    SHOULD_PASS("Ahoj konicci.");
    SHOULD_PASS("Ahoj konicci. Ahoj");
    SHOULD_PASS("   Ahoj   konicci. {}[]((((D.");
    SHOULD_PASS("Ahoj konicci.Ahoj konicci!  Ahoj konicci?  ");
    SHOULD_PASS("   Ahoj   konicci.");
    SHOULD_PASS("Ahoj ,,85konicci.");
    SHOULD_PASS("Ahoj KOOONonicci C.");
    SHOULD_PASS("Ahoj");
    SHOULD_PASS("Ahoj.World");
    SHOULD_PASS("Ahoj.  World");
    SHOULD_PASS("]{  B");

    SHOULD_FAIL("ahoj svete.");
    SHOULD_FAIL("aAhoj svete.");
    SHOULD_FAIL("ahoj svete..");
    SHOULD_FAIL("ahoj svete. !");
    SHOULD_FAIL("?Ahoj svete. !");
    SHOULD_FAIL(" !?");
    SHOULD_FAIL("Ahoj konicci.ahoj k.");
    SHOULD_FAIL("Ahoj konicci.  ?!Ahoj k.");
    SHOULD_FAIL("}");
    SHOULD_FAIL("}](");
    SHOULD_FAIL("}](,.:");
    SHOULD_FAIL(".");
    SHOULD_FAIL(".B");
    SHOULD_FAIL(".Sa.");
    SHOULD_FAIL("");
    SHOULD_FAIL("");


    TEST_DONE;
}

TEST(allSentencesAreClosed) {
    TEST_FUNCTION(allSentencesAreClosed);

    SHOULD_PASS("Ahoj konicci. Pepa.");
    SHOULD_PASS("Ahoj konicci.");
    SHOULD_PASS("Ahoj451() konicci. {]");
    SHOULD_PASS("a.");
    SHOULD_PASS("}.a.");
    SHOULD_PASS("ahoj konicci. ahoj.");
    SHOULD_PASS(".");
    SHOULD_PASS(".?");
    SHOULD_PASS("Ahoj. . ?");
    SHOULD_PASS("..");
    SHOULD_PASS(". .");
    SHOULD_PASS("]");
    SHOULD_PASS("");

    SHOULD_FAIL("Ahoj konicci");
    SHOULD_FAIL("Ahoj konicci. ahoj[]");


    TEST_DONE;
}

TEST(noSpaceBeforeSeparators) {
    TEST_FUNCTION(noSpaceBeforeSeparators);

    SHOULD_PASS("Ahoj konicci. Pepa.");
    SHOULD_PASS(".");
    SHOULD_PASS(".,?");
    SHOULD_PASS(". {}{?");
    SHOULD_PASS(" ");
    SHOULD_PASS(". ");
    SHOULD_PASS("");
    SHOULD_PASS("safd");

    SHOULD_FAIL("Ahoj. koni ,cci");
    SHOULD_FAIL(" ?");
    SHOULD_FAIL(" { } . {");

    TEST_DONE;
}

TEST(spaceAfterSeparators) {
    TEST_FUNCTION(spaceAfterSeparators);

    SHOULD_PASS("Ahoj konicci. Pepa.");
    SHOULD_PASS(".");

    SHOULD_PASS(" . {}{?");
    SHOULD_PASS(" ");
    SHOULD_PASS(". ");
    SHOULD_PASS("");
    SHOULD_PASS("safd[");

    SHOULD_FAIL(".,?");
     SHOULD_FAIL("..");
    SHOULD_FAIL("Ahoj. koni ,cci");
    SHOULD_PASS(" ?");
    SHOULD_PASS(" { } .  {");

    TEST_DONE;
}

TEST(properParenthesesPairing) {
    TEST_FUNCTION(properParenthesesPairing);

    SHOULD_PASS(".");
    SHOULD_PASS("asda44");
    SHOULD_PASS(" ., {} [? fsdf45]");
    SHOULD_PASS(" ");
    SHOULD_PASS(". ");
    SHOULD_PASS("First (sentence. Second) sentence.");
    SHOULD_PASS("first (sentence. second) sentence.");

    SHOULD_FAIL(")(");
    SHOULD_FAIL("(Ahoj ");
    SHOULD_FAIL("(Ahoj){ ");
    SHOULD_FAIL("({})");

    TEST_DONE;
}

TEST(noParenthesesSentenceCrossing) {
    TEST_FUNCTION(noParenthesesSentenceCrossing);
    SHOULD_PASS("(a.)");
    SHOULD_PASS("sente(c)e.");
    SHOULD_PASS("sente(c)e");
    SHOULD_PASS("sentece.");
    SHOULD_PASS("sentece");
    SHOULD_PASS("()");
    SHOULD_PASS("sente(c)e");
    SHOULD_PASS("().");
    SHOULD_PASS("(.)");
    SHOULD_PASS(".(.).");
    SHOULD_PASS("(Alfa. Beta.) Gama.");
    SHOULD_FAIL("Sen(.sentec)e.");
    SHOULD_FAIL("(a).");

    TEST_DONE;
}

TEST(noSpaceBeforeClosingOrAfterOpeningApostrophe) {
    TEST_FUNCTION(noSpaceBeforeClosingOrAfterOpeningApostrophe);



    TEST_DONE;
}

/****  YOU SHOULD NOT EDIT ANYTHING BELOW THIS LINE  *************************/

int main(void)
{
    TEST_RUN(sentenceStartsWithUppercase);
    TEST_RUN(noSpaceBeforeSeparators);
    TEST_RUN(noTwoConsecutiveSpaces);
    TEST_RUN(spaceAfterSeparators);
    TEST_RUN(properParenthesesPairing);
    TEST_RUN(noParenthesesSentenceCrossing);
    TEST_RUN(allSentencesAreClosed);
    TEST_RUN(noSpaceBeforeClosingOrAfterOpeningApostrophe);
    return 0;
}
