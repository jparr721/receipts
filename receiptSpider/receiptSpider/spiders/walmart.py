from receiptSpider.items import ReceiptspiderItem
import datetime
import scrapy

class WalmartSpider(scrapy.Spider):
	name = "receipt-spider"
	start_urls = ['https://www.bing.com/images/search?q=Walmart+Receipt&qs=n&form=QBILPG&sp=-1&pq=walmart+receipt&sc=8-15&sk=&cvid=07810D45C1AE4B2996877B396B16E72D', 'https://www.google.com/search?q=walmart+receipt&client=firefox-b-1-ab&source=lnms&tbm=isch&sa=X&ved=0ahUKEwiQnKTYsbPZAhUm64MKHQ0oASQQ_AUICigB&biw=1898&bih=935']
	def parse(self, response):
		url = response.css("div a img.rg_ic").xpath("a.rg_l")
		yield scrapy.Request(url.xpath("@href").extract_first(), self.parse_page)
	
	def parse_page(self, response):
		for href in response.xpath("//a"):
			print("Temp")
			#Fix the css selectors here
