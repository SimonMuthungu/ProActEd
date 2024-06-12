import json

input_file = 'recommender_training_data_byte_vectors_backup_fixed2.json'
output_file = 'recommender_training_data_byte_vectors_backup_fixed3.json'

# Define the required fields
required_fields = [
    "course_name",
    "course_objectives",
    "course_general_info_and_about",
    "general_prerequisites",
    "subject_prerequisites"
]

# Load the JSON data
with open(input_file, 'r') as file:
    data = json.load(file)

# Check for missing fields and fix them
for obj in data:
    if "fields" not in obj:
        obj["fields"] = {}
    for field in required_fields:
        if field not in obj["fields"] or obj["fields"][field] is None:
            obj["fields"][field] = ""

# Save the fixed JSON data
with open(output_file, 'w') as file:
    json.dump(data, file, indent=4)

print(f"File {input_file} has been fixed and saved as {output_file}")
