import scrapy

class ReceiptspiderItem(scrapy.Item):
	store = scrapy.Field()
	file_urls = scrapy.Field()
	files = scrapy.Field()
