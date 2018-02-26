import os
from setuptools import setup

def read(filename):
	return open(os.path.join(os.path.dirname(__file__), filename)).read()

setup(
	name='receipt',
	version='1.0.0',
	author='Jarred Parr',
	author_email='jparr721@gmail.com',
	install_requires=['PIL', 'pytesseract'],
	scripts=['bin/receipts'],
	description='Simple receipt data management',
	license='MIT',
	long_description=read('README.md'),
     )
