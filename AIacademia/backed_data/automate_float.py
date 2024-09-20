import json

input_file = 'probabilitydatatable_backup.json'
output_file = 'probabilitydatatable_backup_fixed.json'

# Read the JSON file
with open(input_file, 'r', encoding='utf-8') as file:
    data = json.load(file)

# Replace non-numeric values with appropriate float values
for entry in data:
    for key, value in entry['fields'].items():
        if value == 'poor':
            entry['fields'][key] = 0.0  # or any other appropriate float value
        elif value == 'on-time':
            entry['fields'][key] = 1.0  # or any other appropriate float value

# Write the updated data back to a new JSON file
with open(output_file, 'w', encoding='utf-8') as file:
    json.dump(data, file, indent=4)

print(f"File {input_file} has been processed and saved as {output_file}")
