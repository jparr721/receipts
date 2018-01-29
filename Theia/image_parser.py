from PIL import Image
import pytesseract

#pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
pytesseract.pytesseract.tesseract_cmd = "/usr/local/bin/tesseract"

# Grab the receipt info
print(pytesseract.image_to_string(Image.open('test_receipt.jpg'), lang="eng"))
