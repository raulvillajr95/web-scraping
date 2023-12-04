from bs4 import BeautifulSoup
import requests
import os, os.path, csv

listingurl = "http://www.google.com"

response = requests.get(listingurl)
soup = BeautifulSoup(response.text, "html.parser")

listings = []
for rows in soup.find_all("div"):
  print(rows)
  print('\n')
