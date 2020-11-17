#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "hw01.h"

/****  UTILITIES  ************************************************************/

/*
 * Returns true if and only if 'c' is one of the characters of 'str'.
 *
 * DO NOT EDIT THIS FUNCTION, it is not part of your homework.
 * You can, however, use it to make your life easier, like this:
 *
 *      if (isOneOf(c, str)) {
 *          // this will execute if c is contained in str
 *      } else {
 *          // this will execute otherwise
 *      }
 *
 * For instance,
 *      isOneOf(' ', "Hello, World!")   -> true
 *      isOneOf(' ', "Pocahontas")      -> false
 *      isOneOf('.', "Hello, World!")   -> false
 *      isOneOf('!', "Hello, World!")   -> true
 */
bool isOneOf(char c, char str[])
{
    return strchr(str, c) != NULL;
}

/****  HERE BEGINS YOUR HOMEWORK  ********************************************/

/*
 * There shall be no two consecutive spaces in the string.
 * You are to FIND and FIX an error in this code.
 *
 * Examples:
 *  Wrong: "Hello  world."
 *  Wrong: "Hello.  World."
 *  Right: "Hello world."
 *  Right: "Hello. Wonderful. World."
 */
bool noTwoConsecutiveSpaces(char str[], size_t len)
{
    for (size_t i = 0; i < len; i++) {
        if (isspace(str[i]) && isspace(str[i + 1]))
            return false;
    }
    return true;
}

//Returns true if char c is valid sentence starter.
bool isStarter(char c)
{
    if (c == ' ' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
        return false;
    }
    return true;
}

bool isEnder(char c)
{
    if (c == '.' || c == '!' || c == '?') {
        return true;
    }
    return false;
}

bool isSeparator(char c)
{
    if (c == '.' || c == '!' || c == '?' || c == ',') {
        return true;
    }
    return false;
}

bool isOpeningBracket(char c)
{
    if (c == '(' || c == '{' ||  c == '[') {
        return true;
    }
    return false;
}

bool isClosingBracket(char c)
{
    if (c == ')' || c == '}' || c == ']') {
        return true;
    }
    return false;
}


/**
 * The string represents a list of sentences. A sentence ends with with a
 * '.', '?', or a '!' sign, and starts with the first nonspace character
 * in the string or after the end of the previous sentence.
 *
 * Hint: see 'isupper' function
 */
bool sentenceStartsWithUppercase(char str[], size_t len)
{
    bool senStart = true;
    bool atleastOneSen = false;

    for (size_t i = 0; i < len; i++) {
        // Checks if sentence starts with uppercase and if so, then variable 'senStart' is set to false so the end of the sentence can be searched for.
        if (senStart == true) {
            if (isStarter(str[i]) && isupper(str[i])) {
                atleastOneSen = true; //One sentence occured.
                senStart = false;
                continue;
            } else if (isStarter(str[i])) { // if the char is one of those that does start sentence but is not uppercase.
                return false;
            }
        }

        //Searching for ending char.
        if (senStart == false) {
            if (isEnder(str[i])) {
                senStart = true;
            }
        }
    }
    //When no sentence occurs in the whole string.
    if (atleastOneSen == false) {
        return false;
    }

    return true;
}

/*
 * Every sentence in the string ends with '.', '?' or a '!'.
 */
bool allSentencesAreClosed(char str[], size_t len)
{
    bool senStart = true;

    for (size_t i = 0; i < len; i++) {
        if (senStart == true) {
            if (isEnder(str[i])) { // Aprooves sentences like ".", "!", "?"
                continue;
            }

            if (isStarter(str[i])) {
                senStart = false;
                continue;
            }
        }
        //Searching for ending char.
        if (senStart == false) {
            if (isEnder(str[i])) {
                senStart = true;
            }
        }
    }

    //Ensures that sentence ender is at the end of the string
    if (senStart == true) {
       return true;
    }

    return false;

}

/**
 * There is no separator with a space before it.
 *
 *  Wrong: "Hello, World !"
 *  Wrong: "Hello , World!"
 *  Right: "Hello, World!"
 */
bool noSpaceBeforeSeparators(char str[], size_t len)
{
    for (size_t i = 1; i < len; i++) {
        if (isSeparator(str[i]) && str[i - 1] == ' ') {
            return false;
        }
    }
    return true;
}

/**
 * Every seprator (i.e. '.', ',', '!' or '?') is followed by a space,
 * with the exception of the separator is the last character in the string.
 *
 *  Wrong: "Hello,world."
 *  Right: "Hello, world."
 */
