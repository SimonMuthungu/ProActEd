import sqlite3

# Paths to the source and target database files
source_db_path = r'dbfrom.sqlite3'
target_db_path = r'db.sqlite3'

# Connect to the source and target databases
source_conn = sqlite3.connect(source_db_path)
target_conn = sqlite3.connect(target_db_path)

source_cursor = source_conn.cursor()
target_cursor = target_conn.cursor()

try:
    # Get the schema of the table from the source database
    source_cursor.execute("SELECT sql FROM sqlite_master WHERE name='academia_app_recommender_training_data'")
    create_table_query = source_cursor.fetchone()[0]

    # Create the table in the target database
    target_cursor.execute(create_table_query)

    # Fetch all data from the source table
    source_cursor.execute('SELECT * FROM academia_app_recommender_training_data')
    rows = source_cursor.fetchall()

    # Prepare the INSERT statement based on the number of columns
    num_cols = len(rows[0]) if rows else 0
    placeholders = ', '.join(['?'] * num_cols)
    insert_query = f'INSERT INTO academia_app_recommender_training_data VALUES ({placeholders})'

    # Insert each row into the target table
    for row in rows:
        target_cursor.execute(insert_query, row)

    # Commit the changes in the target database
    target_conn.commit()
except Exception as e:
    print(f'An error occurred: {e}')
finally:
    # Close the cursor and connection objects
    source_cursor.close()
    target_cursor.close()
    source_conn.close()
    target_conn.close()

print("Data transfer complete.")
