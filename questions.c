/*
 Daniel Cancelmo
 CSC 173 - Computation & Formal Systems
 Project 1
 Prof. Ferguson
 I attest that all work herein is my own and I did not collaborate with anyone.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"
#include "dfa.h"
#include "nfa.h"
#include "NFA-DFA.h"

//Exactly the string ab
DFA *ab() {
    printf("Exactly the string 'ab'\n");
    DFA *dfaAB = DFA_new(3);
    DFA_set_transition(dfaAB, 0, 'a', 1);
    DFA_set_transition(dfaAB, 1, 'b', 2);
    DFA_set_accepting(dfaAB, 2, TRUE);
    DFA_print(dfaAB);
    printf("ab: %d\n", DFA_execute(dfaAB, "ab"));
    printf("abc: %d\n", DFA_execute(dfaAB, "abc"));
    printf("zabd: %d\n", DFA_execute(dfaAB, "zabd"));
    printf("cd: %d\n", DFA_execute(dfaAB, "cd"));
    
    return dfaAB;
}

//Strings that begin with the letters 'ab'
DFA *ab_begin() {
    printf("Strings starting with 'ab'\n");
    DFA *dfaAB_begin = DFA_new(3);
    DFA_set_transition(dfaAB_begin, 0, 'a', 1);
    DFA_set_transition(dfaAB_begin, 1, 'b', 2);
    DFA_set_transition_all(dfaAB_begin, 2, 2);
    DFA_set_accepting(dfaAB_begin, 2, TRUE);
    DFA_print(dfaAB_begin);
    printf("abc: %d\n", DFA_execute(dfaAB_begin, "abc"));
    printf("zab: %d\n", DFA_execute(dfaAB_begin, "zab"));
    printf("asdf: %d\n", DFA_execute(dfaAB_begin, "asdf"));
    printf("cd: %d\n", DFA_execute(dfaAB_begin, "cd"));
    printf("cdab: %d\n", DFA_execute(dfaAB_begin, "cdab"));
    
    return dfaAB_begin;
}

//Binary strings with an even number of 1s
DFA *even1() {
    printf("Binary strings with an even number of 1s\n");
    DFA *dfa_even = DFA_new(3);
    DFA_set_transition(dfa_even, 0, '1', 1);
    DFA_set_transition(dfa_even, 1, '1', 2);
    DFA_set_transition(dfa_even, 2, '1', 1);
    DFA_set_transition(dfa_even, 0, '0', 0);
    DFA_set_transition(dfa_even, 1, '0', 1);
    DFA_set_transition(dfa_even, 2, '0', 2);
    DFA_set_accepting(dfa_even, 0, TRUE);
    DFA_set_accepting(dfa_even, 2, TRUE);
    DFA_print(dfa_even);
    printf("011: %d\n", DFA_execute(dfa_even, "011"));
    printf("110: %d\n", DFA_execute(dfa_even, "110"));
    printf("101: %d\n", DFA_execute(dfa_even, "101"));
    printf("01011: %d\n", DFA_execute(dfa_even, "01011"));

    return dfa_even;
}

//Binary strings with an even number of 0s and 1s
DFA *even1even2() {
    printf("Binary strings with an even number of 1s\n");
    DFA *dfa_even = DFA_new(4);
    DFA_set_transition(dfa_even, 0, '0', 1);
    DFA_set_transition(dfa_even, 1, '0', 0);
    DFA_set_transition(dfa_even, 2, '0', 3);
    DFA_set_transition(dfa_even, 3, '0', 2);
    DFA_set_transition(dfa_even, 0, '1', 3);
    DFA_set_transition(dfa_even, 3, '1', 0);
    DFA_set_transition(dfa_even, 1, '1', 2);
    DFA_set_transition(dfa_even, 2, '1', 1);
    DFA_set_accepting(dfa_even, 0, TRUE);
    DFA_print(dfa_even);
    printf("011: %d\n", DFA_execute(dfa_even, "011"));
    printf("1010: %d\n", DFA_execute(dfa_even, "1010"));
    printf("101: %d\n", DFA_execute(dfa_even, "101"));
    printf("101011: %d\n", DFA_execute(dfa_even, "101011"));
    printf("01011: %d\n", DFA_execute(dfa_even, "01011"));
    
    return dfa_even;
}

//Recgonizes strings with prefixes 'mr.', 'mrs.', 'miss', 'ms.'
DFA *prefix() {
    printf("Strings that start with 'mr.', 'mrs.', 'miss', and 'ms.'\n");
    DFA *prefix = DFA_new(8);
    DFA_set_transition(prefix, 0, 'm', 1);
    DFA_set_transition(prefix, 1, 'r', 2);
    DFA_set_transition(prefix, 2, 's', 3);
    DFA_set_transition(prefix, 2, '.', 4);
    DFA_set_transition(prefix, 3, '.', 4);
    DFA_set_transition(prefix, 1, 'i', 5);
    DFA_set_transition(prefix, 5, 's', 6);
    DFA_set_transition(prefix, 6, 's', 4);
    DFA_set_transition(prefix, 1, 's', 7);
    DFA_set_transition(prefix, 7, '.', 4);
    DFA_set_transition_all(prefix, 4, 4);
    DFA_set_accepting(prefix, 4, TRUE);
    DFA_print(prefix);
    printf("mr. k: %d\n", DFA_execute(prefix, "mr. k"));
    printf("mrs. q: %d\n", DFA_execute(prefix, "mrs. q"));
    printf("miss l: %d\n", DFA_execute(prefix, "miss l"));
    printf("ms. c: %d\n", DFA_execute(prefix, "ms. c"));
    printf("dr. f: %d\n", DFA_execute(prefix, "dr. f"));
    
    return prefix;
}

//Strings ending in 'man'
NFA *man() {
    printf("Strings ending in 'man'\n");
    NFA *manNFA = NFA_new(4);
    NFA_add_transition_all(manNFA, 0, 0);
    NFA_add_transition(manNFA, 0, 'm', 1);
    NFA_add_transition(manNFA, 1, 'a', 2);
    NFA_add_transition(manNFA, 2, 'n', 3);
    NFA_set_accepting(manNFA, 3, TRUE);
    printf("superman: %d\n", NFA_execute(manNFA, "superman"));
    printf("catwoman: %d\n", NFA_execute(manNFA, "catwoman"));
    printf("wonderboy: %d\n", NFA_execute(manNFA, "wonderboy"));
    
    return manNFA;
}

//Strings with more than one letter of 'washigto' or two 'n'
NFA *washington() {
    printf("Strings that conatain more than one letter of the same letter of 'washigto' or more than two 'n's\n");
    NFA *washingtonNFA = NFA_new(12);
    NFA_add_transition(washingtonNFA, 0, 'w', 1);
    NFA_add_transition(washingtonNFA, 1, 'w', 11);
    NFA_add_transition(washingtonNFA, 0, 'a', 2);
    NFA_add_transition(washingtonNFA, 2, 'a', 11);
    NFA_add_transition(washingtonNFA, 0, 's', 3);
    NFA_add_transition(washingtonNFA, 3, 's', 11);
    NFA_add_transition(washingtonNFA, 0, 'h', 4);
    NFA_add_transition(washingtonNFA, 4, 'h', 11);
    NFA_add_transition(washingtonNFA, 0, 'i', 5);
    NFA_add_transition(washingtonNFA, 5, 'i', 11);
    NFA_add_transition(washingtonNFA, 0, 'g', 6);
    NFA_add_transition(washingtonNFA, 6, 'g', 11);
    NFA_add_transition(washingtonNFA, 0, 't', 7);
    NFA_add_transition(washingtonNFA, 7, 't', 11);
    NFA_add_transition(washingtonNFA, 0, 'o', 8);
    NFA_add_transition(washingtonNFA, 8, 'o', 11);
    NFA_add_transition(washingtonNFA, 0, 'n', 9);
    NFA_add_transition(washingtonNFA, 9, 'n', 10);
    NFA_add_transition(washingtonNFA, 10, 'n', 11);

    NFA_add_transition_all(washingtonNFA, 0, 0);
    NFA_add_transition_all(washingtonNFA, 1, 1);
    NFA_add_transition_all(washingtonNFA, 2, 2);
    NFA_add_transition_all(washingtonNFA, 3, 3);
    NFA_add_transition_all(washingtonNFA, 4, 4);
    NFA_add_transition_all(washingtonNFA, 5, 5);
    NFA_add_transition_all(washingtonNFA, 6, 6);
    NFA_add_transition_all(washingtonNFA, 7, 7);
    NFA_add_transition_all(washingtonNFA, 8, 8);
    NFA_add_transition_all(washingtonNFA, 9, 9);
    NFA_add_transition_all(washingtonNFA, 10, 10);
    NFA_add_transition_all(washingtonNFA, 11, 11);

    NFA_set_accepting(washingtonNFA, 11, TRUE);
    printf("washington: %d\n", NFA_execute(washingtonNFA, "washington"));
    printf("washingtonwashington: %d\n", NFA_execute(washingtonNFA, "washingtonwashington"));
    printf("washingmachine: %d\n", NFA_execute(washingtonNFA, "washingmachine"));
    
    return washingtonNFA;
}

//Represents the most common letters in english and vowels
NFA *common() {
    printf("Strings that contain one of the most common constanants in English 'tnshrdl' once or two vowels\n");
    NFA *commonNFA = NFA_new(3);
    NFA_add_transition_str(commonNFA, 0, "tnshrdl", 1);
    NFA_add_transition_str(commonNFA, 0, "aeiouy", 2);
    NFA_add_transition_str(commonNFA, 2, "aeiouy", 1);
    NFA_add_transition_all(commonNFA, 0, 0);
    NFA_add_transition_all(commonNFA, 1, 1);
    NFA_add_transition_all(commonNFA, 2, 2);
    NFA_set_accepting(commonNFA, 1, TRUE);
    printf("queueing: %d\n", NFA_execute(commonNFA, "queueing"));
    printf("sfgbm: %d\n", NFA_execute(commonNFA, "sfgbm"));
    printf("ab: %d\n", NFA_execute(commonNFA, "ab"));
    printf("aba: %d\n", NFA_execute(commonNFA, "aba"));
    
    return commonNFA;
}

DFA *convert(NFA *nfa, char* name) {
    printf("Original DFA shown above. Now converting given NFA '%s' to a DFA. Compare to above original for accuracy: \n", name);
    DFA *dfa = NFA_DFA_Convert(nfa);
    free(nfa);
    if (strcmp(name, "man") == 0) {
        printf("superman: %d\n", DFA_execute(dfa, "superman"));
        printf("catwoman: %d\n", DFA_execute(dfa, "catwoman"));
        printf("wonderboy: %d\n", DFA_execute(dfa, "wonderboy"));
    } else if (strcmp(name, "washington") == 0) {
        printf("washington: %d\n", DFA_execute(dfa, "washington"));
        printf("washingtonwashington: %d\n", DFA_execute(dfa, "washingtonwashington"));
        printf("washingmachine: %d\n", DFA_execute(dfa, "washingmachine"));
    } else if (strcmp(name, "common") == 0) {
        printf("queueing: %d\n", DFA_execute(dfa, "queueing"));
        printf("sfgbm: %d\n", DFA_execute(dfa, "sfgbm"));
        printf("ab: %d\n", DFA_execute(dfa, "ab"));
        printf("aba: %d\n", DFA_execute(dfa, "aba"));
    }
    
    return dfa;
}

