# import requests
from bs4 import BeautifulSoup
from selenium import webdriver

# URL = "https://realpython.github.io/fake-jobs/"
URL = "https://www.chaffey.edu/calendar/index.php"

# browser = webdriver.

# response = requests.get(URL)


# page = requests.get(URL)

soup = BeautifulSoup(page.content, "html.parser")

# print(soup)
# print("Hello")

results = soup.find_all('class', 'wrapper')

# print(results)

# python_jobs = results.find_all(
#   "h2", string=lambda text: "python" in text.lower()
# )

# python_job_elements = [
#     h2_element.parent.parent.parent for h2_element in python_jobs
# ]

# # print(python_jobs)

# for job_element in python_job_elements:
#     title_element = job_element.find("h2", class_="title")
#     company_element = job_element.find("h3", class_="company")
#     location_element = job_element.find("p", class_="location")
#     print(title_element.text.strip())
#     print(company_element.text.strip())
#     print(location_element.text.strip())
#     print()

#     links = job_element.find_all("a")
#     for link in links:
#         link_url = link["href"]
#         print(f"Apply here: {link_url}\n")
