from PIL import Image
from datetime import datetime
import pytesseract
import requests
import platform
import sys

today = datetime.now().month() + "/" + datetime.now().day() + "/" +datetime.now().year()
walmart_key = "zcnamdfwjd7udf7nfv7ftrdw"

if platform.system() == "Linux":
	# For arch linux
	pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
else:
	# For OSX
	pytesseract.pytesseract.tesseract_cmd = "/usr/local/bin/tesseract"

#Make this static for now. It will be passed as a command line input later
store = "Walmart"

# Grab the receipt info
#print(pytesseract.image_to_string(Image.open('test_receipt.jpg'), lang="eng"))

def generate_logfile(filetype, data, name):
	log = filetype + ":" + name
	logfile = open(log, "w+")
	logfile.write(data)
	logfile.close()

def acquire_data(receipt_name):
	print("Extracting receipt info...")
	unprocessed_data = pytesseract.image_to_string(Image.open(receipt_name), lang="eng")
	print("Unprocessed data gathered")
#print(unprocessed_data)
	extract_item_codes(unprocessed_data)

def extract_item_codes(data):
	item_codes = list()
	for s in data.split(): 
		if s.isdigit() and len(s) > 4:
			item_codes.append(s)
		else:
			continue
	for code in item_codes:
		print(code+"\n")

def walmart_item_lookup(data, the_juice):
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
	
