from bs4 import BeautifulSoup as bs
import requests
import sys
import json

def main():
	if len(sys.argv)<2:
		print "Usage : python zauba.py item_to_import"
		sys.exit()
	headers = {    "User-Agent": "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.52 Safari/536.5", "content-type":"text/html"}

	url = 'https://www.zauba.com/import-'+sys.argv[1]+'-hs-code.html'
	page = requests.get(url, headers= headers)

	soup = bs(page.text)
	data = []
	if soup.table:
		table = soup.table
		rows = table.find_all('tr')
		th = rows[0].find_all('th')
		info = {'date': '','hscode':'', 'desc':'', 'origin':'', 'port':'', 'unit':'', 'quantity':'', 'value':'', 'perunit':''}
		myfile = open("data.json","w")
		l = 1
		li = ['date', 'hscode', 'desc', 'origin', 'port', 'unit', 'quantity', 'value', 'perunit']

		for i in rows[1:]:
			info['s_no'] = l 
			k = 0
			for j in i:
				info[li[k]] = j.string
				k += 1
			print info
			myfile.write(json.dumps(info))
			l += 1
		myfile.close()
	else:
		print "No Info To Show !!"

if __name__ == '__main__':
	main()