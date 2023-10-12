from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.by import By
import time
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Configure options for a headless browser
options = webdriver.ChromeOptions()
# options.add_argument('--headless')  # Run in headless mode

# Path to the Brave browser executable on your system
brave_path = r"C:\\Program Files\\BraveSoftware\\Brave-Browser\\Application\\brave.exe"

# Set the binary location for the Brave browser
options.binary_location = brave_path

# Create a new instance of the Brave browser in headless mode
driver = webdriver.Chrome(options=options)
# Maximizing the window
driver.maximize_window()

# Navigate to the Maseno University homepage
driver.get("https://www.maseno.ac.ke")

time.sleep(3) 

# Use an explicit wait to wait for the element to become visible
wait = WebDriverWait(driver, 5)
hoverable_link = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "we-mega-menu-li.dropdown-menu.schools-dropdown.open")))


# Create an ActionChains object to perform hover actions
actions = ActionChains(driver)
actions.move_to_element(hoverable_link).perform()

# Collect and print the school names
school_names = driver.find_elements(By.CLASS_NAME, "we-mega-menu-li")
if school_names:
    print('sch names found, proceeding...\n')
else:
    print('no schoolnames...\n')

for school in school_names:
    school_name = school.text
    print(f"School: {school_name}")

    # Click on the school to reveal the department page
    school.click()

    # Find department elements
    department_elements = driver.find_elements(By.XPATH, "//li[contains(@class,'menu-item--expanded') and contains(text(),'Department')]")

    # Loop through departments
    for department_element in department_elements:
        department_name = department_element.text
        print(f"  Department: {department_name}")

        # Click on the department to navigate to its page
        department_element.click()

        # Find the "read more" link and click it
        read_more_link = driver.find_element(By.LINK_TEXT, "Read more")
        read_more_link.click()

        # Collect and print the relevant information on the department page
        department_info = driver.find_element(By.CSS_SELECTOR, ".page--node .field--name-field-description").text
        print(f"{department_info}")

        # Go back to the previous page with the list of departments
        driver.back()

    # Go back to the list of schools
    driver.back()

# Close the Brave browser
driver.quit()