bool spaceAfterSeparators(char str[], size_t len)
{
    if (len < 2) {
        return true;
    }
    for (size_t i = 0; i < len - 1; i++) {

        if (isSeparator(str[i]) && str[i + 1] != ' ') {
            return false;
        }
    }
    return true;
}

/**
 * Every opening bracket '(' is properly closed with ')' and there are no
 * nested parentheses.
 *
 *  Wrong: ":("
 *  Right: "Hello world (again)!"
 *  Wrong: "Hello, (tiny (puny)) world!"
 */
bool properParenthesesPairing(char str[], size_t len)
{
    int roundCount = 0;
    int sharpCount = 0;
    int edgyCount = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] == '(') {
            roundCount++;
        } else if (str[i] == '{') {
            sharpCount++;
        } else if (str[i] == '[') {
            edgyCount++;
        } else if (str[i] == ')') {
            roundCount--;
        } else if (str[i] == '}') {
            sharpCount--;
        } else if (str[i] == ']') {
            edgyCount--;
        }

        if (roundCount < 0 || sharpCount < 0 || edgyCount < 0) { //exaple: ")(" should fail
            return false;
        }

        if ((roundCount + sharpCount + edgyCount) > 1) { // nested parentheses wont pass
            return false;
        }
    }
    if (roundCount == 0 && sharpCount == 0 && edgyCount == 0) {
        return true;
    }

    return false;
}

/****  BONUS  ****************************************************************/

/*
 * You are not required to implement the following functions, but you
 * can get up to 3 bonus points if you do it correctly.
 */

/**
 * Parentheses should not cross sencentes. That is, if a bracket is opened
 * outside of a sentence, it must be closed outside as well.
 * On the other hand, a bracket opened inside a sentence has to be
 * closed before the sentence ends.
 *
 *  Right: "(First sentence. Second sentence.) Third sentence."
 *  Right: "First (inside) sentence."
 *  Wrong: "First (sentence. Second) sentence."
 *  Wrong: "(First sentence. Second) sentence."
 */
bool noParenthesesSentenceCrossing(char str[], size_t len)
{
    //fix Alfa(. Be) ta.
    bool senStart = true; //Determines if algorithm is searching for start or end of sentence
    bool isOutside;
    int roundCount = 0;
    int sharpCount = 0;
    int edgyCount = 0;

    for (size_t i = 0; i < len; i++) {
        if (senStart == true) {
            if (isEnder(str[i])) { // Aprooves sentences like ".", "!", "?"
                continue;
            }

            if (isStarter(str[i])) { //Finds sentence begining
                senStart = false;
                continue;
            }
        }

        if (isOpeningBracket(str[i]) || isClosingBracket(str[i])) { // If char is bracket
            if (str[i] == '(') {
                roundCount++;
            } else if (str[i] == '{') {
                sharpCount++;
            } else if (str[i] == '[') {
                edgyCount++;
            } else if (str[i] == ')') {
                roundCount--;
            } else if (str[i] == '}') {
                sharpCount--;
            } else if (str[i] == ']') {
                edgyCount--;
            }

            if (isOpeningBracket(str[i])) {
                if (senStart == true) { //Now we know bracket is outside or inside sentence.
                    isOutside = true;
                } else {
                    isOutside = false;
                }
            }

            if (isClosingBracket(str[i])) {
                if ((senStart == true && isOutside == false) || (senStart == false && isOutside == true)) { //Opening bracket is outside, but closing is inside or vice versa.
                    return false;
                }
            }

            if (roundCount < 0 || sharpCount < 0 || edgyCount < 0) { //exaple: ")(" should fail
                return false;
            }

            if ((roundCount + sharpCount + edgyCount) > 1) { // nested parentheses wont pass
                return false;
            }

        }

        //Searching for ending char.
        if (senStart == false) {
            if (isEnder(str[i])) {
                if ((roundCount > 0 || sharpCount > 0 || edgyCount > 0) && isOutside == false) { // If brackets are opened and closed in different sentences
                    return false;
                }
                senStart = true;
            }
        }
    }
    // end of loop

    /*
    Ensures that sentence ender is at the end of the string
    if (senStart == true) {
       return true;
    }
    */

    if (roundCount == 0 && sharpCount == 0 && edgyCount == 0) { // If all brackets are correctly closed
        return true;
    }

    return false;
}

/**
 * There can be double quotes inside the text '"', but always in pair.
 * Opening quote must not be followed by a space and similarly
 * there can be no space before the closing quote.
 */
bool noSpaceBeforeClosingOrAfterOpeningApostrophe(char str[], size_t len)
{
    return true;
}
