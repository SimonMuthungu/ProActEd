import requests

# Define the API URL
api_url = 'http://127.0.0.1:8000/predict_data/'

# Perform a GET request to obtain the CSRF token from the cookie
# response = requests.get(api_url)

headers = {
        'Referer': api_url,  # Include the referer to ensure Django recognizes the request as originating from your site
        # 'X-CSRFToken': csrf_token  # Set the CSRF token in the headers
    }


data = {
        # 'csrfmiddlewaretoken': csrf_token,
        'lessons_attended': 200,
        'aggregate_points': 70,
        # Add other form fields here
    }

response = requests.post(api_url, data=data, headers=headers)
print(response)


if response.status_code == 200:
        print("Request was successful") 
        print("Response:")
        print(response.text)
else:
        print("Request failed with status code:", response.status_code)



# Check if the response status code is 200 (OK)
# if response.status_code == 200:
    # Extract the CSRF token from the cookie
    # csrf_token = response.cookies['csrftoken']
    # print("csrf: ", csrf_token)

    # Include the CSRF token in the headers
    

    # Define the POST data
    

    # Send a POST request to the API with the CSRF token in the headers
    # Check the response
    
# else:
#     print("Failed to retrieve the CSRF token from the API.")



