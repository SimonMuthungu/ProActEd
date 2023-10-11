import requests
from bs4 import BeautifulSoup
import pandas as pd

# Initialize an empty list to store the course information
courses = []

# URL of the Maseno University website
url = "https://www.maseno.ac.ke"

# Send an HTTP GET request to the website
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

# Find the dropdown menu with school titles
school_dropdown = soup.find("ul", class_="we-mega-menu-li dropdown-menu schools-dropdown")

if school_dropdown:
    # Iterate through each school
    for school in school_dropdown.find_all("li", class_="we-mega-menu-li"):
        school_name = school.get_text()
        school_url = school.a["href"]
        school_page = requests.get(url + school_url)
        school_soup = BeautifulSoup(school_page.text, "html.parser")

        # Check if the school page contains "undergraduate" text
        undergraduate_text = school_soup.find(text="undergraduate")
        if undergraduate_text:
            undergraduate_link = undergraduate_text.find_next("a")
            if undergraduate_link:
                undergraduate_url = undergraduate_link["href"]
                undergraduate_page = requests.get(url + undergraduate_url)
                undergraduate_soup = BeautifulSoup(undergraduate_page.text, "html.parser")

                # Find the list of undergraduate courses
                course_list = undergraduate_soup.find("ul")
                if course_list:
                    for course in course_list.find_all("li"):
                        course_name = course.get_text()
                        courses.append({"School": school_name, "Course": course_name})

# Create a DataFrame from the collected course information
df = pd.DataFrame(courses)

# Save the data to an Excel file
df.to_excel("recommender_system_training_dataset1.xlsx", index=False)
