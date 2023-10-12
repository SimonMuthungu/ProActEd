import requests
from bs4 import BeautifulSoup

# Send an HTTP GET request to the Undergraduate Programmes page
url = "https://programmes.maseno.ac.ke"
response = requests.get(url, verify=False)

# Parse the HTML content of the page
soup = BeautifulSoup(response.text, 'html.parser')

# Find the "Undergraduate Programmes" link
programmes_link = soup.find('a', text='                           Undergraduate Programmes                        ')

# Check if the link exists
if programmes_link:
    
    # Open the link
    programmes_url = 'https://programmes.maseno.ac.ke' + programmes_link['href']
    print(f'{programmes_url}\n')
    programmes_response = requests.get(programmes_url, verify=False)
    programmes_soup = BeautifulSoup(programmes_response.text, 'html.parser')

    # Find the "sub-title" div and extract its name
    sub_title_div = programmes_soup.find('div', class_='sub-title')
    sub_title = sub_title_div.text if sub_title_div else "No sub-title found"

    # Move up two levels to find the "column-content" div
    column_content_div = sub_title_div.find_parent().find_parent().find('div', class_='column-content')

    # Find ul elements and get the href and anchor text
    ul_elements = column_content_div.find_all('ul')
    if ul_elements:
        print('got some ul elements')
    else:
        print('no ul elements gotten')
    data_list = []

    for ul in ul_elements:
        anchor = ul.find('span', 'nav-item')
        if anchor:
            anchor_text = anchor.find('a')
            if anchor_text:
                href = anchor_text['href']
                text = anchor_text.text
                data_list.append((text, href))
            else:
                data_list.append(("No anchor to follow here", "No href"))
        else:
            data_list.append(("No anchor to follow here", "No href"))

    # Check if the page produces a "page not found" error
    page_not_found = "page not found" in programmes_response.text.lower()

    # Retrieve the headers of the content on pages that have content
    content_headers = []
    if not page_not_found:
        content_divs = programmes_soup.find_all('div', class_='component-title')
        content_headers = [header.text for header in content_divs]

    # Display the results
    print("Sub-title:", sub_title)
    print("Data list:", data_list)
    print("Page not found:", page_not_found)
    print("Content headers:", content_headers)
else:
    print("Undergraduate Programmes link not found.")

