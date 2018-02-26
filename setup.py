import os
from setuptools import setup

def read(filename):
	return open(os.path.join(os.path.dirname(__file__), filename)).read()

setup(
	name='receipt',
	version='1.0.0',
	author='Jarred Parr',
	install_requires=['PIL'],
	scripts=['bin/receipts'],
	author_email='jparr721@gmail.com',
	description='Simple receipt data management',
	license='MIT',
	long_description=read('README.md'),
     )
