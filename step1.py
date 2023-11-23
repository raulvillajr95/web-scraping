# import urllib3
# from lxml import html

# # urlib3 section
# http = urllib3.PoolManager()
# r = http.request('GET', 'http://www.google.com')

# data_string = r.data.decode('utf-8', errors='ignore')

# tree = html.fromstring(data_string)

# links = tree.xpath('//a')

# for link in links:
#   print(link.get('href'))

import requests

r = requests.get('https://www.google.com')
print(r.text)