#!/usr/bin/env python3
from PIL import Image
from datetime import datetime
from pathlib import Path
import urllib2
import pytesseract
import requests
import platform
import sys
import argparse

PARSER_DATA_DIR = Path.home() / '.receipt-parser'

if platform.system() == "Linux":
	# For arch linux
	pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
else:
	# For OSX
	pytesseract.pytesseract.tesseract_cmd = "/usr/local/bin/tesseract"

# This script requires internet to run
def internet_on():
	try:
		urllib.urlopen('http://8.8.8.8', timeout = 1)
		return True
	except urllib2.URLError as err:
		return False

def initialize():
	today = datetime.now().month() + "/" + datetime.now().day() + "/" +datetime.now().year()
	walmart_key = "zcnamdfwjd7udf7nfv7ftrdw"
	stores = ['Walmart']

def parse_args() -> argparse.Namespace:
	parser = argparse.ArgumentParser(description='The food tracker with cow powers.')
	parser.add_argument('-V', '--version', action='version', version='%(prog)s 1.0')
	parser.add_argument('-a', '--acquire', action='store', type=string, help="Extract data from provided receipt")
	parser.add_argument('-m', '--manual', action='store', type=string, help="Manually enter item ID to be stored")
#parser.add_argument('l', '--logging', action='store', help="Enable logging of errors")
	subparsers = parser.add_subparsers(dest='cmd')
	return parser.parse_args()

def acquire_data(acquire: argparse.Namespace): 
	"""
	Read the receipt data from the given location
	and call helper functions
	"""
	print("Extracting receipt info...")
	raw_data = pytesseract.image_to_string(Image.open(acquire), lang="eng")
	print("Raw data gathered. Extracting item codes...")
	extract_item_codes(raw_data)

def manually_gather_data(manual: argparse.Namespace):
	"""
	Manually store item by ID and not UPC code
	"""
	print("Searching for item...")
	walmart_item_lookup(True, manual)


def generate_logfile(filetype, data, name):
	"""
	Generates a log file to record bad codes
	and other errors.
	"""
	log = filetype + ":" + name
	logfile = open(log, "w+")
	logfile.write(data)
	logfile.close()

def extract_item_codes(data):
	item_codes = list()
	for s in data.split(): 
		if s.isdigit() and len(s) > 9:
			item_codes.append(s)
		else:
			continue
	for store in stores:
		if store in data:
			if store == 'Walmart':
				walmart_item_lookup(False, item_codes)
		else:
			print("Error! store not recognized!")

def walmart_item_lookup(manual, the_juice):
	# The juice is the codes
	print("Fetching data from Walmart API")
	item_names = {}
	if manual:
		for item_id in the_juice:
			walmart_data = requests.get("http://api.walmartlabs.com/v1/items/" + item_id + "?apiKey=" + walmart_key + "&format=json")
			if (walmart_data['code'] != 4023) or (walmart_data['code'] != '4023'):
				item_names[walmart_data['itemId']] = walmart_data['name']
			else:
				generate_logfile('ERROR', item_upc, today)
	else:
		for item_upc in the_juice:
			walmart_data = requests.get("http://api.walmartlabs.com/v1/items?apiKey="+ walmart_key +"&upc="+ item_upc)
			if (walmart_data['code'] != 4023) or (walmart_data['code'] != '4023'):
				item_names[walmart_data['itemId']] = walmart_data['name']
			else:
				generate_logfile('ERROR', item_upc, today)

def main():
	args = parse_args()

	if args.acquire:
		
		

if __name__ == "__main__":
	if not internet_on():
		sys.exit(0)
	else:
		main()
