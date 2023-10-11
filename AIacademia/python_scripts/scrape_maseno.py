import requests
from bs4 import BeautifulSoup
import pandas as pd

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
