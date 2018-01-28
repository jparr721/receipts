from PIL import Image
import pytesseract

pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"

print(pytesseract.image_to_string(Image.open('test_receipt.jpg'), lang="eng"))
