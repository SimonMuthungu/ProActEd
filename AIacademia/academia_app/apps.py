from django.apps import AppConfig
from flask import Flask, render_template, request, redirect, url_for
import sqlite3

app = Flask(__name__)

# Configuration
DATABASE = 'users.db'

# Helper function to connect to the database
def connect_db():
    return sqlite3.connect(DATABASE)

 # Routes
@app.route('/')
def index():
    return 'Welcome to the sign-up page!'

@app.route('/signup', methods=['GET', 'POST'])
def signup():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        # Connect to the database
        conn = connect_db()
        cursor = conn.cursor()

        # Insert user details into the database
        cursor.execute('INSERT INTO users (username, password) VALUES (?, ?)', (username, password))

        # Commit changes and close the connection
        conn.commit()
        conn.close()

        return redirect(url_for('login'))

    return render_template('signup.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        # Connect to the database
        conn = connect_db() 
        cursor = conn.cursor()

        # Check if the user exists in the database
        cursor.execute('SELECT * FROM users WHERE username=? AND password=?', (username, password))
        user = cursor.fetchone()

        # Close the connection
        conn.close()

        if user:
            return 'Login successful!'
        else:
            return 'Login failed. Invalid username or password.'

    return render_template('login.html')

if __name__ == '__main__':
    app.run(debug=True)



class AcademiaAppConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'academia_app'
