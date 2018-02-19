from receiptSpider.items import ReceiptspiderItem
import datetime
import scrapy

class WalmartSpider(scrapy.Spider):
	name = "storereceipt-spider"
	start_urls = []

