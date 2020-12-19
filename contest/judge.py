# !/usr/bin/python3

'''
LOCAL JUDGE for Competitive Programming
NOTE: This judge is not useful when there are more than one correct answer

@author Utkarsh Patel (utkarsh512)
'''

import os

class FormattingError(Exception):
    pass

class WrongAnswer(Exception):
    pass

def getOutputs():
    os.system('{0} gentest.cpp'.format(CM))
    os.system('a')
    os.system('{0} a.cpp'.format(CR))
    os.system('a')
    os.system('{0} brute.cpp'.format(CM))
    os.system('a')

class TestCase:
    def __init__(self, test_id, testcase, testcase_output, testcase_answer, datatypes):
        '''
        Initializing the TestCase object
        :param testcase: List of lines
        :param testcase_output: List of lines
        :param testcase_answer: List of lines
        '''
        self.id = test_id
        self.input = testcase
        self.output = testcase_output
        self.answer = testcase_answer
        self.dtypes = datatypes

    def convert(self, lst):
        '''
        Utility to convert list into text
        :param lst: Python list
        :return: Text
        '''
        s = ''
        for _ in lst:
            s += _
        flag = (len(s) > maxLength)
        s = s[: min(len(s), maxLength)]
        if flag:
            s += '...\n'
        return s

    def parse(self, label):
        s = label.capitalize() + '\n'
        s += self.convert(self.__dict__[label])
        s += '\n' + '-' * 50 + '\n'
        return s

    def separate(self, s, dtype):
        s = s.strip().split()
        s = [dtype(x) for x in s]
        return s

    def __str__(self):
        s = 'Test {0}'.format(self.id) + '\n' + '-' * 50 + '\n'
        s += self.parse('input')
        s += self.parse('output')
        s += self.parse('answer')
        return s

    def verdict(self):
        print(self)
        if len(self.output) != len(self.answer):
            raise FormattingError('OUTPUT and ANSWER contain different number of lines.')
        for i in range(outputLineCount):
            self.output[i] = self.separate(self.output[i], self.dtypes[i])
            self.answer[i] = self.separate(self.answer[i], self.dtypes[i])
            if len(self.output[i]) != len(self.answer[i]):
                raise FormattingError('Token count differs in LINE {0}'.format(i + 1))
        for i in range(outputLineCount):
            for j in range(len(self.output[i])):
                if self.output[i][j] != self.answer[i][j]:
                    raise WrongAnswer('In line {0} - token {1} differs - expected: \'{2}\', found: \'{3}\''.format(i + 1, j + 1,
                                                                                                                   self.answer[i][j],
                                                                                                                   self.output[i][j]))
        print('Passed\n' + '-' * 50 + '\n\n')

def run(testcase_id, testcase, testcase_output, testcase_answer, dtypes):
    TC = TestCase(testcase_id, testcase, testcase_output, testcase_answer, dtypes)
    TC.verdict()


if __name__ == '__main__':
    multiple_testcases = False
    # True if we are dealing with multiple testcases, False otherwise
    inputLineCount = 1
    # Number of lines per test case
    outputLineCount = 1
    # Number of lines in output of each test case
    maxLength = 256
    # if count of character in a line exceed this, it will be truncated
    datatypes = [int] * 300

    CM = 'g++ -pedantic -std=c++17 -DLOCAL -O2 -Wall -Wl,--stack=268435456 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -Wshadow -Wfloat-equal'
    CO = 'g++ -pedantic -std=c++17 -DLOCAL -DREAD_FILE -O2 -Wall -Wl,--stack=268435456 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -Wshadow -Wfloat-equal'
    CR = 'g++ -pedantic -std=c++17 -DLOCAL -DREAD_FILE -DCHK_RNDM -O2 -Wall -Wl,--stack=268435456 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -Wshadow -Wfloat-equal'

    getOutputs()

    testcases = open('input.txt', 'r')
    output = open('output.txt', 'r')
    answer = open('output_b.txt', 'r')
    TT = testcases.readlines()
    OO = output.readlines()
    AA = answer.readlines()
    testCount = 1
    if multiple_testcases:
        testCount = int(TT[0].strip())
        TT = TT[1:]
    assert(len(TT) == testCount * inputLineCount)
    assert(len(OO) == testCount * outputLineCount)
    assert(len(AA) == testCount * outputLineCount)
    for i in range(testCount):
        testcase = []
        testcase_output = []
        testcase_answer = []
        for j in range(inputLineCount):
            testcase.append(TT[i * inputLineCount + j])
        for j in range(outputLineCount):
            testcase_output.append(OO[i * outputLineCount + j])
            testcase_answer.append(AA[i * outputLineCount + j])
        run(i + 1, testcase, testcase_output, testcase_answer, datatypes)
    testcases.close()
    output.close()
    answer.close()

