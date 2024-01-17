import requests
from bs4 import BeautifulSoup
import pandas as pd

import requests

# Set the user agent to mimic a web browser
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.1.68.67 Brave/117.1.68.67 Safari/537.36',
}

# Create a session to handle cookies
session = requests.Session()
session.headers.update(headers)

# Define the URL to scrape
url = "https://programmes.maseno.ac.ke/bachelors_programmes" 

# Send a GET request to the URL
response = session.get(url, verify=False)

# Parse the HTML content of the page
soup = BeautifulSoup(response.text, 'html.parser')
print(soup.prettify())

# Initialize lists to store data
# course_names = []
# first_headings = []
# link_texts = []

# # Find all list items (li) in the page
# list_items = soup.find_all('li')

# # Iterate through the list items
# for item in list_items:
#     # Check if the list item contains a link
#     link = item.find('a')
#     if link:
#         # Get the course name (anchor text)
#         print('got link')
#         course_name = link.text
#         course_names.append(course_name)

#         # Get the link text
#         link_text = link.get('href', 'no link to follow')
#         link_texts.append(link_text)


#         # Follow the link and scrape the first heading on the new page
#         new_url = link.get('href')
#         print(new_url)
#         new_response = requests.get(new_url, verify=False)
#         new_soup = BeautifulSoup(new_response.text, 'html.parser')
#         heading = new_soup.find('h1')
#         first_heading = heading.text if heading else 'No heading found'
#         first_headings.append(first_heading)
#     else:
#         print('no span')
#         # If no link found, set course name and link text as specified
#         span = item.find('span')
        
#         course_name = span.text if span else 'No course name found'
#         course_names.append(course_name)
#         first_headings.append('No link to follow')
#         link_texts.append('No link to follow')

# session.close()

# # Create a DataFrame to store the data
# data = {'Course Name': course_names, 'First Heading': first_headings, 'Link Text': link_texts}
# df = pd.DataFrame(data)

# # Save the data to an Excel file
# df.to_excel(r'AIacademia/python_scripts/maseno_programs.xlsx', index=False)
# Send an HTTP GET request to the URL
url = "https://www.maseno.ac.ke"
response = requests.get(url)

# Parse the HTML content of the page
soup = BeautifulSoup(response.text, 'html.parser')

# Find the school titles using a CSS selector
school_titles = soup.select(".we-mega-menu-li.dropdown-menu.schools-dropdown .we-mega-menu-li")

# Initialize lists to store the data
titles_list = []
courses_list = []

# Iterate through the school titles and collect the text
for title in school_titles:
    titles_list.append(title.get_text()) 
    # Check if there is a link under the title
    link = title.find('a')
    if link:
        course_page_url = link['href']
        # Send a GET request to the course page
        course_page_response = requests.get(course_page_url) 
        print(course_page_response.response)
        course_page_soup = BeautifulSoup(course_page_response.text, 'html.parser')
        # Find the course names using a CSS selector
        course_names = course_page_soup.select(".we-mega-menu-li .we-mega-menu-li") 
        # Iterate through the course names and collect the text
        course_names_list = [course.get_text() for course in course_names] 
        courses_list.extend(course_names_list)

# Create a DataFrame and save it to an Excel file
df = pd.DataFrame({'School Titles': titles_list, 'Courses': courses_list})
df.to_excel('recommender_system_training_dataset1.xlsx', index=False)
