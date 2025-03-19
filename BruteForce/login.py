from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def login():
    username = request.form.get('username')
    password = request.form.get('password')

    if username == 'raz' and password == '1234':
        return 'Login successful'  # Replace with appropriate response or redirect
    else:
        return 'Invalid username or password'  # Replace with appropriate response or redirect

if __name__ == '__main__':
    app.run()

