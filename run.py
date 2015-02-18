# -*- coding: utf-8 -*-

from subprocess import Popen, PIPE, STDOUT
from os import system

tests = []
answers = []

def read_tests():
	global tests
	global answers
	is_test = 1
	test = ''
	answer = ''
	with open('tests') as f:
		for line in f.readlines():
			if 'входные данные' in line or 'nput' in line or (not is_test and line == '\n'):
				is_test = 1
				if answer != '':
					answers.append(answer)
					answer = ''
			elif 'выходные данные' in line or 'utput' in line or (is_test and line == '\n'):
				is_test = 0
				if test != '':
					tests.append(test)
					test = ''
			elif is_test:
				test += line.lstrip(' ') 
			else:
				answer += line.lstrip(' ')

		if answer != '':
					answers.append(answer)

def check(answer1, answer2):
	answer1_lines = answer1.rstrip('\n').split('\n') 
	answer2_lines = answer2.rstrip('\n').split('\n') 
	if len(answer1_lines) != len(answer2_lines):
		return False

	for i in xrange(0, len(answer1_lines)):
		if answer1_lines[i].rstrip() != answer2_lines[i].rstrip():
			return False
	return True

def main():
	read_tests()

	if len(tests) != len(answers):
		print 'Something is wrong with tests'
		print 'tests len = ', len(tests)
		print 'answers len = ', len(answers)

	system('g++ -std=c++11 task.cpp -o task')
	
	for i in xrange(0, len(tests)):
		p = Popen(['./task'], stdout = PIPE, stdin = PIPE, stderr = STDOUT)
		result = p.communicate(input = tests[i])[0]
		verdict = 'Test ' + str(i) + ':' 
		if check(result, answers[i]):
			verdict += 'WIN'
		else:
			verdict += 'FAIL\n'
			verdict += 'Your result:\n'
			verdict += result + '\n'
			verdict += 'Right answer:\n'
			verdict += answers[i] + '\n'
		print verdict

if __name__ == '__main__':
    main()
