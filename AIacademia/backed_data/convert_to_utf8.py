import codecs

input_file = 'recommender_training_data_backup.json'
output_file = 'recommender_training_data_backup_utf8.json'

with codecs.open(input_file, 'r', encoding='latin1') as file:
    content = file.read()

with codecs.open(output_file, 'w', encoding='utf-8') as file:
    file.write(content)

print(f"File {input_file} has been converted to UTF-8 and saved as {output_file}")
