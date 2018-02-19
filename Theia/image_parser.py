from PIL import Image
from datetime import datetime
import pytesseract
import requests
import platform
import sys
import argparse

parser = argparse.ArgumentParser(description='Receipt-Based product manager')
parser.add_argument('-V', '--version', action='version', version='%(prog)s 1.0')

def initialize():
	today = datetime.now().month() + "/" + datetime.now().day() + "/" +datetime.now().year()
	walmart_key = "zcnamdfwjd7udf7nfv7ftrdw"
	stores = ['Walmart']

if platform.system() == "Linux":
	# For arch linux
	pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
else:
	# For OSX
	pytesseract.pytesseract.tesseract_cmd = "/usr/local/bin/tesseract"

def generate_logfile(filetype, data, name):
	log = filetype + ":" + name
	logfile = open(log, "w+")
	logfile.write(data)
	logfile.close()

def acquire_data(receipt_name):
	print("Extracting receipt info...")
	unprocessed_data = pytesseract.image_to_string(Image.open(receipt_name), lang="eng")
	print("Unprocessed data gathered")
	extract_item_codes(unprocessed_data)

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
				walmart_item_lookup(item_codes)
		else:
			print("Error! store not recognized!")

def walmart_item_lookup(the_juice):
	# The juice is the codes
	print("Fetching data from Walmart API")
	item_names = {}
	for item_upc in the_juice:
		walmart_data = requests.get("http://api.walmartlabs.com/v1/items?apiKey="+ walmart_key +"&upc="+ item_upc)
		if (walmart_data['code'] != 4023) or (walmart_data['code'] != '4023'):
			item_names[walmart_data['itemId']] = walmart_data['name']
		else:
			generate_logfile('ERROR', item_upc, today)


if __name__ == "__main__":
	acquire_data('test_receipt.jpg')
	acquire_data('walmart_receipt_1.jpg')
	
